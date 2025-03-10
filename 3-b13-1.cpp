/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;
int main()
{
	int y, m, xq;

	while (1) {
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> y >> m;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;
		cout << "输入非法，请重新输入" << endl;
	}
	while (1) {
		cout << "请输入" << y << "年" << m << "月1日的星期(0-6表示星期日-星期六) : ";
		cin >> xq;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(2048, '\n');
		}
		else if (xq >= 0 && xq <= 6)
			break;
		cout << "输入非法，请重新输入" << endl;
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
	cout << y << "年" << m << "月" << "的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
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