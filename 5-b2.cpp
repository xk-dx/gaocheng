/* 2354218 Ð¤¼ÑÍ® ¼Æ¿Æ */
#include <iostream>
using namespace std;

int main()
{
	int sw[100] = {0};
	int i, j;
	for (i = 1; i <= 100; i++) {
		for (j = 0; j < 100; j++) {
			if ((j + 1) % i == 0) {
				if (sw[j] == 0)
					sw[j] = 1;
				else if (sw[j] == 1)
					sw[j] = 0;
			}
		}
	}
	for (int k = 0; k < 100; k++) {
		if (sw[k] == 1)
			if (k != 99)
				cout << k + 1 << ' ';
			else
				cout << k + 1;
	}
	cout << endl;
	return 0;
}