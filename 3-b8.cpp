/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <cmath>
#include <iomanip> 
using namespace std;
int main()
{
	int x;
	while (1) {
		cout << "请输入x的值[-10 ~ +65]" << endl;
		cin >> x;
		if (x >= -10 && x <= 65) {
			break;
		}
		cout << "输入非法，请重新输入" << endl;
	}
	int fm = 1;
	double n = 1;
	double e = 0;
	while (fabs(n) >= 1e-6) {
		e += n;
		n *= x;
		n /= fm;
		fm++;
	}
	cout << "e^" << x << "=" << setprecision(10) << e << endl;
	return 0;
}