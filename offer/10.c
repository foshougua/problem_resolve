/*************************************************************************
	> File Name: 10.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月06日 星期一 20时07分24秒
 ************************************************************************/
//用1 * 2（一个整体）矩形，填满N * 2个矩形
//问共有多少种填法

#include<stdio.h>

int Fun(int n);

int main()
{
    printf("%d\n",Fun(10));
}

int Fun(int n)
{
    if(n == 0 )
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;

    return Fun(n - 1) + Fun(n - 2);
}
