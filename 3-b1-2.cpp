/*2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    const double pi = 3.14159;
    double a, b, c, d, e, f, g;
    cout<<"������뾶�͸߶�"<<endl;
    cin>>a>>b;
    c = 2 * pi * a;//Բ�ܳ�
    d = pi * a * a;//Բ���
    e = 4 * pi * a * a;//Բ������
    f = 4.0 / 3 * pi * a * a * a;//Բ�����
    g = d * b;//Բ�����
    cout << setprecision(2) <<setiosflags(ios::fixed);
    cout << "Բ�ܳ�     : " << c<<endl;
    cout << "Բ���     : " << d<<endl;
    cout << "Բ������ : " << e<< endl;
    cout << "Բ�����   : " << f<< endl;
    cout << "Բ�����   : " << g<< endl;

    return 0;
}