/*2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    const double pi = 3.14159;
    double a,b,c,d,e,f,g;
    printf("������뾶�͸߶�\n");
    scanf("%lf %lf",&a,&b);
    c = 2 * pi * a;//Բ�ܳ�
    d = pi * a * a;//Բ���
    e = 4 * pi * a * a;//Բ������
    f = 4.0 / 3 * pi * a * a * a;//Բ�����
    g = d * b;//Բ�����
    printf("Բ�ܳ�     : %.2f\n", c);
    printf("Բ���     : %.2f\n", d);
    printf("Բ������ : %.2f\n", e);
    printf("Բ�����   : %.2f\n", f);
    printf("Բ�����   : %.2f\n", g);
    
    return 0;
}