/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double amount;
    cout << "请输入找零值：" << endl;
    cin >> amount;

    int t_a = int(amount * 100);  
    int sum=0;
    if (amount >= 0.01 && amount < 100) {
        // 50元
        int count50 = t_a / 5000;
        if (count50 > 0) {
            sum += count50;
        }
        t_a %= 5000;  // 更新剩余的金额

        // 20元
        int count20 = t_a / 2000;
        if (count20 > 0) {
            sum += count20;
        }
        t_a %= 2000;

        // 10元
        int count10 = t_a / 1000;
        if (count10 > 0) {
            sum += count10;
        }
        t_a %= 1000;

        // 5元
        int count5 = t_a / 500;
        if (count5 > 0) {
            sum += count5;
        }
        t_a %= 500;

        // 1元
        int count1 = t_a / 100;
        if (count1 > 0) {
            sum += count1;
        }
        t_a %= 100;

        // 5角
        int count50Cents = t_a / 50;
        if (count50Cents > 0) {
            sum += count50Cents;
        }
        t_a %= 50;

        // 1角
        int count10Cents = t_a / 10;
        if (count10Cents > 0) {
            sum += count10Cents;
        }
        t_a %= 10;

        // 5分
        int count5Cents = t_a / 5;
        if (count5Cents > 0) {
            sum += count5Cents;
        }
        t_a %= 5;

        // 2分
        int count2Cents = t_a / 2;
        if (count2Cents > 0) {
            sum += count2Cents;
        }
        t_a %= 2;

        // 1分
        int count1Cent = t_a;
        if (count1Cent > 0) {
            sum += count1Cent;
        }

        cout << "共" << sum << "张找零，具体如下：" << endl;
        // 50元
        if (count50 > 0) {
            cout << "50元 : " << count50 << "张" << endl;
        }

        // 20元
        if (count20 > 0) {
            cout << "20元 : " << count20 << "张" << endl;
        }
        // 10元
        if (count10 > 0) {
            cout << "10元 : " << count10 << "张" << endl;
        }
        // 5元
        if (count5 > 0) {
            cout << "5元  : " << count5 << "张" << endl;
        }
        // 1元
        if (count1 > 0) {
            cout << "1元  : " << count1 << "张" << endl;
        }
        // 5角
        if (count50Cents > 0) {
            cout << "5角  : " << count50Cents << "张" << endl;
        }

        // 1角
        if (count10Cents > 0) {
            cout << "1角  : " << count10Cents << "张" << endl;
        }
        // 5分
        if (count5Cents > 0) {
            cout << "5分  : " << count5Cents << "张" << endl;
        }

        // 2分
        if (count2Cents > 0) {
            cout << "2分  : " << count2Cents << "张" << endl;
        }
        // 1分
        if (count1Cent > 0) {
            cout << "1分  : " << count1Cent << "张" << endl;
        }
    }
    else
        cout << "输入错误，请重新输入" << endl;
    return 0;
}
