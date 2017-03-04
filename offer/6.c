/*************************************************************************
	> File Name: 6.c
	> Author: 
	> Mail: 
	> Created Time: 2017年03月03日 星期五 21时18分17秒
 ************************************************************************/

//把一个数组最开始的若干个元素搬到数组末尾，我们称之为数组的旋转
//求一个旋转数组的最小值
#include<stdio.h>
int Min(int arr[],int start,int end);
int Find_min(int arr[],int size);
int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int re_arr[] = {4,5,6,7,1,2,3};
    int size = sizeof(arr)/sizeof(int);
    printf("arr min = %d\n",Find_min(arr,size));
}

int Min(int arr[],int start,int end)
{
    int i = 0;
    int min = arr[0];
    for(i = start; i <=end; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}

//利用二分法的思想
int Find_min(int arr[],int size)
{
    int min_index = 0;
    int max_index = size - 1;
    int mid_index = min_index;

    while(arr[min_index] >= arr[max_index])
    {
        //终止条件
        if(max_index - min_index == 1)
        {
            mid_index = max_index;
            break;
        }

        mid_index = (min_index + max_index) / 2;

        //如果出现下面情况则要进行遍历
        if((arr[min_index] == arr[max_index]) && (arr[max_index] == arr[mid_index]))
        {
            return Min(arr,min_index,max_index);
        }

        if(arr[mid_index] >= arr[min_index])
        {
            min_index = mid_index;
        }
        else if(arr[mid_index] <= arr[max_index])
        {
            max_index = mid_index;
        }
    }

    return arr[mid_index];
}

