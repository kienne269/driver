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
    int i;
    int min = 0;
    int max = 0;
    int a[6] = {0, 9, 8, 1, 5, 3};
    for (i = 0; i < 6; i++)
    {
        if (min > a[i])
        {
            min = a[i];
        }
        if (max < a[i])
        {
            max = a[i];
        }
    }
    printk("Chuoi so so a[]: ");
    printk("%d", a[0]);
    printk("%d", a[1]);
    printk("%d", a[2]);
    printk("%d", a[3]);
    printk("%d", a[4]);
    printk("%d", a[5]);
    printk("Phan tu nho nhat trong chuoi so la %d", min);
    printk("Phan tu lon nhat trong chuoi so la %d", max);
}

static void p01_exit(void)
{
    printk(KERN_ALERT "Ket thuc ok\n");
}

module_init(p01_init);
module_exit(p01_exit);

MODULE_LICENSE("GPL");