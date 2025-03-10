/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <Windows.h>
#include <ctime>   
using namespace std;
static const char other[] = "!@#$%^&*-_=+,.?";

int main()
{
	srand((unsigned int)(time(0)));
	int length, upper, lower, number, other_n;
	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> length >> upper >> lower >> number >> other_n;
	if (cin.fail())
		cout << "输入非法" << endl;
	else if (length < 12 || length > 16)
		cout << "密码长度[" << length << "]不正确" << endl;
	else if (upper < 2 || upper > 16)
		cout << "大写字母个数[" << upper << "]不正确" << endl;
	else if (lower < 2 || lower > 16)
		cout << "小写字母个数[" << lower << "]不正确" << endl;
	else if (number < 2 || number > 16)
		cout << "数字个数[" << number << "]不正确" << endl;
	else if (other_n < 2 || other_n > 16)
		cout << "其它符号个数[" << other_n << "]不正确" << endl;
	else if (upper + lower + number + other_n > length)
		cout << "所有字符类型之和[" << upper << "+" << lower << "+" << number << "+" << other_n << "]大于总密码长度[" << length << "]" << endl;
	else{

		cout << length << " " << upper << " " << lower << " " << number << " " << other_n << endl;
	

		for (int i = 0; i<10; i++)
		{
			int types[4];
			types[0] = upper;
			types[1] = lower;
			types[2] = number;
			types[3] = other_n;
			int uncategorized = length - (upper + lower + number + other_n);
			while (uncategorized--)
			{
				types[rand() % 4]++;
			}

			char key[17] = { 0 };
			int index;
			while (types[0] > 0) {
				index = rand() % length;
				if (!key[index]) {
					key[index] = 'A' + rand() % 26;
					types[0]--;
				}
			}
			while (types[1] > 0) {
				index = rand() % length;
				if (!key[index]) {
					key[index] = 'a' + rand() % 26;
					types[1]--;
				}
			}
			while (types[2] > 0) {
				index = rand() % length;
				if (!key[index]) {
					key[index] = '0' + rand() % 9;
					types[2]--;
				}
			}
			while (types[3] > 0) {
				index = rand() % length;
				if (!key[index]) {
					int char_index;
					char_index = rand() % 15;
					key[index] = other[char_index];
					types[3]--;
				}
			}
			cout << key << endl;
		}
	}

	return 0;
}
