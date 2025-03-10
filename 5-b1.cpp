/* 2354218 肖佳彤 计科 */
#include <iostream>
using namespace std;

int main()
{
	int i = 0, a;
	int num[21]={0}, temp;
	cout << "请输入任意个正整数（升序，最多20个），0或负数结束输入"<< endl;
	for (i; i < 20; i++)
	{
		cin >> temp;
		if (temp > 0)
			num[i] = temp;
		else
			break;
	}
	if (i == 0)
		cout << "无有效输入" << endl;
	if (i > 0)
	{
		cout << "原数组为：" << endl;
		for (int j = 0; j < i; j++)
			cout << num[j] << ' ';
	}
	cout << endl;
	cin.ignore(65536, '\n');
	cout << "请输入要插入的正整数" << endl;
	cin >> a;
	int i2 = 0;
	for (i2; i2 < i; i2++)
	{
		if (num[i2] > a)
			break;
	}
	for (int i3 =i; i3 >i2; i3--) {
		num[i3] = num[i3 - 1];
	}
	num[i2] = a;
	cout << "插入后的数组为：" << endl;
	for (int j = 0; j < i+1; j++)
		cout << num[j] << ' ';
	cout << endl;
	return 0;
}
