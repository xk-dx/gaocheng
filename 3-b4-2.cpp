/*2354218 Ф��ͮ �ƿ� */
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	const double pi = 3.14159;
	int a,b,c;
	cout << "�����������ε����߼���н�(�Ƕ�)" << endl;
	cin >> a>>b>>c;
	float s = a * b * sin(c*pi/180) / 2;
	cout << "���������Ϊ : " << setprecision(3) << setiosflags(ios::fixed) << s << endl;
	


	return 0;
}
