/*************************************************************************
	> File Name: 16.c
	> Author:wangkang 
    > Mail:
	> Created Time: 2017年03月09日 星期四 10时29分14秒
 ************************************************************************/
//两个有序链表，合并它们
#include<stdio.h>

typedef struct List
{
    int element;
    struct List *next;
} *list;

list Merge_list(list h1,list h2)
{
    //将h2合并到h1

    //如果h1 或者 h2 有一个为空
    //直接返回另一个
    if(h1 == NULL)
        return h2;
    if(h2 == NULL)
        return h1;

    list pr1 = NULL;
    list temp1 = h1;
    list temp2 = h2;
    list next2 = temp2->next;

    while(temp1 != NULL && next2 != NULL)
    {
        if(temp2->element < temp1->element)
        {
            temp2->next = temp1;
            temp2 = next2;
            next2 = temp2->next2;
        }
        else
        {
            while(temp2->element > temp1->element)
            {
                pr1 = temp1;
                temp1 = temp1->next;
            }
            //插入temp2
            pr1->next = temp2;
            temp2->next = temp1;

            //变换pr1和temp1的位置
            pr1 = temp2;
            temp1 = pr1->next;

            //变换temp2和next2的位置
            temp2 = next2;
            next2 = temp2->next;
        }
    }

    //跳出while有两种情况，一种是temp1 == NULL
    //另一种是temp2->next 即 next2 == NULL

    if(temp1 == NULL)
    {
        pr1->next = temp2;
    }
    else if(next2 == NULL)
    {
        while(temp1 != NULL && temp2 > temp1->element)
        {
            pr1 = temp1;
            temp1 = temp1->next;
        }

        if(temp1 == NULL)
        {
            pr1->next = temp2;
        }
        else
        {
            pr1->next = temp2;
            temp2->next = temp1;
        }
    }
    return h1;
}
