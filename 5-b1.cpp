/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
using namespace std;

int main()
{
	int i = 0, a;
	int num[21]={0}, temp;
	cout << "��������������������������20������0������������"<< endl;
	for (i; i < 20; i++)
	{
		cin >> temp;
		if (temp > 0)
			num[i] = temp;
		else
			break;
	}
	if (i == 0)
		cout << "����Ч����" << endl;
	if (i > 0)
	{
		cout << "ԭ����Ϊ��" << endl;
		for (int j = 0; j < i; j++)
			cout << num[j] << ' ';
	}
	cout << endl;
	cin.ignore(65536, '\n');
	cout << "������Ҫ�����������" << endl;
	cin >> a;
	int i2 = 0;
	for (i2; i2 < i; i2++)
	{
		if (num[i2] > a)
			break;
	}
	for (int i3 =i; i3 >i2; i3--) {
		num[i3] = num[i3 - 1];
	}
	num[i2] = a;
	cout << "����������Ϊ��" << endl;
	for (int j = 0; j < i+1; j++)
		cout << num[j] << ' ';
	cout << endl;
	return 0;
}
