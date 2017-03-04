/*************************************************************************
	> File Name: 7.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月04日 星期六 22时40分56秒
 ************************************************************************/
//输出斐波那契数列第n项
#include<stdio.h>
long Fab(int n);
int main()
{
    printf("%ld\n",Fab(5));
}

long Fab(int n)
{
    int f1 = 0;
    int f2 = 1;
    while(n-- > 0)
    {
        int temp = f2;
        f2 = f1 + f2;
        f1 = temp;
    }
    return f1;
}
