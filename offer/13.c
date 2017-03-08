/*************************************************************************
	> File Name: 13.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月08日 星期三 10时04分18秒
 ************************************************************************/
//一个存有奇数和偶数的数组，现需要将奇数按序排好
//但是它们的相对位置不能改变
#include<stdio.h>

void OddEven(int a[],int size);
int main()
{
    int i;
    int a[] = {1,2,3,4,5,6,7,8,9,0};
    int size = sizeof(a)/sizeof(int);
    OddEven(a,size);
    for(i = 0; i < size; i++)
    {
        printf("%d\n",a[i]);
    }
}

//奇数放前面，偶数放后面
void OddEven(int a[],int size)
{
    int i = 0;//找偶数
    int j = 0;//找奇数

    while(1)
    {
        while(i < size && a[i]%2 == 1)
            i++;
        j = i + 1;//从i的下一位置开始寻找
        while(j < size && a[j]%2 == 0)
            j++;

        if(i > size - 1 || j > size - 1)//如果i到头或者j到头，都要跳出循环
            break;

        int k;
        int temp = a[j];

        for(k = j; k > i; k--)
        {
            a[k] = a[k - 1];
        }
        a[i] = temp;
        
    }
}

