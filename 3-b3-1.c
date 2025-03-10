/* 2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    printf("请输入[0-100亿)之间的数字:\n");
    scanf("%lf", &a);  
    printf("十亿位 : %d\n", (int)(a / 1000000000) % 10);
    printf("亿位   : %d\n", (int)(a / 100000000) % 10);
    printf("千万位 : %d\n", (int)(a / 10000000) % 10);
    printf("百万位 : %d\n", (int)(a / 1000000) % 10);
    printf("十万位 : %d\n", (int)(a / 100000) % 10);
    printf("万位   : %d\n", (int)(a / 10000) % 10);
    printf("千位   : %d\n", (int)(a / 1000) % 10);
    printf("百位   : %d\n", (int)(a / 100) % 10);

    // 处理小数部分
    a /= 100;                  
    a -= (int)a;               
    a *= 10000;                
    a += 0.001;               

    printf("十位   : %d\n", (int)(a / 1000) % 10);
    printf("圆     : %d\n", (int)(a / 100) % 10);
    printf("角     : %d\n", (int)(a / 10) % 10);
    printf("分     : %d\n", (int)a % 10);

    return 0;
}
