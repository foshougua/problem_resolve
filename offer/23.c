/*************************************************************************
	> File Name: 24.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月18日 星期六 09时12分41秒
 ************************************************************************/
//给你一个序列，判断他是否某个搜索二叉树的后序

#include<stdio.h>

struct BinaryNode
{
    int element;
    struct BinaryNode *Left;
    struct BinaryNode *Right;
};
typedef struct BinaryNode Node;

int Result(int a[],int begin,int end);
int Is_BST_Post(int a[],int size);

int main()
{
    int a[] = {-1,3,1};
    int size = sizeof(a)/sizeof(*a);
    printf("%d\n",Is_BST_Post(a,size));
}

//搜索二叉树的后序应该符合这样的规律
//该序列的最后一位大于该序列的前半部分
//同时小于该序列的后半部分

int Result(int a[],int begin,int end)
{
    int i;
    int j;
    if(begin >= end)
        return 1;
    else
    {
        int pivot = a[end];
        i = end - 1;
        while(pivot < a[i])
            i--;
        for(j = i;j >= begin ; j--)
            if(pivot < a[j])
                return -1;
    }
    return Result(a,begin,i) && Result(a,i+1,end-1);
}

int Is_BST_Post(int a[],int size)
{
    return Result(a,0,size - 1);
}
