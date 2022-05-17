#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/ctype.h>
#include <linux/moduleparam.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Tuyenkkkkkk");
MODULE_DESCRIPTION("bai 2.1_lab3");
MODULE_VERSION("1.0");

char *xauro;
module_param(xauro, charp, 0);

int k1;
module_param(k1, int, S_IRUSR | S_IWUSR);

char *k2;
module_param(k2, charp, 0);

int arrk3[100];
int length;
module_param_array(arrk3, int, &length, S_IRUSR | S_IWUSR);
static int __init start(void)
{
    printk(KERN_INFO "bat dau \n");
    return 0;
}
void chuyenVi(void)
{
    char buff[100];
    int i;
    strcpy(buff, xauro);
    for (i = 0; i < strlen(buff); i++)
    {
        if (isalpha(buff[i]))
        {
            buff[i] += k1;
            while (!isalpha(buff[i]))
            {
                buff[i] -= 26;
            }
        }
    }
    printk(KERN_INFO "k1= %s\n", buff);
}

void hoanVi(void){
    char buff[100];
    int i;
    memset(buff,0,sizeof(buff));
    if (length==strlen(xauro))
    {
        for ( i = 0; i < strlen(xauro); i++)
        {
            buff[i]=xauro[arrk3[i]];
        }
    }
    printk(KERN_INFO "arrk3= %s\n",buff);
}

void thayThe(void){
    char buff[100];
    int i;
    strcpy(buff,xauro);
    for ( i = 0; i < strlen(buff); i++)
    {
        if (isalpha(buff[i]))
        {
            buff[i]=k2[buff[i]-97];
        }
    }
    printk(KERN_INFO "k2=%s\n",buff);
    
}
void in(void)
{
    printk(KERN_INFO "xau ro: %s\n",xauro);
    chuyenVi();
    thayThe();
    hoanVi();
}
static void __exit end(void)
{
    in();
    printk(KERN_INFO "ket thuc\n");
}

module_init(start);
module_exit(end);
