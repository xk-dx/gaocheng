/*2354218 Ф��ͮ �ƿ� */
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main()
{
	double a;
	cout << "������[0-100��)֮�������:" << endl;
	cin >> a;
	cout << "ʮ��λ : " << int(a / 1000000000) % 10 << endl;
	cout << "��λ   : " << int(a / 100000000) % 10 << endl;
	cout << "ǧ��λ : " << int(a / 10000000) % 10 << endl;
	cout << "����λ : " << int(a / 1000000) % 10 << endl;
	cout << "ʮ��λ : " << int(a / 100000) % 10 << endl;
	cout << "��λ   : " << int(a / 10000) % 10 << endl;
	cout << "ǧλ   : " << int(a / 1000) % 10 << endl;
	cout << "��λ   : " << int(a / 100) % 10 << endl;
	a /= 100;
	a -= int(a);
	a *= 10000;
	a += 0.001;
	cout << "ʮλ   : " << int(a / 1000) % 10 << endl;
	cout << "Բ     : " << int(a / 100) % 10 << endl;
	cout << "��     : " << int(a / 10) % 10 << endl;
	cout << "��     : " << int(a) % 10 << endl;
	

	return 0;
}
