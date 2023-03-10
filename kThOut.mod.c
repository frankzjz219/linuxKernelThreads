#include <linux/build-salt.h>
#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

BUILD_SALT;

MODULE_INFO(vermagic, VERMAGIC_STRING);
MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(.gnu.linkonce.this_module) = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};

#ifdef CONFIG_RETPOLINE
MODULE_INFO(retpoline, "Y");
#endif

static const struct modversion_info ____versions[]
__used __section(__versions) = {
	{ 0xdd8f8694, "module_layout" },
	{ 0x22b90774, "cdev_del" },
	{ 0x2064fa56, "cdev_init" },
	{ 0x3fd78f3b, "register_chrdev_region" },
	{ 0xb43f9365, "ktime_get" },
	{ 0x22e92418, "device_destroy" },
	{ 0x6091b333, "unregister_chrdev_region" },
	{ 0xa6521794, "kthread_create_on_node" },
	{ 0x15ba50a6, "jiffies" },
	{ 0x92ec510d, "jiffies64_to_msecs" },
	{ 0xc5850110, "printk" },
	{ 0x7749276a, "device_create" },
	{ 0xc4952f09, "cdev_add" },
	{ 0x6bb70076, "wake_up_process" },
	{ 0xbdfb6dbb, "__fentry__" },
	{ 0xb65e5a32, "class_destroy" },
	{ 0x2871e975, "__class_create" },
	{ 0xe3ec2f2b, "alloc_chrdev_region" },
};

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "76EAC93EE38081E4DEE60D6");
