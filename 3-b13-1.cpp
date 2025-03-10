/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;
int main()
{
	int y, m, xq;

	while (1) {
		cout << "���������(2000-2030)���·�(1-12) : ";
		cin >> y >> m;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;
		cout << "����Ƿ�������������" << endl;
	}
	while (1) {
		cout << "������" << y << "��" << m << "��1�յ�����(0-6��ʾ������-������) : ";
		cin >> xq;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (xq >= 0 && xq <= 6)
			break;
		cout << "����Ƿ�������������" << endl;
	}
	cout << endl;

	int days;
	bool run = ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0));
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		days = 31;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		days = 30;
	else if (m == 2 && run)
		days = 29;
	else if (m == 2 && !run)
		days = 28;
	cout << y << "��" << m << "��" << "������Ϊ:" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	for (int i = 0; i < xq; ++i) {
		cout << "        ";
	}
	for (int day = 1; day <= days; day++){
		cout <<"  "<<setw(2)<<day<<"    ";
		if ((day + xq) % 7 == 0)
			cout << endl;
	} 	
	cout << endl;

	return 0;
}