/* 2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <math.h> 

int main() {
    double amount;
    printf("����������ֵ��\n");
    scanf("%lf", &amount);  

    int t_a = (int)round(amount * 100);
    int sum = 0;  

    if (amount >= 0.01 && amount < 100) {
        int count50 = t_a / 5000;
        t_a %= 5000;
        sum += count50;  // 50Ԫ
        int count20 = t_a / 2000;
        t_a %= 2000;
        sum += count20;  // 20Ԫ
        int count10 = t_a / 1000;
        t_a %= 1000;
        sum += count10;  // 10Ԫ
        int count5 = t_a / 500; 
        t_a %= 500;
        sum += count5;      // 5Ԫ
        int count1 = t_a / 100;
        t_a %= 100;
        sum += count1;      // 1Ԫ
        int count50Cents = t_a / 50;
        t_a %= 50; sum += count50Cents; // 5��
        int count10Cents = t_a / 10; 
        t_a %= 10;
        sum += count10Cents; // 1��
        int count5Cents = t_a / 5;
        t_a %= 5; sum += count5Cents;     // 5��
        int count2Cents = t_a / 2;
        t_a %= 2; sum += count2Cents;     // 2��
        int count1Cent = t_a; 
        sum += count1Cent;                     // 1��

        // ������
        printf("��%d�����㣬�������£�\n", sum);
        if (count50 > 0)
            printf("50Ԫ : %d��\n", count50);
        if (count20 > 0) 
            printf("20Ԫ : %d��\n", count20);
        if (count10 > 0)
            printf("10Ԫ : %d��\n", count10);
        if (count5 > 0)
            printf("5Ԫ  : %d��\n", count5);
        if (count1 > 0)
            printf("1Ԫ  : %d��\n", count1);
        if (count50Cents > 0)
            printf("5��  : %d��\n", count50Cents);
        if (count10Cents > 0)
            printf("1��  : %d��\n", count10Cents);
        if (count5Cents > 0) 
            printf("5��  : %d��\n", count5Cents);
        if (count2Cents > 0)
            printf("2��  : %d��\n", count2Cents);
        if (count1Cent > 0)
            printf("1��  : %d��\n", count1Cent);
    }
    else {
        printf("�����������������\n");
    }

    return 0;
}
