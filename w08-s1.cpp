/* 2354218 肖佳彤 计科 */
#include <iostream>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：输出位数、正序、逆序
  输入参数：
  返 回 值：
  说    明：不准修改函数名、返回类型、形参
***************************************************************************/
void output(int k)
{
	int temp = k;
	int num = 1;
	while (temp > 1)
	{
		num++;
		temp = temp / 10;
	}
	cout << num << "位数" << endl;
	temp = k;
	int n = 1;
	for (int i = 0; i < num - 1; i++)
	{
		n *= 10;
	}
	cout << "每位数字分别是 : " << endl;
	for (int i = 0; i < num; i++)
	{

		cout << temp / n % 10;

		n = n / 10;
		if (i != num - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
	cout << "逆序输出的每位数字分别是 : " << endl;
	n = 1;
	for (int i = 0; i < num; i++)
	{
		cout << temp / n % 10;
		n = n * 10;
		if (i != num - 1)
		{
			cout << " ";
		}
	}
	cout << endl;
}


/***************************************************************************
  函数名称：
  功    能：重复输入，直到取得[0..99999]之间的整数后返回
  输入参数：
  返 回 值：
  说    明：不准修改函数名、返回类型、形参
***************************************************************************/
int input(void)
{
	int k;
	while (1) {
		cout << "请输入一个[0..99999]间的整数" << endl;
		cin >> k;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
		}
		else if (k >= 0 && k <= 99999) {
			break;
		}
	}
	return k;

}
	/***************************************************************************
	  函数名称：
	  功    能：
	  输入参数：
	  返 回 值：
	  说    明：main函数不准动
	***************************************************************************/
	int main()
	{
		int k;

		k = input();
		output(k);

		return 0;
	}