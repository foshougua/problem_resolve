/*************************************************************************
	> File Name: 22.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月14日 星期二 19时08分30秒
 ************************************************************************/
//层序打印一个二叉树
#include<stdio.h>

typedef struct BinaryNode{
    int Element;
    struct BinaryNode *Left;
    struct BinaryNode *Right;
}Node;

//这里假设我们有一个Queue的操作
//Push、Pop、Length、Init
void Floor_print(Node *Header)
{
    if(Header == NULL)
    {
        printf("The binary Tree is NULL!!!\n");
        return;
    }
    else
    {
        Queue *Q = Init();
        Push(Q,Header);
        while(Length(Q) != 0)
        {
            Node *node = Pop(Q);
            printf("%d\n",node->Element);
            if(node->Left != NULL)
                Push(Q,node->Left);
            if(node->Right != NULL)
                Push(Q,node->Right);
        }
    }
}

