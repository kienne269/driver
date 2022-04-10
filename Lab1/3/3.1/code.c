#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

static int N = 10;
module_param(N, int, S_IRUGO);

void matran(int N);

static int p01_init(void)
{
    printk(KERN_ALERT "Khoi tao ok\n");

    matran(N);
    return 0;
}

void matran(int N)
{
    int i, j;
    int tong = 0;
    // khoi tao ma tran
    int matrix[3][3];

    matrix[0][0] = 5;
    matrix[0][1] = 4;
    matrix[0][2] = 6;
    matrix[1][0] = 12;
    matrix[1][1] = 22;
    matrix[1][2] = 1;
    matrix[2][0] = 333;
    matrix[2][1] = 44;
    matrix[2][2] = 21;

    printk("Cac phan tu cua ma tran: \n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printk("%d ", matrix[i][j]);
            tong = tong + matrix[i][j];
        }
        printk("\n");
    }
    printk("Tong cac phan tu trong ma tran la %d\n", tong);
}

static void p01_exit(void)
{
    printk(KERN_ALERT "Ket thuc ok\n");
}

module_init(p01_init);
module_exit(p01_exit);

MODULE_LICENSE("GPL");