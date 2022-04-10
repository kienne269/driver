#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

void chuoiso(void);

static int p01_init(void)
{
    printk(KERN_ALERT "Khoi tao ok\n");

    chuoiso();
    return 0;
}

void chuoiso(void)
{
    int a[6] = {0, 9, 8, 1, 5, 3};
    printk("Chuoi so so a[]: ");
    printk("%d", a[0]);
    printk("%d", a[1]);
    printk("%d", a[2]);
    printk("%d", a[3]);
    printk("%d", a[4]);
    printk("%d", a[5]);
    printk("Tong cac phan tu cua chuoi so a[] la: %d", a[0] + a[1] + a[2] + a[3] + a[4] + a[5]);
}

static void p01_exit(void)
{
    printk(KERN_ALERT "Ket thuc ok\n");
}

module_init(p01_init);
module_exit(p01_exit);

MODULE_LICENSE("GPL");