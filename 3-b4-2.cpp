/*2354218 肖佳彤 计科 */
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	const double pi = 3.14159;
	int a,b,c;
	cout << "请输入三角形的两边及其夹角(角度)" << endl;
	cin >> a>>b>>c;
	float s = a * b * sin(c*pi/180) / 2;
	cout << "三角形面积为 : " << setprecision(3) << setiosflags(ios::fixed) << s << endl;
	


	return 0;
}
