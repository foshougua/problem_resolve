/*************************************************************************
	> File Name: 9.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月05日 星期日 10时32分41秒
 ************************************************************************/
//爬楼梯问题
//n阶楼梯，一次可以爬1，2，3…………，n阶
//问，一共有多少种爬法
#include<stdio.h>

long JumpFloor(int n);

int main()
{
    int n = 10;
    printf("%ld\n",JumpFloor(n));
}

long JumpFloor(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    int i;
    long result = 0;
    for( i = 1; i <= n; i++)
    {
        result += JumpFloor(n - i);
    }
    return result;
}
