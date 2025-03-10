/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "5-b7.h"
using namespace std;
int stack_a[10] = { 0,0,0,0,0,0,0,0,0,0 };
int stack_b[10] = { 0,0,0,0,0,0,0,0,0,0 };
int stack_c[10] = { 0,0,0,0,0,0,0,0,0,0 };
int top_a = 0;
int top_b = 0;
int top_c = 0;
static int num = 1;
static int Time=0;

void init(int n, char src)
{
    if (src == 'A')
    {
        while (top_a < n)
        {
            stack_a[top_a++] = n - top_a;
        }
    }
    else if (src == 'B')
    {
        while (top_a < n)
        {
            stack_b[top_b++] = n - top_b;
        }
    }
    else if (src == 'C')
    {
        while (top_c < n)
        {
            stack_c[top_c++] = n - top_c;
        }
    }
}

void push_pop(char src, char dst)
{
    int element = 0;
    if (src == 'A' && top_a > 0)
    {
        element = stack_a[--top_a];
        stack_a[top_a] = 0;
    }
    else if (src == 'B' && top_b > 0)
    {
        element = stack_b[--top_b];
        stack_b[top_b] = 0;
    }
    else if (src == 'C' && top_c > 0)
    {
        element = stack_c[--top_c];
        stack_c[top_c] = 0;
    }
    if (dst == 'A' && top_a < 10)
        stack_a[top_a++] = element;
    else if (dst == 'B' && top_b < 10)
        stack_b[top_b++] = element;
    else if (dst == 'C' && top_c < 10)
        stack_c[top_c++] = element;
}

void print()
{
    cout << " A:";
    for (int i = 0; i < 10; i++)
    {
        if (stack_a[i])
            cout << setw(2) << stack_a[i];
        else
            cout << "  ";
    }
    cout << " B:";
    for (int i = 0; i < 10; i++)
    {
        if (stack_b[i])
            cout << setw(2) << stack_b[i];
        else
            cout << "  ";
    }
    cout << " C:";
    for (int i = 0; i < 10; i++)
    {
        if (stack_c[i])
            cout << setw(2) << stack_c[i];
        else
            cout << "  ";
    }
    cout << endl;
}
void print_v_init(char src, char dst, int speed)
{
    cct_gotoxy(0, 20);
    cout << "         =========================" << endl;
    cout << "           A         B         C";
    for (int i = 0; i < top_a; i++)
    {
        cct_gotoxy(10, 19 - i);
        if (stack_a[i])
        {
            cout << setw(2) << stack_a[i];
        }
    }
    for (int i = 0; i < top_b; i++)
    {
        cct_gotoxy(20, 19 - i);
        if (stack_b[i])
        {
            cout << setw(2) << stack_b[i];
        }
    }
    for (int i = 0; i < top_c; i++)
    {
        cct_gotoxy(30, 19 - i);
        if (stack_c[i])
        {
            cout << setw(2) << stack_c[i];
        }
        if (speed)
        {
            Sleep(Time);
        }
        else
        {
            while (getchar() != '\n');
        }
    }
}
  
void print_v(char src, char dst, int speed)
{
        if (src == 'A')
        {
            cct_gotoxy(10, 19 - top_a);
            cout << "  ";
        }
        else if (src == 'B')
        {
            cct_gotoxy(20, 19 - top_b);
            cout << "  ";
        }
        else if (src == 'C')
        {
            cct_gotoxy(30, 19 - top_c);
            cout << "  ";
        }
        if (dst == 'A')
        {
            cct_gotoxy(10, 20 - top_a);
            cout << setw(2) << stack_a[top_a - 1];
        }
        else if (dst == 'B')
        {
            cct_gotoxy(20, 20 - top_b);
            cout << setw(2) << stack_b[top_b - 1];
        }
        else if (dst == 'C')
        {
            cct_gotoxy(30, 20 - top_c);
            cout << setw(2) << stack_c[top_c - 1];
        }
    if (speed)
    {
        Sleep(Time);
    }
    else
    {
        while (getchar() != '\n');
    }
}

void hanoi(int n, char src, char tmp, char dst, int speed, int disp)
{
    if (n == 1)
    {
        cct_gotoxy(20, 25);
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
        push_pop(src, dst);
        if (disp)
        {
            cct_gotoxy(40, 25);
            print();
        }
        print_v(src, dst, speed);

    }
    if (n > 1)
    {
        hanoi(n - 1, src, dst, tmp, speed, disp);
        cct_gotoxy(20, 25);
        cout << "��" << setw(4) << num++ << " ��(" << setw(2) << n << "): " << src << "-->" << dst;
        push_pop(src, dst);
        if (disp)
        {
            cct_gotoxy(40, 25);
            print();
        }
        print_v(src, dst, speed);

        hanoi(n - 1, tmp, src, dst, speed, disp);
    }
  
}
int main()
{
    int n;
    char src, dst, tmp;
    int speed,disp;
    while (1) {
        cout << "�����뺺ŵ���Ĳ���(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(65536, '\n');
        if (n >= 1 && n <= 10)
            break;
    }
    while (1) {
        cout << "��������ʼ��(A-C)" << endl;
        cin >> src;
        cin.clear();
        cin.ignore(65536, '\n');
        if (src >= 'a' && src <= 'c') {
            src -= 32;
            break;
        }
        if (src >= 'A' && src <= 'C')
            break;
    }
    while (1) {
        cout << "������Ŀ����(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(65536, '\n');

        if (dst >= 'a' && dst <= 'c') {
            dst -= 32;
        }
        if (dst >= 'A' && dst <= 'C')
            if (dst == src)
                cout << "Ŀ����(" << dst << ")��������ʼ��(" << src << ")��ͬ" << endl;
            else
                break;
    }
    if ((src == 'A' && dst == 'B') || (src == 'B' && dst == 'A'))
        tmp = 'C';
    else if ((src == 'A' && dst == 'C') || (src == 'C' && dst == 'A'))
        tmp = 'B';
    else
        tmp = 'A';

    while (1)
    {
        cout << "�������ƶ��ٶ�(0-5: 0-���س�������ʾ 1-��ʱ� 5-��ʱ���)" << endl;
        cin >> speed;
        cin.clear();
        cin.ignore(65536, '\n');
        if (speed >= 0 && speed <= 5)
            break;
    }

    while (1)
    {
        cout << "�������Ƿ���ʾ�ڲ�����ֵ(0-����ʾ 1-��ʾ)" << endl;
        cin >> disp;
        cin.clear();
        cin.ignore(65536, '\n');
        if (disp >= 0 && disp<=1)
            break;
    }

    cct_cls();
    init(n, src);
    if (disp==0)
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << "������ʾ�ڲ�����ֵ" << endl;
    else if (disp==1)
        cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " �㣬��ʱ����Ϊ " << speed << "����ʾ�ڲ�����ֵ" << endl;
    switch (speed)
    {
        case(1):
            Time = 1000;
            break;
        case(2):
            Time = 500;
            break;
        case(3):
            Time = 200;
            break;
        case(4):
            Time = 50;
            break;
        case(5):
            Time = 0;
            break;
    }
    if (disp)
    {
        cct_gotoxy(20, 25);
        cout << "��ʼ:                ";
        print();
        if (speed)
            Sleep(Time);
        else
        {
            while (getchar() != '\n');
        }
        print_v_init(src, dst, speed);
    }
    else
    {
        print_v_init(src, dst, speed);
    }
    hanoi(n, src, tmp, dst, speed, disp);
	system("pause"); //���������ʾ��ͣ��ע�⣺ֻ�ʺ����ض��������ر������ĳ���Ӵ˾���÷�Ϊ0��
	return 0;
}
