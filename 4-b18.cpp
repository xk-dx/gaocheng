/* 2354218 肖佳彤 计科 */
#include <iostream>
using namespace std;

int max(int a, int b)
{
	return a > b ? a: b;
}

int max(int a, int b, int c)
{
	if (b > a)
		a = b;
	if (c > a)
		a = c;
	return a;
}

int max(int a, int b, int c, int d)
{
	if (b > a)
		a = b;
	if (c > a)
		a = c;
	if (d > a)
		a = d;
	return a;
}

int main()
{
	int num,a,b,c,d;
	while (1)
	{
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> num;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (num < 2 || num>4 )
		{
			cout << "个数输入错误" << endl;
			return 0;
		}
		if (num == 2)
		{
			cin >> a >> b;
			if (cin.fail() || a <= 0 || b <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else if (num == 3)
		{
			cin >> a >> b >> c;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else if (num == 4)
		{
			cin >> a >> b >> c >> d;
			if (cin.fail() || a <= 0 || b <= 0 || c <= 0 || d <= 0)
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
	}
	switch (num)
	{
		case 2:
			cout << "max=" << max(a, b) << endl;
			break;
		case 3:
			cout << "max=" << max(a, b, c) << endl;
			break;
		case 4:
			cout << "max=" << max(a, b, c, d) << endl;
			break;
		default:
			break;
	}
	return 0;
}