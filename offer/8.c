/*************************************************************************
	> File Name: 8.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月05日 星期日 10时22分57秒
 ************************************************************************/
//爬楼梯问题，一次可以爬一阶或者两阶
//问：n阶楼梯共有多少种爬法
#include<stdio.h>

int Stairs(int n);

int main()
{
    int n = 40;
    printf("climb Stairs number = %d\n",Stairs(n));
}

int Stairs(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(n == 2)
        return 2;

    return Stairs(n - 1) + Stairs(n - 2);
}

