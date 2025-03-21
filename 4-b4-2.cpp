/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
char menu()
{
	cout << "1.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界停止)" << endl;
	cout << "2.用I、J、K、L键控制上下左右(大小写均可，按左箭头光标不允许下移，边界回绕)" << endl;
	cout << "3.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界停止）" << endl;
	cout << "4.用箭头键控制上下左右（按大写HPKM不允许移动光标，边界回绕）" << endl;
	cout << "0.退出" << endl;
	cout << "[请选择0-4]";
	char ch;
	while (1) {
		ch = _getch();
		if (ch == '0' || ch == '1' || ch == '2' || ch == '3' || ch == '4')
			break;
	}
	return ch;
}

void move_by_ijkl(const HANDLE hout,int mode)
{
	cls(hout);
	init_border(hout);
	int X = 35, Y = 9;
	gotoxy(hout, X, Y);
    while (1)
	{
		int move;
		move = _getch();
		if (move == 32)
			putchar(32);//空格
		if (move == 224)
			_getch();
		if (move == 'i' || move == 'I') {
			if (Y > 1 && mode == '1')
				--Y;
			else if (mode == '2')
				if (Y > 1)
					--Y;
				else if (Y == 1)
					Y = 17;
		}
		else if (move == 'j' || move == 'J') {
			
			if (X > 1 && mode == '1')
				--X;
			else if (mode == '2')
				if (X > 1)
					--X;
				else if (X == 1)
					X = 70;
		}
		
		else if (move == 'k' || move == 'K') {
			if (Y <17  && mode == '1')
				++Y;
			else if (mode == '2')
				if (Y <17 )
					++Y;
				else if (Y == 17)
					Y = 1;
		}
		else if (move == 'l' || move == 'L') {
			if (X < 70 && mode == '1')
				++X;
			else if (mode == '2')
				if (X < 70)
					++X;
				else if (X == 70)
					X = 1;
		}
		else if (move == 'q' || move == 'Q')
			break;
		gotoxy(hout, X, Y);

	}
	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键返回菜单.";
	while (1) {
		int direction = _getch();
		if (direction == 13)
			break;
	};
	cls(hout);
}

void move_by_arrow(const HANDLE hout, int mode)
{
	cls(hout);
	init_border(hout);
	int X = 35, Y = 9;
	gotoxy(hout, X, Y);
	while (1)
	{
		int move;
		move = _getch();
		if (move == 32)
			putchar(32);//空格
		if (move == 224) {
			move = _getch();
			if (move== 72) {
				if (Y > 1 && mode == '3')
					--Y;
				else if (mode == '4')
					if (Y > 1)
						--Y;
					else if (Y == 1)
						Y = 17;
			}
			else if (move == 75) {

				if (X > 1 && mode == '3')
					--X;
				else if (mode == '4')
					if (X > 1)
						--X;
					else if (X == 1)
						X = 70;
			}

			else if (move==80) {
				if (Y < 17 && mode == '3')
					++Y;
				else if (mode == '4')
					if (Y < 17)
						++Y;
					else if (Y == 17)
						Y = 1;
			}
			else if (move == 77) {
				if (X < 70 && mode == '3')
					++X;
				else if (mode == '4')
					if (X < 70)
						++X;
					else if (X == 70)
						X = 1;
			}
		}
		else if (move == 'q' || move == 'Q')
			break;
		gotoxy(hout, X, Y);
	}
	gotoxy(hout, 0, 23);
	cout << "游戏结束，按回车键返回菜单.";
	while (1) {
		int direction = _getch();
		if (direction == 13)
			break;
	};
	cls(hout);
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	
	/* 生成伪随机数的种子，只需在程序开始时执行一次即可 */
	srand((unsigned int)(time(0)));
	char choose;

	while (1) {
		choose = menu();
		if (choose == '0')
			break;
		else if (choose == '1' || choose == '2')
			move_by_ijkl(hout,choose);
		else if (choose == '3' || choose == '4')
			move_by_arrow(hout, choose);
	}

	return 0;
} 