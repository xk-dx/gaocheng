/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
using namespace std;

void input(string id[],string name[],int score[])
{
    for (int i = 0; i < 10; i++) {
        cout << "�������" << i + 1 << "���˵�ѧ�š��������ɼ�" << endl;
        cin >> id[i] >> name[i] >> score[i];
    }
    cout << endl;
}

void sort(string id[], string name[], int score[])
{
    for (int i = 0; i < 9; i++) {
        for (int j = i + 1; j < 10; j++) {
            if (id[i] > id[j]) {
                string tempid;
                tempid = id[i];
                id[i] = id[j];
                id[j] = tempid;
                string tempname;
                tempname = name[i];
                name[i] = name[j];
                name[j] = tempname;
                int tempScore = score[i];
                score[i] = score[j];
                score[j] = tempScore;
            }
        }
    }
}

void output(string id[], string name[], int score[])
{
    cout << "ȫ��ѧ��(ѧ������):" << endl;
    for (int i = 0; i < 10; i++) {
            cout << name[i] << ' ' << id[i] << ' ' << score[i] << endl;
    }
}

int main() {
	string id[10];
	string name[10];
	int score[10] = { 0 };

    input(id, name, score);
    sort(id, name, score);
    output(id, name, score);
   
    return 0;
}