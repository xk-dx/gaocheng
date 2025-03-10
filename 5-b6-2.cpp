/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <iomanip>
using namespace std;
int top[3] = { 0 };
int stack[3][10] = { 0 };
int num = 1;

void init(int n, char src)
{
    if (src == 'A')
    {
        while (top[0] < n)
        {
            stack[0][top[0]++] = n - top[0];
        }
    }
    else if (src == 'B')
    {
        while (top[1] < n)
        {
            stack[1][top[1]++] = n - top[1];
        }
    }
    else if (src == 'C')
    {
        while (top[2] < n)
        {
            stack[2][top[2]++] = n - top[2];
        }
    }
}

void print()
{   
    int i,j;
    for (i = 0; i < 3; i++) {
        cout << " " << char('A' + i) << ":";
        for (j = 0; j < 10; j++){
            if (stack[i][j])
            {
                cout << setw(2) << stack[i][j];
            }
            else
            {
                cout << "  ";
            }
        }
    }
    cout << endl;
}

void push_pop(char src, char dst)
{
    int element = 0;
    if (src == 'A' && top[0] > 0)
    {
        element = stack[0][--top[0]];
        stack[0][top[0]] = 0;
    }
    else if (src == 'B' && top[1] > 0)
    {
        element = stack[1][--top[1]];
        stack[1][top[1]] = 0;
    }
    else if (src == 'C' && top[2] > 0)
    {
        element = stack[2][--top[2]];
        stack[2][top[2]] = 0;
    }
    if (dst == 'A' && top[0] < 10)
    {
        stack[0][top[0]++] = element;
    }
    else if (dst == 'B' && top[1] < 10)
    {
        stack[1][top[1]++] = element;
    }
    else if (dst == 'C' && top[2] < 10)
    {
        stack[2][top[2]++] = element;
    }
}

void hanoi(int n, char src, char tmp, char dst)
{
    if (n == 1) {
        cout << "第" << setw(4) << num++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        push_pop(src, dst);
        print();
    }
    else
    {
        hanoi(n - 1, src, dst, tmp);
        cout << "第" << setw(4) << num++ << " 步(" << setw(2) << n << "): " << src << "-->" << dst;
        push_pop(src, dst);
        print();
        hanoi(n - 1, tmp, src, dst);
    }
}

int main()
{
    int n;
    char src, dst, tmp;
    int speed;
    while (1) {
        cout << "请输入汉诺塔的层数(1-10)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(65536, '\n');
        if (n >= 1 && n <= 10)
            break;
    }
    while (1) {
        cout << "请输入起始柱(A-C)" << endl;
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
        cout << "请输入目标柱(A-C)" << endl;
        cin >> dst;
        cin.clear();
        cin.ignore(65536, '\n');

        if (dst >= 'a' && dst <= 'c') {
            dst -= 32;
        }
        if (dst >= 'A' && dst <= 'C')
            if (dst == src)
                cout << "目标柱(" << dst << ")不能与起始柱(" << src << ")相同" << endl;
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
        cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
        cin >> speed;
        cin.clear();
        cin.ignore(65536, '\n');
        if (speed >= 0 && speed <= 5)
            break;
    }
    cout << "初始:               ";
    init(n, src);
    print();
    hanoi(n, src, tmp, dst);

    return 0;
}