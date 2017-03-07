/*************************************************************************
	> File Name: 11.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月07日 星期二 23时05分53秒
 ************************************************************************/
//输入一个整数，输出该数的二进制中一的个数
#include<stdio.h>

int Number(int n);

int main()
{
    int n = 123;
    printf("%d\n",Number(n));
}

int Number(int n)
{
    int result = 0;
    while(n > 0)
    {
        if((n & 1) == 1)
            result += 1;
        n >>= 1;
    }
    return result;
}

