/* 2354218 肖佳彤 计科 */
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
	cout << year << "年" << month << "月" << endl;
	/* 头部分隔线，不算打表 */
	cout << "======================================================" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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
	/* 尾部分隔线，不算打表 */
	cout << "======================================================" << endl;
}


int main()
{
	int year, month;

	while (1) {
		cout << "请输入年[1900-2100]、月" << endl;
		cin >> year >> month;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		else if (year < 1900 || year > 2100) {
			cout << "年份不正确，请重新输入" << endl;
			continue;
		}
		else if (month > 12 || month < 1) {
			cout << "月份不正确，请重新输入" << endl;
			continue;
		}
		break;
	}
	calendar(year, month);
	return 0;
}