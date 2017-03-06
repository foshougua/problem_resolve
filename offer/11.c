/*************************************************************************
	> File Name: 11.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月06日 星期一 20时11分51秒
 ************************************************************************/
//给一个底数n，和阶数e，求其结果
#include<stdio.h>

double Fac(int n,int e);

int main()
{
    int n = 10;
    int e = -5;
    printf("%d^%d = %lf\n",n,e,Fac(n,e));
}


//解法一，递归
//
/*double Fac(int n,int e)
{
    if(e == 0)
        return 1;
    if(e == 1)
        return n;
    if(e == -1)
        return 1/n;
    if(e > 0)
        return Fac(n,e/2) * Fac(n,e/2) * Fac(n,e%2);
    else
        return 1/(Fac(n,(-e)/2) * Fac(n,(-e)/2) * Fac(n,(-e)%2));
}*/


//解法2
double Fac(int n,int e)
{
    int exponent;
    double res = 1;
    double curr = n;
    if(e > 0)
    {
        exponent = e;
    }
    else if(e < 0)
    {
        exponent = -e;
    }
    else
    {
        return 1;
    }

    while(exponent > 0)
    {
        if((exponent & 1) == 1)
            res *= curr;

        exponent >>= 1;
        curr *= curr;
    }

    return e > 0 ? res:1/res;
}
