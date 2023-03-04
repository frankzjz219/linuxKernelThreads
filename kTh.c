#include "task.h"


typedef struct 
{
	dev_t devid;			/* 设备号 	 */
	struct cdev cdev;		/* cdev 	*/
	struct class *class;		/* 类 		*/
	struct device *device;	/* 设备 	 */
	int major;				/* 主设备号	  */
	int minor;				/* 次设备号   */
} kernelThreads;

struct file_operations kThOptions = 
{
    .owner = THIS_MODULE,
};

static kernelThreads kstruct = {0};

static int hello_init(void)
{


    // 注册设备
    if(kstruct.major) // 已经具有设备号
    {
        kstruct.devid = MKDEV(kstruct.major, 0);
        register_chrdev_region(kstruct.devid, 1, "KernelMultiThread");
    }
    // 没有设备号
    else
    {
        alloc_chrdev_region(&kstruct.devid, 0, 1, "KernelMultiThread");
        kstruct.major = MAJOR(kstruct.devid);
        kstruct.minor = MINOR(kstruct.devid);
    }

        // 初始化cdev
    kstruct.cdev.owner = THIS_MODULE;
    cdev_init(&kstruct.cdev, &kThOptions);
    // 添加cdev
    cdev_add(&kstruct.cdev, kstruct.devid, "KernelMultiThread");
    // 创建类
    kstruct.class = class_create(THIS_MODULE, "KernelMultiThread");
    // 创建设备
    kstruct.device = device_create(kstruct.class, NULL, kstruct.devid, NULL, "KernelMultiThread");

	printk(KERN_ALERT " Hello World enter\n");
    printk(KERN_ALERT "Start Calculation\n");

    // tmp1 = get_jiffies_64();


    printk(KERN_ALERT "Kernel time is %d \n", ktime_get_ns()/1000000);
    task();
	return 0;
}
static void hello_exit(void)
{
    // 注销设备
    cdev_del(&kstruct.cdev);
    unregister_chrdev_region(kstruct.devid, 1);

    device_destroy(kstruct.class, kstruct.devid);

    class_destroy(kstruct.class);
    /*********************************************/
    printk(KERN_ALERT "Kernel time is %u \n", (unsigned int)(jiffies64_to_msecs(jiffies)));
    printk(KERN_ALERT "Calculator unmounted!\r\n");
}

MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("Frank Zhang");

module_init(hello_init);
module_exit(hello_exit);


