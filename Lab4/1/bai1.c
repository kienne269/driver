#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tuyenkkkkkk");
MODULE_DESCRIPTION("Device number dong, lab4 bai1");
MODULE_VERSION("1.0");

dev_t dev_num = 0;
char name[]="lab4.1 HoangTrongTuyen";
static int __init char_driver_init(void)
{
    int ret = 0;
    ret = alloc_chrdev_region(&dev_num, 0, 1, name);
    if (ret < 0)
    {
        printk(KERN_INFO "Failed to register device number dynamically\n");
        return ret;
    }
    printk(KERN_INFO "Allocated device number (%d,%d)\t", MAJOR(dev_num), MINOR(dev_num));
    return 0;
}

static void __exit char_driver_exit(void){
    unregister_chrdev_region(dev_num,1);
    printk(KERN_INFO "Remove and Exit successfully.\n");
}
module_init(char_driver_init);
module_exit(char_driver_exit);
