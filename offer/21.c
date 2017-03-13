/*************************************************************************
	> File Name: 21.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月13日 星期一 17时05分03秒
 ************************************************************************/
//输入两组数arr1，arr2
//判断arr2是不是arr1压栈出栈的一种可能顺序
//比如输入arr1是{1,2,3,4,5}，arr2为{4,5,3,2,1}
//那么arr2就是arr1的一种可能顺序
#include<stdio.h>

//这里假设有Push和Pop函数
//StackFirst和Length函数
typedef struct Stack stack;

stack *InitStack();
int Push(stack *s,int element);
int Pop(stack *s);
int StackFirst(stack *s);
int Length(stack *s);


int Result(int arr1[],int arr2[],int size)
{
    int i = 0;
    int j = 0;
    stack *test = InitStack();
    Push(s,arr1[0]);
    while(i < size && j < size)
    {
        while(i < size && StackFirst(test) != arr2[j])
        {
            Push(test,arr1[++i]);
        }
        while(j < size && StackFirst(test) == arr2[j])
        {
            Pop(test);
            j++;
        }
    }
    if(Length(test) == 0)
        return 1;
    else
        return -1;
}
