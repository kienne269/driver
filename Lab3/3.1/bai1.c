#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tuyenkkkkkk");
MODULE_DESCRIPTION("Lab3_Bai1");
MODULE_VERSION("1.0");

int vectorA[100];
int vectorB[100];
int matranA[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}, {4, 5, 6, 7}};
int matranB[4][4] = {{-1, 4, 2, 5}, {-3, 6, 9, 0}, {-2, -1, 3, 4}, {4, 5, 6, 7}};
module_param_array(vectorA, int, NULL, S_IRUSR | S_IWUSR);
module_param_array(vectorB, int, NULL, S_IRUSR | S_IWUSR);
static int __init start(void)
{
    printk(KERN_INFO "bat dau \n");
    return 0;
}
void tichVoHuong(void)
{
    int lengthA;
    int lengthB;
    int i;
    int j;
    int tg;
    int sum = 0;

    lengthA = sizeof vectorA / sizeof(int);
    lengthB = sizeof vectorB / sizeof(int);
    for (i = 0; i < lengthA; i++)
    {
        for (j = 0; j < lengthB; j++)
        {
            if (i == j)
            {
                tg = vectorA[i] * vectorB[j];
                sum += tg;
            }
        }
    }
    printk(KERN_INFO "Tich vo huong 2 vector la: %d", sum);
}
void tongMatran(void)
{
    int i;
    int j;
     int k;
    int m;
    int tongMatran[4][4];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tongMatran[i][j] = matranA[i][j] + matranB[i][j];
        }
    }
    printk(KERN_INFO "Tong 2 ma tran la:");
   
    for (k = 0; k < 4; k++)
    {
        for (m = 0; m < 4; m++)
        {
            printk(KERN_ALERT "tongMatran[%d][%d]: %d", k, m, tongMatran[k][m]);
        }
    }
}
void hieuMatran(void)
{
    int i;
    int j;
    int k;
    int m;
    int hieuMatran[4][4];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            hieuMatran[i][j] = matranA[i][j] - matranB[i][j];
        }
    }
    printk(KERN_INFO "Hieu 2 ma tran la:");
    
    for (k = 0; k < 4; k++)
    {
        for (m = 0; m < 4; m++)
        {
            printk(KERN_ALERT "hieuMatran[%d][%d]: %d ", k, m, hieuMatran[k][m]);
        }
    }
}
void tichMatran(void)
{
    int i;
    int j;
    int k;
    int n;
    int m;
    int tichMatran[4][4];
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
        {
            tichMatran[i][j] = 0;
            for (k = 0; k < 4; k++)
            {
                tichMatran[i][j] += matranA[i][k] * matranB[k][j];
            }
        }
    }
    printk(KERN_INFO "Tich 2 ma tran la:");
    
    for (n = 0; n < 4; n++)
    {
        for (m = 0; m < 4; m++)
        {
            printk(KERN_INFO "tichMatran[%d][%d]: %d ", n, m, tichMatran[n][m]);
        }
    }
}
int giaiThua(int n){
    int i;
    int giaiThua=1;
    for(i=1;i<=n;i++){
        giaiThua*=i;
    }
    return giaiThua;
}
void chinhHop(void){
    int n=10;
    int k=5;
    int chinhHop=giaiThua(n)/(giaiThua(n-k));
    printk(KERN_INFO "Chinh hop chap k cua N la %d",chinhHop);
}
static void __exit end(void)
{
    tichVoHuong();
    tongMatran();
    hieuMatran();
    tichMatran();
    chinhHop();
    printk(KERN_INFO "ket thuc\n");
}

module_init(start);
module_exit(end);