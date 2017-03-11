/*************************************************************************
	> File Name: 17.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月11日 星期六 09时10分46秒
 ************************************************************************/
//输入一个二叉树A和二叉树B
//判断B是不是A的子结构

#include<stdio.h>

#define true 1
#define false 0

typedef struct BinanyNode
{
    int element;
    struct BinanyNode *left;
    struct BinanyNode *right;
} *node;

node HasSubtree(node A,node B);
node IsSubtree(node A,node B);

//这个函数主要是为下一个函数做服务
//不能判断B是A的一棵子树
node IsSubtree(node A,node B)
{
    //如果B是NULL，书名B必然是A的子树
    if(B == NULL)
        return true;
    //如果A是NULL，因为前面已经判断了B不是NULL，所以返回false
    if(A == NULL)
        return false;
//更高效的写法
//利用短路原理

/*if(B == NULL || A == NULL)
    return NULL;*/

    if(A->element == B->element)
    {
        return IsSubtree(A->left,B->left) && IsSubtree(A->right,B->right);
    }
    else
    {
        return false;
    }
}

node HasSubtree(node A,node B)
{
    if(B == NULL)
        return false;
    if(A == NULL)
        return false;
//同样的高效方法
/* if(B == NULL || A == NULL)
 * return false;
 */
    return IsSubtree(A,B) || HasSubtree(A->left,B) || HasSubtree(A->right,B);
}
