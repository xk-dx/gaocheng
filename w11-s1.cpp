/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
using namespace std;

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/

bool is_z(int num,int base) 
{
	if (num % base == 0)
		return 1;
	else
		return 0;
}
int main()
{
	int n;
	cout << "���������ݵĸ���[1..10000]" << endl;
	cin >> n;
	cout << "������" << n << "��������" << endl;
	int num[10000] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int base;
	int count=0;
	cout << "���������[2..9]" << endl;
	cin >> base;

	for (int i = 0; i < n; i++) {
		if (is_z(num[i], base)) {
			count++;
		}
	}
	cout << n << "������" << base << "���Ƹ�λΪ0�ĸ��� : " << count<<endl;
	return 0;
}
