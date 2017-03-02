/*************************************************************************
	> File Name: 5.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月02日 星期四 22时37分18秒
 ************************************************************************/
//利用两个栈实现一个队列
//假设有两个栈s1和s2
//每次压栈进s1，如果s2为空，则将s1全部弹出压入s2
//出栈时如果s2非空，则从s2弹出
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

struct Node;
struct Stake;

typedef struct Stake
{
    struct Node *header;
    int length;
}stake;

typedef struct Node
{
    int element;
    struct Node *next;
}node;

stake *CreateStake();
int StakePush(int e,stake *s);
int StakePop(stake *s);

int QueuePush(int e,stake *s1,stake *s2);
int QueuePop(stake *s1,stake *s2);

int main()
{
    
}

stake *CreateStake()
{
    stake *s = malloc(sizeof(stake));
    assert(s != NULL);
    s->header = NULL;
    s->length = 0;
    return s;
}

int StakePush(int e,stake *s)
{
    if(s == NULL)
        return -1;
    node *new = malloc(sizeof(node));
    assert(new != NULL);
    new->element = e;
    new->next = s->header->next;
    s->header->next = new;
    s->length++;
    return 0;
}

int StakePop(stake *s)
{
    if(s == NULL || s->header->next == NULL)
    {
        printf("the stake is empty!\n");
        return -1;
    }
    else
    {
        int element = s->header->next->element;
        node *temp = s->header->next;
        s->header->next = temp->next;
        free(temp);
        s->length--;
        return element;
    }
}

int QueuePush(int e,stake *s1,stake *s2)
{
    if(s1 == NULL || s2 == NULL)
    {
        printf("input error!\n");
        return -1;
    }
    else
    {
        StakePush(e,s1);
        if(s2->header->next == NULL)
        {
            while(s1->length != 0)
            {
                StakePush(StakePop(s1),s2);
            }
        }
    }
}

int QueuePop(stake *s1,stake *s2)
{
    if(s1 == NULL || s2 == NULL)
    {
        printf("invalid input\n");
        return -1;
    }
    else
    {
        if(s2->header->next != NULL)
        {
            return StakePop(s2);
        }
        else if(s1->header->next == NULL)
        {
            return -1;
        }
        else
        {
            while(s1->length != 0)
            {
                StakePush(StakePop(s1),s2);
            }
            return StakePop(s2);
        }
    }
}


