/*2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    int i;
    printf( "������һ��[1..30000]�������:\n");
    scanf("%d",&i);
    int a = i / 10000;
    int b = i / 1000 % 10;
    int c = i / 100 % 10;
    int d = i / 10 % 10;
    int e = i % 10;

    printf( "��λ : %d\n",a) ;
    printf( "ǧλ : %d\n",b) ;
    printf( "��λ : %d\n",c) ;
    printf( "ʮλ : %d\n",d) ;
    printf( "��λ : %d\n",e) ;

    return 0;
} 