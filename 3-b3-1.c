/* 2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
    double a;
    printf("������[0-100��)֮�������:\n");
    scanf("%lf", &a);  
    printf("ʮ��λ : %d\n", (int)(a / 1000000000) % 10);
    printf("��λ   : %d\n", (int)(a / 100000000) % 10);
    printf("ǧ��λ : %d\n", (int)(a / 10000000) % 10);
    printf("����λ : %d\n", (int)(a / 1000000) % 10);
    printf("ʮ��λ : %d\n", (int)(a / 100000) % 10);
    printf("��λ   : %d\n", (int)(a / 10000) % 10);
    printf("ǧλ   : %d\n", (int)(a / 1000) % 10);
    printf("��λ   : %d\n", (int)(a / 100) % 10);

    // ����С������
    a /= 100;                  
    a -= (int)a;               
    a *= 10000;                
    a += 0.001;               

    printf("ʮλ   : %d\n", (int)(a / 1000) % 10);
    printf("Բ     : %d\n", (int)(a / 100) % 10);
    printf("��     : %d\n", (int)(a / 10) % 10);
    printf("��     : %d\n", (int)a % 10);

    return 0;
}
