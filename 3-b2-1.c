/*2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int i;
    printf( "请输入一个[1..30000]间的整数:\n");
    scanf("%d",&i);
    int a = i / 10000;
    int b = i / 1000 % 10;
    int c = i / 100 % 10;
    int d = i / 10 % 10;
    int e = i % 10;

    printf( "万位 : %d\n",a) ;
    printf( "千位 : %d\n",b) ;
    printf( "百位 : %d\n",c) ;
    printf( "十位 : %d\n",d) ;
    printf( "个位 : %d\n",e) ;

    return 0;
} 