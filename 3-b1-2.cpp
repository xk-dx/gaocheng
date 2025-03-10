/*2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    const double pi = 3.14159;
    double a, b, c, d, e, f, g;
    cout<<"请输入半径和高度"<<endl;
    cin>>a>>b;
    c = 2 * pi * a;//圆周长
    d = pi * a * a;//圆面积
    e = 4 * pi * a * a;//圆球表面积
    f = 4.0 / 3 * pi * a * a * a;//圆球体积
    g = d * b;//圆柱体积
    cout << setprecision(2) <<setiosflags(ios::fixed);
    cout << "圆周长     : " << c<<endl;
    cout << "圆面积     : " << d<<endl;
    cout << "圆球表面积 : " << e<< endl;
    cout << "圆球体积   : " << f<< endl;
    cout << "圆柱体积   : " << g<< endl;

    return 0;
}