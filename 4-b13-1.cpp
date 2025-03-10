/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、不允许添加其它函数
   4、main函数处理输入，允许循环
   --------------------------------------------------------------------- */

   /***************************************************************************
     函数名称：
     功    能：打印n层汉诺塔的移动顺序
     输入参数：int n：层数
               char src：起始柱
               char tmp：中间柱
               char dst：目标柱
     返 回 值：
     说    明：1、函数名、形参、返回类型均不准动
               2、本函数不允许出现任何形式的循环
               3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
    static int b=0;
    if (n == 1) {
        b++;
        cout << setw(5) << b << ": " << setw(2) << n << "# " << src << "-->" << dst << endl;
    }
    else
    {
     
        hanoi(n - 1, src, dst, tmp);
        b++;
        cout <<setw(5)<<b<<": " << setw(2) << n << "# " << src << "-->" << dst << endl;
        hanoi(n - 1, tmp, src, dst);
    }
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：1、完成输入、调用递归函数
            2、处理输入错误时，允许使用循环
            3、为了统一检查，不再允许添加其它函数（输入起始/目标柱的代码不要求统一函数处理，均直接放在main中）
***************************************************************************/
int main()
{
    int n;
    char src, dst, tmp;
    while (1) {
        cout << "请输入汉诺塔的层数(1-16)" << endl;
        cin >> n;
        cin.clear();
        cin.ignore(65536, '\n');
        if (n >= 1 && n <= 16)
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
    cout << "移动步骤为:" << endl;
    hanoi(n, src, tmp, dst);

    return 0;
}