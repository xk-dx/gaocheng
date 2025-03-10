/* 2354218 肖佳彤 计科 */
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
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
	cout << "请输入数据的个数[1..10000]" << endl;
	cin >> n;
	cout << "请输入" << n << "个正整数" << endl;
	int num[10000] = { 0 };
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	int base;
	int count=0;
	cout << "请输入基数[2..9]" << endl;
	cin >> base;

	for (int i = 0; i < n; i++) {
		if (is_z(num[i], base)) {
			count++;
		}
	}
	cout << n << "个数中" << base << "进制个位为0的个数 : " << count<<endl;
	return 0;
}
