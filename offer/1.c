/*************************************************************************
	> File Name: 1.c
	> Author: 
	> Mail: 
	> Created Time: 2017年02月25日 星期六 22时04分28秒
 ************************************************************************/
//一个二维数组中，每一行，一列都从小到大排列
//输入一个二维数组和一个整数，判断数组中
//是否有该整数

#include<stdio.h>
#define true 1
#define false 0

int fun(int (*arr)[5],int row,int key);

int main()
{

}

//由题可知，数组从左到右逐渐递增
//从下到上逐次递减
//所以可以从左下角开始
//如果该数大于key，上移，小于key右移
int fun(int (*arr)[5],int row,int key)
{
    int c;
    int r;
    for(c = 0,r = row; c < 5 && r > 0;)
    {
        if(arr[r][c] == key)
            return true;
        else if(arr[r][c] < key)
            r++;
        else
            c++;
    }
    return false;
}
