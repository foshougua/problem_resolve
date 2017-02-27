/*************************************************************************
	> File Name: 3.c
	> Author: 
	> Mail: 
	> Created Time: 2017年02月27日 星期一 22时08分54秒
 ************************************************************************/

#include<stdio.h>
//从尾到头打印一个链表
//基本方法就是递归打印

void reverse_print_list(ListHead *H)
{
    if(H == NULL)
    {
        return;
    }
    else
    {
        reverse_print_list(H->next);
        printf("%d\n",H->element);
    }
}
