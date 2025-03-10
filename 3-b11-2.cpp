/* ¼Æ¿Æ 2354218 Ð¤¼ÑÍ® */
#include <iostream> 
using namespace std;

int main()
{
	int i, j, k, sum = 0;

	for (i = 0; i < 5; i++) {
		for (j = 0; j < 5; j++) {
			for (k = 0; k < 5; k++) {
				cout << "*";
				sum++;
				if (k > 2)
					break;
			}
			cout << ' ';
			if (j > 0)
				break;
		}
		cout << endl;
		/************/
	}

	cout << "sum=" << sum << endl;
	cout << "i=" << i << endl;
	cout << "j=" << j << endl;
	cout << "k=" << k << endl;

	return 0;
}
