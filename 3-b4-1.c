/* 2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    const double pi = 3.14159;  // ����е�ֵ
    printf("�����������ε����߼���н�(�Ƕ�):\n");
    scanf("%d %d %d", &a, &b, &c);
    float s = a * b * (float)(sin(c * pi / 180))/2;
    printf("���������Ϊ : %.3f\n", s);
    return 0;
}
