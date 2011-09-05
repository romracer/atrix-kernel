/*
 * Copyright (c) 2009 NVIDIA Corporation.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * Neither the name of the NVIDIA Corporation nor the names of its contributors
 * may be used to endorse or promote products derived from this software
 * without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

/**
 * @file          nvodm_usbulpi.c
 * @brief         <b>Adaptation for USB ULPI </b>
 *
 * @Description : Implementation of the USB ULPI adaptation.
 */
#include "nvodm_usbulpi.h"
#include "nvodm_services.h"
#include "nvodm_query_discovery.h"
#include "nvodm_services.h"
#include "nvodm_keylist_reserved.h"
#include "nvrm_drf.h"
#include "nvos.h"

/* Etna actually uses the 3326 but the ref clocks are hooked up the same */
#define SMSC3317GUID NV_ODM_GUID('s','m','s','c','3','3','1','7')

#define MAX_CLOCKS 3

#define NVODM_PORT(x) ((x) - 'a')
#define ULPI_RESET_PORT NVODM_PORT('f')
#define ULPI_RESET_PIN 0

#define MODEM_POWERON_PORT NVODM_PORT('m')
#define MODEM_POWERON_PIN 5


#ifdef NV_DRIVER_DEBUG
    #define NV_DRIVER_TRACE NvOsDebugPrintf
#else
    #define NV_DRIVER_TRACE (void)
#endif

typedef struct NvOdmUsbUlpiRec
{
    NvU64    CurrentGUID;
} NvOdmUsbUlpi;

static NvOdmServicesGpioHandle s_hGpio = NULL;
static NvOdmGpioPinHandle s_hResetPin = NULL;

static NvOdmServicesGpioHandle modem_hGpio = NULL;
static NvOdmGpioPinHandle modem_hPin = NULL;

static int turn_on_modem()
{
    static int modem_turned_on = 0;

   if(modem_turned_on)
       return 0;

    modem_hGpio = NvOdmGpioOpen();
    if (!modem_hGpio)
    {
        NV_DRIVER_TRACE (("ERROR turn_on_modem: "
                          "Not able to open gpio handle\n"));
        return -1;
    }

    modem_hPin = NvOdmGpioAcquirePinHandle(modem_hGpio, MODEM_POWERON_PORT, MODEM_POWERON_PIN);

    if (!modem_hPin)
    {
        NvOdmGpioClose(modem_hGpio);
        modem_hGpio = NULL;
        NV_DRIVER_TRACE (("ERROR turn_on_modem: "
                          "Not able to Acq pinhandle\n"));
        return -1;
    }

    NvOdmGpioConfig(modem_hGpio, modem_hPin, NvOdmGpioPinMode_Output);
    NvOdmGpioSetState(modem_hGpio, modem_hPin, 0x01);

    modem_turned_on = 1;

    return 0;
}

NvOdmUsbUlpiHandle NvOdmUsbUlpiOpen(NvU32 Instance)
{
    NvOdmUsbUlpi *pDevice = NULL;
    NvU32 ClockInstances[MAX_CLOCKS];
    NvU32 ClockFrequencies[MAX_CLOCKS];
    NvU32 NumClocks;

    pDevice = NvOdmOsAlloc(sizeof(NvOdmUsbUlpi));
    if(pDevice == NULL)
        return NULL;

    if(!NvOdmExternalClockConfig(SMSC3317GUID, NV_FALSE, ClockInstances, ClockFrequencies, &NumClocks))
    {
        NV_DRIVER_TRACE (("ERROR NvOdmUsbUlpiOpen: "
                                "NvOdmExternalClockConfig fail\n"));
        goto ExitUlpiOdm;
    }
    NvOdmOsSleepMS(10);

    if (!s_hGpio)
        s_hGpio = NvOdmGpioOpen();
    if (!s_hGpio)
    {
        NV_DRIVER_TRACE (("ERROR NvOdmUsbUlpiOpen: "
                          "Not able to open gpio handle\n"));
        goto ExitUlpiOdm;
    }

    if (!s_hResetPin)
        s_hResetPin = NvOdmGpioAcquirePinHandle(s_hGpio, ULPI_RESET_PORT, ULPI_RESET_PIN);

    if (!s_hResetPin)
    {
        NvOdmGpioClose(s_hGpio);
        s_hGpio = NULL;
        NV_DRIVER_TRACE (("ERROR NvOdmGpioAcquirePinHandle: "
                          "Not able to Acq pinhandle\n"));
        goto ExitUlpiOdm;
    }

    // Pull high on RESETB
    // config as out put pin
    NvOdmGpioConfig(s_hGpio,s_hResetPin, NvOdmGpioPinMode_Output);
    // Set low to write high on ULPI_RESETB pin
    NvOdmGpioSetState(s_hGpio, s_hResetPin, 0x01);
    NvOdmGpioSetState(s_hGpio, s_hResetPin, 0x0);
    NvOdmOsSleepMS(5);
    NvOdmGpioSetState(s_hGpio, s_hResetPin, 0x01);

    pDevice->CurrentGUID = SMSC3317GUID;

    if(turn_on_modem())
    {
        NvOsDebugPrintf("Error enabling modem from NvOdmUsbUlpiOpen\n");
        goto ExitUlpiOdm;
    }

    return pDevice;

ExitUlpiOdm:
    NvOdmOsFree(pDevice);
    return NULL;
}

void NvOdmUsbUlpiClose(NvOdmUsbUlpiHandle hOdmUlpi)
{
    if (hOdmUlpi) {
        NvOdmOsFree(hOdmUlpi);
    }
    if (s_hResetPin)
    {
        NvOdmGpioReleasePinHandle(s_hGpio, s_hResetPin);
        s_hResetPin = NULL;
    }
    if (s_hGpio)
    {
        NvOdmGpioClose(s_hGpio);
        s_hGpio = NULL;
    }
}
