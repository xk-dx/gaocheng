/* 2354218 肖佳彤 计科 */
#include <iostream>
using namespace std;

int huiwen(char* str)
{
	int flag=1;
	char* p1=str, * p2=str+ strlen(str)-2;
	for (; p1< p2; p1++, p2--) {
		if (*p1 != *p2) {
			flag = 0;
			break;
		}
	}
	return flag;
}

int main()
{
	char str[81];
	cout << "请输入一个长度小于80的字符串（回文串）" << endl;
	fgets(str, 80,stdin);
	int is_huiwen;
	is_huiwen = huiwen(str);

	if (is_huiwen) {
		cout << "yes" << endl;
	}
	else
		cout << "no" << endl;
	return 0;
}