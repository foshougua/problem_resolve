/*************************************************************************
	> File Name: 18.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月11日 星期六 10时28分53秒
 ************************************************************************/
//操作一个给定的二叉树，使其变成该二叉树的镜像
#include<stdio.h>

typedef struct BinaryNode
{
    int element;
    struct BinaryNode *left;
    sturct BinaryNode *right;
} *TreeNode;


//解法一:递归实现

TreeNode Mirror(TreeNode root)
{
    i
    f(root == NULL)
        return root;
    else
    {
        TreeNode temp = root->left;
        root->left = root->right;
        root->right = temp;

        Mirror(root->left);
        Mirror(root->right);
    }
}

//解法二：非递归实现
//在这里要用到队列，使用队列先进先出的性质
//这里假设有一个已经写好的队列数据结构

TreeNode RemoveFirst(Queue Q);//其中压入的数据是TreeNode
TreeNode Push(TreeNode node,Queue Q);//队列压入数据
int Length(Queue Q);//求出队列的长度

TreeNode Mirror(TreeNode root)
{
    if(root == NULL)
        return NULL;
    TreeNode temp = NULL;
    Queue Q;
    Push(root,Q);
    while(Length(Q) != 0)
    {
        TreeNode r = RemoveFirst(Q);
        temp = r->left;
        r->left = r->right;
        r->right = temp;

        //在这里交换r的左右节点之后
        //要记得左右节点的左右节点在这时候是没有交换的
        //即相当于把左右节点之后的“整棵子树”交换了
        //接下来要做的就是交换该“子树”上面的一些“子树”
        if(r->right != NULL)
        {
            Push(r->right,Q);
        }

        if(r->left != NULL)
        {
            Push(r->left,Q);
        }
    }
    return root;
}

