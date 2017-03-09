/*************************************************************************
	> File Name: 15.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月08日 星期三 22时35分51秒
 ************************************************************************/
//输入一个链表，反转链表后，输出链表的所有元素
#include<stdio.h>
typedef struct ListNode
{
    int element;
    struct ListNode *next;
}list;

//这里假设该链表没有头指针

//解法一
list *Reverse(list *pre,list *Header)
{
    if(Header == NULL || Header->next == NULL)
        return Header;
    else
    {
        list *temp = Header->next;
        Header->next = pre;
        list *new_head = Reverse(Header,temp);
        printf("%d\n",Header->element);
    }

    return new_head;
}



//解法二
list *Reverse(list *Header)
{
    if(Header == NULL || Header->next == NULL)
        return Header;
    list *pre = NULL;
    list *temp = Header;
    list *next = temp->next;

    while(temp->next != NULL)
    {
        temp->next = pre;
        pre = temp;
        temp = next;
        next = temp->next;
    }

    temp->next = pre;

    return temp;
}

//解法三

list *Reverse(list *Header)
{
    if(Header == NULL || Header->next == NULL)
        return Header;

    list *nextnode = Header->next;
    Header->next = NULL;

    list *rehead = Reverse(nextnode);

    //相当于把链表断开之后再次链接起来
    nextnode->next = Header;

    return rehead;

}
