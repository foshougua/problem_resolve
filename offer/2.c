/*************************************************************************
	> File Name: 2.c
	> Author: 
	> Mail: 
	> Created Time: 2017年02月27日 星期一 00时25分32秒
 ************************************************************************/
//用%20代替字符串中的空格
//比如输入“hello world”，输出“hello%20world”
//假设原有字符串可以容纳转换后的字符
#include<stdio.h>

char *Revise(char *str);

int main()
{
    char str[20] = "hello world";
    putchar(*str);
    printf("%s\n",Revise(str));
}

char *Revise(char *str)
{
    int beginLen = 0;
    while(*str++ != '\0')
        beginLen++;
    str -= beginLen;
    int endLen = 1;
    while(*str != '\0')
    {
        if(*str++ == ' ')
            endLen += 3;
        else
            endLen++;
    }
    str -= beginLen - 1;
    while(beginLen >= 0)
    {
        if(*(str + beginLen) != ' ')
        {
            *(str + endLen--) = *(str + beginLen--);
        }
        else
        {
            *(str + endLen--) = '0';
            *(str + endLen--) = '2';
            *(str + endLen--) = '%';
            beginLen--;
        }
            
    }

    return str;
}
