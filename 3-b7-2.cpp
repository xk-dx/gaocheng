/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double amount;
    cout << "����������ֵ��" << endl;
    cin >> amount;

    int t_a = int(amount * 100);  
    int sum=0;
    if (amount >= 0.01 && amount < 100) {
        // 50Ԫ
        int count50 = t_a / 5000;
        if (count50 > 0) {
            sum += count50;
        }
        t_a %= 5000;  // ����ʣ��Ľ��

        // 20Ԫ
        int count20 = t_a / 2000;
        if (count20 > 0) {
            sum += count20;
        }
        t_a %= 2000;

        // 10Ԫ
        int count10 = t_a / 1000;
        if (count10 > 0) {
            sum += count10;
        }
        t_a %= 1000;

        // 5Ԫ
        int count5 = t_a / 500;
        if (count5 > 0) {
            sum += count5;
        }
        t_a %= 500;

        // 1Ԫ
        int count1 = t_a / 100;
        if (count1 > 0) {
            sum += count1;
        }
        t_a %= 100;

        // 5��
        int count50Cents = t_a / 50;
        if (count50Cents > 0) {
            sum += count50Cents;
        }
        t_a %= 50;

        // 1��
        int count10Cents = t_a / 10;
        if (count10Cents > 0) {
            sum += count10Cents;
        }
        t_a %= 10;

        // 5��
        int count5Cents = t_a / 5;
        if (count5Cents > 0) {
            sum += count5Cents;
        }
        t_a %= 5;

        // 2��
        int count2Cents = t_a / 2;
        if (count2Cents > 0) {
            sum += count2Cents;
        }
        t_a %= 2;

        // 1��
        int count1Cent = t_a;
        if (count1Cent > 0) {
            sum += count1Cent;
        }

        cout << "��" << sum << "�����㣬�������£�" << endl;
        // 50Ԫ
        if (count50 > 0) {
            cout << "50Ԫ : " << count50 << "��" << endl;
        }

        // 20Ԫ
        if (count20 > 0) {
            cout << "20Ԫ : " << count20 << "��" << endl;
        }
        // 10Ԫ
        if (count10 > 0) {
            cout << "10Ԫ : " << count10 << "��" << endl;
        }
        // 5Ԫ
        if (count5 > 0) {
            cout << "5Ԫ  : " << count5 << "��" << endl;
        }
        // 1Ԫ
        if (count1 > 0) {
            cout << "1Ԫ  : " << count1 << "��" << endl;
        }
        // 5��
        if (count50Cents > 0) {
            cout << "5��  : " << count50Cents << "��" << endl;
        }

        // 1��
        if (count10Cents > 0) {
            cout << "1��  : " << count10Cents << "��" << endl;
        }
        // 5��
        if (count5Cents > 0) {
            cout << "5��  : " << count5Cents << "��" << endl;
        }

        // 2��
        if (count2Cents > 0) {
            cout << "2��  : " << count2Cents << "��" << endl;
        }
        // 1��
        if (count1Cent > 0) {
            cout << "1��  : " << count1Cent << "��" << endl;
        }
    }
    else
        cout << "�����������������" << endl;
    return 0;
}
