/* 2354218 肖佳彤 计科 */
#include <iostream>
using namespace std;
#define L 9
bool isValid(int array[L][L]) {

    for (int r = 0; r < L; r++) {
        int check[9] = { 0 };
        for (int c = 0; c < L; c++) {
            int num = array[r][c];
            if (num != 0) {
                if (check[num - 1] == 0) {
                    check[num - 1] = 1;
                }
                else {
                    return false;
                }
            }
        }
    }

    for (int c = 0; c < L; c++) {
        int check[9] = { 0 };
        for (int r = 0; r < L; r++) {
            int num = array[r][c];
            if (num != 0) {
                if (check[num - 1] == 0) {
                    check[num - 1] = 1;
                }
                else {
                    return false;
                }
            }
        }
    }

    for (int blockRow = 0; blockRow < L; blockRow += 3) {
        for (int blockCol = 0; blockCol < L; blockCol += 3) {
            int check[9] = { 0 };
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int num = array[blockRow + i][blockCol + j];
                    if (num != 0) {
                        if (check[num - 1] == 0) {
                            check[num - 1] = 1;
                        }
                        else {
                            return false;
                        }
                    }
                }
            }
        }
    }

    return true;
}
int main()
{
	int temp;
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	int shudu[L][L] = { 0 };
	for (int i = 0; i < 81; i++) {
		while (1) {
			cin >> temp;
			if (cin.fail()) {
				cout << "请重新输入第" << (i / 9 + 1) << "行" << (i % 9 + 1) << "列(行列均从1开始计数)的值"<<endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (temp < 1 || temp>9)
			{
				cout << "请重新输入第" << (i / 9 + 1) << "行" << (i % 9 + 1) << "列(行列均从1开始计数)的值"<<endl;
				continue;
			}
			break;
		}
		shudu[i / 9][i % 9] = temp;
	}
	
	if  (isValid(shudu))
		cout << "是数独的解" << endl;
	else
		cout << "不是数独的解" << endl;
	return 0;
}
