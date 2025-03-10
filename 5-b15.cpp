/* 2354218 肖佳彤 计科 */
#include <iostream>
using namespace std;

int main()
{
	int upper=0, lower=0, number=0, space=0, other=0;
	char str[3][128];
	for (int i = 0; i < 3; i++)
	{
		cout << "请输入第" << i + 1 << "行" << endl;
		cin.getline(str[i], 128);
	}
	for (int i = 0; i < 3; i++)
	{
		for (unsigned int j = 0; j < strlen(str[i]); j++)
		{
			if (str[i][j] >= 'A' && str[i][j] <= 'Z')
				upper++;
			else if (str[i][j] >= 'a' && str[i][j] <= 'z')
				lower++; 
			else if (str[i][j] >= '0' && str[i][j] <= '9')
				number++;
			else if (str[i][j] == ' ')
				space++;
			else
				other++;
		}
	}
	cout << "大写 : " << upper << endl;
	cout << "小写 : " << lower << endl;
	cout << "数字 : " << number << endl;
	cout << "空格 : " << space << endl;
	cout << "其它 : " << other << endl;
	return 0;
} 
 