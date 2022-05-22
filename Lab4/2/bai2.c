#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tuyenkkkkkk");
MODULE_DESCRIPTION("Device number dong, lab4 bai1");
MODULE_VERSION("1.0");

struct _vchar_drv{
    dev_t dev_num;
}vchar_drv;
char name[]="lab4.2 HoangTrongTuyen";
static int __init vchar_driver_init(void){
    int ret=0;
    vchar_drv.dev_num = MKDEV(235,0);
    ret=register_chrdev_region(vchar_drv.dev_num,1,name);
    if (ret<0)
    {
        printk(KERN_INFO "Failed to register device number statically\n");
        return ret;
    }
    printk(KERN_INFO "Initialize vchar driver successfully");
    
    return 0;
    
}
static void __exit vchar_driver_exit(void){
    unregister_chrdev_region(vchar_drv.dev_num,1);
    printk(KERN_INFO "Remove and Exit successfully\n");
}
module_init(vchar_driver_init);
module_exit(vchar_driver_exit);

