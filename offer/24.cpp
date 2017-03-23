/*************************************************************************
	> File Name: 24.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月20日 星期一 20时31分30秒
 ************************************************************************/
//给你一个二叉树和整数，打印出所有从根节点到叶节点和等于该整数的路径

#include<vector>
using std::vector;

typedef struct BinaryNode
{
    int Element;
    struct BinaryNode *Left;
    struct BinaryNode *Right;
}Node;

int main()
{

}

//解法一，递归

vector< vector<int> > Result(Node *root,int number)
{
    vector< vector<int> > result;
    vector<int> temp;
    temp.push_back(root->Element);
    if(number - root->Element == 0 && !root->Left && !root->Right)
    {
        result.push_back(temp);
    }
    else
    {
        if(root->Left)
            Result(root->Left,number - root->Element);
        if(root->Right)
            Result(root->Right,number - root->Element);
    }
    temp.pop_back();
    return result;
}
