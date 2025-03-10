/* 2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
int main()
{
    int a, b, c;
    const double pi = 3.14159;  // 定义π的值
    printf("请输入三角形的两边及其夹角(角度):\n");
    scanf("%d %d %d", &a, &b, &c);
    float s = a * b * (float)(sin(c * pi / 180))/2;
    printf("三角形面积为 : %.3f\n", s);
    return 0;
}
