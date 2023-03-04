#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/types.h>
#include <linux/delay.h>
#include <linux/ide.h>
#include <linux/errno.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/proc_fs.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include <net/sock.h>
#include <net/netlink.h>
#include <linux/time.h>
#include <linux/time64.h>
#include <linux/jiffies.h>

// #include <linux/param.h>

#include <asm/msr.h>

#include <linux/timex.h>

#include <linux/ktime.h>


/***************************************内核线程*************************************************/
#include <linux/sched.h>   //wake_up_process()
#include <linux/kthread.h> //kthread_create()、kthread_run()

#define SIZEOFMAT 100
#define SIZEOFVEC 1000000000

int calc(void *input);
void task(void);