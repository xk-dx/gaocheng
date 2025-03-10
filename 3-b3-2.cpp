/*2354218 肖佳彤 计科 */
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	cout << "十亿位 : " << int(a / 1000000000) % 10 << endl;
	cout << "亿位   : " << int(a / 100000000) % 10 << endl;
	cout << "千万位 : " << int(a / 10000000) % 10 << endl;
	cout << "百万位 : " << int(a / 1000000) % 10 << endl;
	cout << "十万位 : " << int(a / 100000) % 10 << endl;
	cout << "万位   : " << int(a / 10000) % 10 << endl;
	cout << "千位   : " << int(a / 1000) % 10 << endl;
	cout << "百位   : " << int(a / 100) % 10 << endl;
	a /= 100;
	a -= int(a);
	a *= 10000;
	a += 0.001;
	cout << "十位   : " << int(a / 1000) % 10 << endl;
	cout << "圆     : " << int(a / 100) % 10 << endl;
	cout << "角     : " << int(a / 10) % 10 << endl;
	cout << "分     : " << int(a) % 10 << endl;
	

	return 0;
}
