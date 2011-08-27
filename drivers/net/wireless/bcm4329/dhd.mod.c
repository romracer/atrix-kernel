#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x2c2fa4d5, "module_layout" },
	{ 0x539efe6c, "sdio_register_driver" },
	{ 0xf6f796b8, "sdio_unregister_driver" },
	{ 0xe70c5959, "dev_get_drvdata" },
	{ 0x27bbf221, "disable_irq_nosync" },
	{ 0xfda85a7d, "request_threaded_irq" },
	{ 0xfed37883, "dev_set_drvdata" },
	{ 0xfcec0987, "enable_irq" },
	{ 0xf20dabd8, "free_irq" },
	{ 0x3ce4ca6f, "disable_irq" },
	{ 0x1b9981cc, "set_irq_wake" },
	{ 0x260aa580, "sdio_set_block_size" },
	{ 0xae36bfe1, "sdio_reset_comm" },
	{ 0xa0ccf674, "sdio_enable_func" },
	{ 0x58bdeb86, "sdio_f0_writeb" },
	{ 0xf98cfc81, "sdio_readb" },
	{ 0x97634b63, "sdio_disable_func" },
	{ 0x30e6ddd8, "sdio_writeb" },
	{ 0xa483f75b, "sdio_f0_readb" },
	{ 0xb7088114, "sdio_readl" },
	{ 0xdc7dfa40, "sdio_readw" },
	{ 0x925945d9, "sdio_writel" },
	{ 0x580fd050, "sdio_writew" },
	{ 0x313f5d1f, "sdio_memcpy_fromio" },
	{ 0x447a7dcb, "sdio_release_host" },
	{ 0x31c8538c, "sdio_readsb" },
	{ 0x7f439b73, "sdio_memcpy_toio" },
	{ 0xf98c1da4, "sdio_claim_host" },
	{ 0x16305289, "warn_slowpath_null" },
	{ 0x6d860949, "skb_push" },
	{ 0xf9a482f9, "msleep" },
	{ 0xf7802486, "__aeabi_uidivmod" },
	{ 0x4e830a3e, "strnicmp" },
	{ 0x1e6d26a8, "strstr" },
	{ 0x85df9b6c, "strsep" },
	{ 0x6e720ff2, "rtnl_unlock" },
	{ 0xc7a4fbed, "rtnl_lock" },
	{ 0x20000329, "simple_strtoul" },
	{ 0x6c1ce5ce, "strcspn" },
	{ 0xc73d621b, "wireless_send_event" },
	{ 0x6a08f2d0, "dev_open" },
	{ 0x1b80548d, "sched_setscheduler" },
	{ 0x94dc300b, "tegra_ioremap" },
	{ 0x2b0935de, "tegra_iounmap" },
	{ 0x9c15e530, "outer_cache" },
	{ 0x2196324, "__aeabi_idiv" },
	{ 0x349cba85, "strchr" },
	{ 0xc7ec6c27, "strspn" },
	{ 0x71c90087, "memcmp" },
	{ 0x9f984513, "strrchr" },
	{ 0x61651be, "strcat" },
	{ 0x701d0ebd, "snprintf" },
	{ 0x57a6504e, "vsnprintf" },
	{ 0xe707d823, "__aeabi_uidiv" },
	{ 0x105e2727, "__tracepoint_kmalloc" },
	{ 0x42102f22, "kmalloc_caches" },
	{ 0x43b0c9c3, "preempt_schedule" },
	{ 0xe2738d86, "kmem_cache_alloc" },
	{ 0x5f96af94, "skb_put" },
	{ 0x21a0dbf2, "__alloc_skb" },
	{ 0x12da5bb2, "__kmalloc" },
	{ 0x37a0cba, "kfree" },
	{ 0xc7966e04, "dma_alloc_coherent" },
	{ 0xfc7a10eb, "dma_free_coherent" },
	{ 0x56de23d6, "dma_map_single" },
	{ 0xb5cd7826, "dma_unmap_single" },
	{ 0x90f8c3bd, "skb_clone" },
	{ 0x49e182c0, "param_get_string" },
	{ 0x4101bbde, "param_set_copystring" },
	{ 0x6980fe91, "param_get_int" },
	{ 0xff964b25, "param_set_int" },
	{ 0x108e8985, "param_get_uint" },
	{ 0x3285cc48, "param_set_uint" },
	{ 0x76bc2ea6, "platform_get_resource_byname" },
	{ 0x9e7d6bd0, "__udelay" },
	{ 0x1b28c2d4, "down_timeout" },
	{ 0x3bd1b1f6, "msecs_to_jiffies" },
	{ 0x90bf9547, "platform_driver_register" },
	{ 0xa2c2b3bd, "platform_driver_unregister" },
	{ 0xad9c3eab, "dev_kfree_skb_any" },
	{ 0xd63b3281, "consume_skb" },
	{ 0x5e0cdc0e, "skb_realloc_headroom" },
	{ 0xf997dcd5, "__netif_schedule" },
	{ 0xcccca482, "_test_and_clear_bit_le" },
	{ 0xaa183d3f, "netif_rx_ni" },
	{ 0x438ad649, "netif_rx" },
	{ 0xf2b0080b, "skb_pull" },
	{ 0xeed90f97, "eth_type_trans" },
	{ 0xa9f9c63a, "wake_lock_timeout" },
	{ 0xfaef0ed, "__tasklet_schedule" },
	{ 0xda5ea696, "_test_and_set_bit_le" },
	{ 0x235443d3, "complete_and_exit" },
	{ 0x94af7d90, "down_interruptible" },
	{ 0xe5ada986, "complete" },
	{ 0xd79b5a02, "allow_signal" },
	{ 0xdc43a9c8, "daemonize" },
	{ 0x7e9ebb05, "kernel_thread" },
	{ 0x5f754e5a, "memset" },
	{ 0xe914e41e, "strcpy" },
	{ 0x3e45e9ff, "register_inetaddr_notifier" },
	{ 0xb5eeb329, "register_early_suspend" },
	{ 0x3cfedb3f, "register_pm_notifier" },
	{ 0x9545af6d, "tasklet_init" },
	{ 0xbf42d3d7, "init_timer_key" },
	{ 0xddb1fab8, "__mutex_init" },
	{ 0x5b89a27c, "__init_waitqueue_head" },
	{ 0x97255bdf, "strlen" },
	{ 0x6892088c, "unregister_pm_notifier" },
	{ 0x82072614, "tasklet_kill" },
	{ 0x6e765cdb, "wait_for_completion" },
	{ 0xb227ae83, "unregister_early_suspend" },
	{ 0x760b437a, "unregister_inetaddr_notifier" },
	{ 0x6b699811, "alloc_etherdev_mq" },
	{ 0xa2737c9d, "free_netdev" },
	{ 0x730d1338, "unregister_netdev" },
	{ 0xac76c1d, "register_netdev" },
	{ 0x547bf3cd, "wake_lock_destroy" },
	{ 0xeeea61f7, "wake_unlock" },
	{ 0x2f8ed62e, "wake_lock" },
	{ 0xc769e3d8, "wake_lock_init" },
	{ 0x7dceceac, "capable" },
	{ 0x5093fa82, "_clear_bit_le" },
	{ 0x313341a3, "_set_bit_le" },
	{ 0xe2d5255a, "strcmp" },
	{ 0x98082893, "__copy_to_user" },
	{ 0x17a142df, "__copy_from_user" },
	{ 0x328a05f1, "strncpy" },
	{ 0x84b183ae, "strncmp" },
	{ 0xffd5a395, "default_wake_function" },
	{ 0xa695ca4a, "remove_wait_queue" },
	{ 0x8bc18b61, "add_wait_queue" },
	{ 0x7d11c268, "jiffies" },
	{ 0x28806a5f, "mod_timer" },
	{ 0xe41ab616, "del_timer_sync" },
	{ 0x81c8e41f, "kernel_read" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0xfbdd8f5b, "finish_wait" },
	{ 0xda6c388d, "prepare_to_wait" },
	{ 0x24051c6f, "down" },
	{ 0x9d669763, "memcpy" },
	{ 0xc38be2b, "up" },
	{ 0xe9a23a48, "_spin_lock_bh" },
	{ 0x4fd6fa59, "_spin_unlock_bh" },
	{ 0xfa2a45e, "__memzero" },
	{ 0xd93c7eef, "__wake_up" },
	{ 0x8a27632a, "mutex_lock" },
	{ 0xe0e60a76, "mutex_unlock" },
	{ 0xa2e85741, "_spin_lock_irqsave" },
	{ 0x8e80d4fd, "_spin_unlock_irqrestore" },
	{ 0xd62c833f, "schedule_timeout" },
	{ 0xc99765bd, "filp_close" },
	{ 0xe7c5bb6, "filp_open" },
	{ 0xea147363, "printk" },
	{ 0xf6ebc03b, "net_ratelimit" },
	{ 0x3c2c5af5, "sprintf" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";

MODULE_ALIAS("sdio:c*v02D0d0000*");
MODULE_ALIAS("sdio:c*v02D0d0492*");
MODULE_ALIAS("sdio:c*v02D0d0493*");
MODULE_ALIAS("sdio:c*v02D0d4329*");
MODULE_ALIAS("sdio:c*v02D0d4319*");
