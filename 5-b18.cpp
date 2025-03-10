/* 2354218 Ð¤¼ÑÍ® ¼Æ¿Æ */
#include <iostream>
using namespace std;

int main()
{
	int valid = 1;
	char top_line[1000];
	cin.getline(top_line,1000);
	int length, upper, lower, number, other;

		cin >> length >> upper >> lower >> number >> other;
		if (cin.fail())
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		if (length < 12 || length>16)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		if (upper < 2)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		if (lower < 2)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		if (number < 2)
		{
			cout << "´íÎó" << endl;
			return 0;
		}
		if (other < 2)
		{
			cout << "´íÎó" << endl;
			return 0;
		}

		if (upper + lower + number + other > length)
		{
			cout << "´íÎó" << endl;
			return 0;
		}

			char password[17];
			cin.getline(password, 17);
			for (int i = 0; i < 10 ; i++)
			{
				int upper_real = 0, lower_real = 0, number_real = 0, other_real = 0;
				cin >> password;
				int j = 0;
				while (password[j])
				{
					if (password[j] >= 'a' && password[j] <= 'z')
					{
						lower_real++;
					}
					else if (password[j] >= 'A' && password[j] <= 'Z')
					{
						upper_real++;
					}
					else if (password[j] >= '0' && password[j] <= '9')
					{
						number_real++;
					}
					else
					{
						other_real++;
					}
					j++;
				}
				if (j != length || upper_real < upper || lower_real < lower||number_real < number || other_real < other)
				{
					valid = 0;
					break;
				}
			}
			if (valid)
			{
				cout << "ÕýÈ·" << endl;
			}
			else
			{
				cout << "´íÎó" << endl;
			}
			return 0;
		}