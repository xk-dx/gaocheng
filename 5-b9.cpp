/* 2354218 Ф��ͮ �ƿ� */
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
	cout << "������9*9�ľ���ֵΪ1-9֮��" << endl;
	int shudu[L][L] = { 0 };
	for (int i = 0; i < 81; i++) {
		while (1) {
			cin >> temp;
			if (cin.fail()) {
				cout << "�����������" << (i / 9 + 1) << "��" << (i % 9 + 1) << "��(���о���1��ʼ����)��ֵ"<<endl;
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			if (temp < 1 || temp>9)
			{
				cout << "�����������" << (i / 9 + 1) << "��" << (i % 9 + 1) << "��(���о���1��ʼ����)��ֵ"<<endl;
				continue;
			}
			break;
		}
		shudu[i / 9][i % 9] = temp;
	}
	
	if  (isValid(shudu))
		cout << "�������Ľ�" << endl;
	else
		cout << "���������Ľ�" << endl;
	return 0;
}
