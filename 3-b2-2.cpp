/*2354218 肖佳彤 计科 */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i;
    cout<<"请输入一个[1..30000]间的整数:"<<endl;
    cin>>i;
    int a = i / 10000;
    int b = i / 1000 % 10;
    int c = i / 100 % 10;
    int d = i / 10 % 10;
    int e = i % 10;
    
    cout << setprecision(2) <<setiosflags(ios::fixed);
    cout << "万位 : " << a<<endl;
    cout << "千位 : " << b<<endl;
    cout << "百位 : " << c<< endl;
    cout << "十位 : " << d<< endl;
    cout << "个位 : " <<e<< endl;

    return 0;
}