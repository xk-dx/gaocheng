/*2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int i;
    cout<<"������һ��[1..30000]�������:"<<endl;
    cin>>i;
    int a = i / 10000;
    int b = i / 1000 % 10;
    int c = i / 100 % 10;
    int d = i / 10 % 10;
    int e = i % 10;
    
    cout << setprecision(2) <<setiosflags(ios::fixed);
    cout << "��λ : " << a<<endl;
    cout << "ǧλ : " << b<<endl;
    cout << "��λ : " << c<< endl;
    cout << "ʮλ : " << d<< endl;
    cout << "��λ : " <<e<< endl;

    return 0;
}