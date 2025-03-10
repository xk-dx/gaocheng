/*2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
    const double pi = 3.14159;
    double a,b,c,d,e,f,g;
    printf("请输入半径和高度\n");
    scanf("%lf %lf",&a,&b);
    c = 2 * pi * a;//圆周长
    d = pi * a * a;//圆面积
    e = 4 * pi * a * a;//圆球表面积
    f = 4.0 / 3 * pi * a * a * a;//圆球体积
    g = d * b;//圆柱体积
    printf("圆周长     : %.2f\n", c);
    printf("圆面积     : %.2f\n", d);
    printf("圆球表面积 : %.2f\n", e);
    printf("圆球体积   : %.2f\n", f);
    printf("圆柱体积   : %.2f\n", g);
    
    return 0;
}