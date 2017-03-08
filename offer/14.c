/*************************************************************************
	> File Name: 14.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月08日 星期三 19时07分39秒
 ************************************************************************/
//输出一个链表的倒数第k个数据
#include<stdio.h>

typedef struct List
{
    int element;
    struct List *next;
}list;

void Print_k_node(list *,int k);
int main()
{

}


void Print_k_node(list *header,int k)
{
    if(header == NULL)
    {
        printf("the list is empty!!!\n");
        return;
    }
    int i;
    list *node1 = header;
    list *node2 = header;
    for(i = k; i > 0; i--)
    {
        node1 = node1->next;
    }

    while(node1 != NULL)
    {
        node2 = node2->next;
        node1 = node1->next;
    }

    printf("%d\n",node1->element);
}
