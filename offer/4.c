/*************************************************************************
	> File Name: 4.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月01日 星期三 22时50分11秒
 ************************************************************************/
//输入一个二叉树的前序和中序
//输出该二叉树
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct BinaryNode
{
    int element;
    struct BinaryNode *Left;
    struct BinaryNode *Right;
}node;

node *CreatBinary(int pre[],int ord[],int pre_start,int pre_end,int ord_start,int ord_end);
int main()
{
    int pre[] = {1,2,4,8,9,5,3,6,7};
    int ord[] = {8,4,9,2,5,1,6,3,7};
    node *root = CreatBinary(pre,ord,0,8,0,8);
}


//基本思路是前序的第一个肯定是根节点
//在中序中找到该节点然后该节点的左边就是左子树，右边就是右子树
//依据中序中的找到的就可以找到前序中的左右子树的节点
node *CreatBinary(int pre[],int ord[],int pre_start,int pre_end,int ord_start,int ord_end)
{
    node *root = malloc(sizeof(node));
    assert(root != NULL);
    root->element = pre[pre_start];
    root->Left = NULL;
    root->Right = NULL;
    if(pre_start == pre_end)
    {
        return root;
    }
    else if(pre_start < pre_end && ord_start < ord_end)    {
        int len = 0;
        while(pre[pre_start] != ord[ord_start + len])
        {
            len++;
        }
        root->Left = CreatBinary(pre,ord,pre_start+1,pre_start+len,ord_start,ord_start+len-1);
        root->Right = CreatBinary(pre,ord,pre_start+len+1,pre_end,ord_start+len+1,ord_end);
        return root;
    }
}
