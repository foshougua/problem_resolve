/*************************************************************************
	> File Name: 20.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月11日 星期六 21时03分18秒
 ************************************************************************/
//定义一个栈结构，实现一个能够得到最小元素的min函数
//利用链表实现栈

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct StackNode
{
    int element;
    struct StackNode *next;
}Node;

typedef struct Stack
{
    int size;
    Node *normal_stack;
    Node *min_stack;
}stack;

stack *InitStack()
{
    stack *s = malloc(sizeof(struct Stack));
    assert(s != NULL);
    s->size = 0;
    s->normal_stack = NULL;
    s->min_stack = NULL;
}

int Push(stack *s,int element)
{
    if(s->normal_stack == NULL && s->min_stack == NULL)
    {
        s->normal_stack = malloc(sizeof(Node));
        assert(s->normal_stack != NULL);
        s->min_stack = malloc(sizeof(Node));
        assert(s->min_stack != NULL);
        s->normal_stack->element = element;
        s->normal_stack->next = NULL;
        s->min_stack->element = element;
        s->min_stack->next = NULL;
        s->size++;
        return 1;
    }
    else
    {
        int min = s->min_stack->element;
        Node *new_node = malloc(sizeof(Node));
        assert(new_node != NULL);
        new_node->next = s->normal_stack->next;
        s->normal_stack->next = new_node;
        Node *new_node2 = malloc(sizeof(Node));
        assert(new_node2 != NULL);
        if(min < element)
        {
            new_node2->element = min;
        }
        else
        {    
            new_node2->element = element;
        }
        new_node2->next = s->min_stack->next;
        s->min_stack->next = new_node2;
        return 1;
    }
    return -1;
}

int Pop(stack *s)
{
    if(s == NULL || s->size == 0)
    {
        printf("the stacke is empty!!!\n");
        return -1;
    }
    else
    {
        int element;
        Node *temp1 = s->normal_stack;
        element = temp1->element;
        s->normal_stack = temp1->next;
        free(temp1);
        temp1 = NULL;
        Node *temp2 = s->min_stack;
        s->min_stack = temp2->next;
        free(temp2);
        temp2 = NULL;

        return element;
    }
}


int Min(stack *s)
{
    if(s == NULL || s->size == 0)
    {
        printf("the stack is empty!!!\n");
        return -1;
    }
    else
    {
        return s->min_stack->element;
    }
}


int main()
{
    stack *s = InitStack();
    Push(s,5);
    printf("%d\n",Min(s));
}
