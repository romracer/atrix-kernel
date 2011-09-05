# bcm4329
DHDCFLAGS = -DLINUX -DBCMDRIVER -DBCMDONGLEHOST -DDHDTHREAD                   \
        -DBCMWPA2 -DBCMWAPI_WPI -DUNRELEASEDCHIP -DDHD_GPL -DDHD_SCHED -DBDC  \
        -DTOE -DDHD_BCMEVENTS -DSHOW_EVENTS -DOOB_INTR_ONLY -DHW_OOB          \
        -DMMC_SDIO_ABORT -DBCMSDIO -DDHD_GPL -DBCMLXSDMMC -DBCMPLATFORM_BUS   \
        -DDHD_DEBUG -Dlinux -DCUSTOMER_HW -DOEM_ANDROID -DEMBEDDED_PLATFORM   \
        -DARP_OFFLOAD_SUPPORT -DPKT_FILTER_SUPPORT -DOOB_INTR_ONLY            \
        -DMMC_SDIO_ABORT -DSOFTAP -DENABLE_ROAMING -DPNO_SUPPORT              \
        -DGET_CUSTOM_MAC_ENABLE -DKEEP_ALIVE -Wall -Wstrict-prototypes -Werror\
	-Idrivers/net/wireless/bcm4329 -Idrivers/net/wireless/bcm4329/include

DHDOFILES = dhd_linux.o linux_osl.o bcmutils.o dhd_common.o dhd_custom_gpio.o \
	siutils.o sbutils.o aiutils.o hndpmu.o dhd_linux_sched.o bcmwifi.o    \
	wl_iw.o dhd_cdc.o dhd_sdio.o bcmsdh_sdmmc.o bcmsdh.o bcmsdh_linux.o   \
	bcmsdh_sdmmc_linux.o

obj-$(CONFIG_BCM4329) += dhd.o
dhd-objs += $(DHDOFILES)
EXTRA_CFLAGS = $(DHDCFLAGS)
EXTRA_LDFLAGS += --strip-debug
