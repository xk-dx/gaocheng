/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include <iomanip>
using namespace std;

int zeller(int y, int m, int d)
{
	if (m == 1 || m == 2) {
		y -= 1;
		m += 12;
	}
	int w, c;
	c = y / 100;
	y = y % 100;
	w = y + y / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
	while (w < 0) {
		w += 7;
	}
	w %= 7;
	return w;
}

void calendar(int year, int month)
{
	int days;
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
		days = 31;

	if (month == 4 || month == 6 || month == 9 || month == 11)
		days = 30;

	if (month == 2) {
		if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			days = 29;
		else
			days = 28;
	}
	int week = zeller(year, month, 1);
	cout << endl;
	cout << year << "��" << month << "��" << endl;
	/* ͷ���ָ��ߣ������� */
	cout << "======================================================" << endl;
	cout << "������  ����һ  ���ڶ�  ������  ������  ������  ������" << endl;
	cout << "======================================================" << endl;

	for (int i = 0; i < week; i++) {
		cout << "        ";
	}
	for (int day = 1; day <= days; day++) {
		cout << "  " << setw(2) << day << "    ";
		if ((day + week) % 7 == 0&&day!=days)
			cout << endl;
	}
	cout << endl;
	/* β���ָ��ߣ������� */
	cout << "======================================================" << endl;
}


int main()
{
	int year, month;

	while (1) {
		cout << "��������[1900-2100]����" << endl;
		cin >> year >> month;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "�����������������" << endl;
			continue;
		}
		else if (year < 1900 || year > 2100) {
			cout << "��ݲ���ȷ������������" << endl;
			continue;
		}
		else if (month > 12 || month < 1) {
			cout << "�·ݲ���ȷ������������" << endl;
			continue;
		}
		break;
	}
	calendar(year, month);
	return 0;
}