/*************************************************************************
	> File Name: 19.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月11日 星期六 17时30分44秒
 ************************************************************************/
//顺时针输出一个矩阵
//比如输入1，2，3，4
//输出1，2，4，3
#include<stdio.h>

void PrintMarix(int (*a)[4],int col);
int main()
{
    int a[][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    PrintMarix(a,4);
}

void PrintMarix(int (*a)[4],int col)
{
    int i;
    int right_end = 4;
    int left_end = 0;
    int up_height = 0;
    int low_height = col;
    int number = 0;
    while(left_end < right_end - 1 && up_height < low_height - 1)
    {
        for(i = left_end;i < right_end; i++)
        {
            number++;
            printf("%d ",a[up_height][i]);
        }
        up_height++;
        for(i = up_height; i < low_height; i++)
        {
            number++;
            printf("%d ",a[i][right_end - 1]);
        }
        right_end--;
        for(i = right_end - 1; i >= left_end; i--)
        {
            number++;
            printf("%d ",a[low_height -1][i]);
        }
        low_height--;
        for(i = low_height - 1; i >= up_height; i--)
        {
            number++;
            printf("%d ",a[i][left_end]);
        }
        left_end++;
    }
    if(number >= 4 * col)
    {
        putchar('\n');
        return;
    }
    if(left_end == right_end)
    {
        int j = 0;
        for(j = up_height; j < low_height; j++)
        {
            printf("%d ",a[left_end][j]);
        }
        putchar('\n');
        return;
    }
    if(up_height == low_height)
    {
        int k = 0;
        for(k = left_end; k < right_end; k++)
        {
            printf("%d ",a[low_height][k]);
        }
        putchar('\n');
        return;
    }
}
