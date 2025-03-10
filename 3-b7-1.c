/* 2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <math.h> 

int main() {
    double amount;
    printf("请输入找零值：\n");
    scanf("%lf", &amount);  

    int t_a = (int)round(amount * 100);
    int sum = 0;  

    if (amount >= 0.01 && amount < 100) {
        int count50 = t_a / 5000;
        t_a %= 5000;
        sum += count50;  // 50元
        int count20 = t_a / 2000;
        t_a %= 2000;
        sum += count20;  // 20元
        int count10 = t_a / 1000;
        t_a %= 1000;
        sum += count10;  // 10元
        int count5 = t_a / 500; 
        t_a %= 500;
        sum += count5;      // 5元
        int count1 = t_a / 100;
        t_a %= 100;
        sum += count1;      // 1元
        int count50Cents = t_a / 50;
        t_a %= 50; sum += count50Cents; // 5角
        int count10Cents = t_a / 10; 
        t_a %= 10;
        sum += count10Cents; // 1角
        int count5Cents = t_a / 5;
        t_a %= 5; sum += count5Cents;     // 5分
        int count2Cents = t_a / 2;
        t_a %= 2; sum += count2Cents;     // 2分
        int count1Cent = t_a; 
        sum += count1Cent;                     // 1分

        // 输出结果
        printf("共%d张找零，具体如下：\n", sum);
        if (count50 > 0)
            printf("50元 : %d张\n", count50);
        if (count20 > 0) 
            printf("20元 : %d张\n", count20);
        if (count10 > 0)
            printf("10元 : %d张\n", count10);
        if (count5 > 0)
            printf("5元  : %d张\n", count5);
        if (count1 > 0)
            printf("1元  : %d张\n", count1);
        if (count50Cents > 0)
            printf("5角  : %d张\n", count50Cents);
        if (count10Cents > 0)
            printf("1角  : %d张\n", count10Cents);
        if (count5Cents > 0) 
            printf("5分  : %d张\n", count5Cents);
        if (count2Cents > 0)
            printf("2分  : %d张\n", count2Cents);
        if (count1Cent > 0)
            printf("1分  : %d张\n", count1Cent);
    }
    else {
        printf("输入错误，请重新输入\n");
    }

    return 0;
}
