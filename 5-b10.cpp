/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <iomanip>
#include <cmath>
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

void p_month(int ji)
{
	int f_month = (ji - 1) * 3 + 1;
	for (int i = f_month; i < f_month + 3; i++)
	{
		cout << "           "<< setw(2) << i << "月" << "                 ";
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "Sun Mon Tue Wed Thu Fri Sat" << "     ";
	}
	cout << endl;
}

int main()
{
    int year;
    while (1)
    {
        cout << "请输入年份[1900-2100]" << endl;
        cin >> year;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if (year < 1900 || year>2100)
            continue;
        break;
    }
    cout << year << "年的日历:" << endl << endl;
    int leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    int month_days[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
    int firstday[12] = { 0 };
    for (int i = 0; i < 12; i++)
        firstday[i] = zeller(year, i + 1, 1);
    for (int ji = 1; ji <= 4; ji++)
    {
        p_month(ji);
        int month_base = (ji - 1) * 3;
        int month_start[3] = { -firstday[month_base] + 1, -firstday[month_base + 1] + 1, -firstday[month_base + 2] + 1 };
        int terminate_output[3] = { 0, 0, 0 };

        while (true) {
            if (terminate_output[0] && terminate_output[1] && terminate_output[2]) {
                cout << endl;
                break;
            }

            bool flag = false;  

            for (int j = 0; j < 3; j++) {  
                int month = month_base + j;
                for (int k = 0; k < 7; k++) { 
                    if (month_start[j] <= 0 || month_start[j] > month_days[month]) {
                        cout << "    ";
                        month_start[j]++;
                        if (month_start[j] > month_days[month]) {
                            terminate_output[j] = 1;
                        }
                    }
                    else {
                        cout << setw(4) << setiosflags(ios::left) << month_start[j]++<<resetiosflags(ios::left);

                        flag = true;
                    }
                }
                if (j != 2) cout << "    "; 
            }

            cout << endl;
            if (!flag)
                break; 
        }
    }
    cout << endl;
	return 0;
}