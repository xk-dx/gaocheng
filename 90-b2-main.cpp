/* 2354218 肖佳彤 计科 */
#include <iostream>
#include "90-b2.h"
using namespace std;
void menu()
{
	int flag = 1;
	while (flag) {
		cct_cls();
		cout << "--------------------------------------------" << endl;
		cout << "A.内部数组，随机生成初始5个球" << endl;
		cout << "B.内部数组，随机生成60%的球，寻找移动路径" << endl;
		cout << "C.内部数组，完整版" << endl;
		cout << "D.画出n*n的框架（无分隔线），随机显示5个球" << endl;
		cout << "E.画出n*n的框架（有分隔线），随机显示5个球" << endl;
		cout << "F.n*n的框架，60%的球，支持鼠标，完成一次移动" << endl;
		cout << "G.cmd图形界面完整版" << endl;
		cout << "Q.退出" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "请选择:";
		char key = _getch();
	
		if (key == 'A' || key == 'a') {
			putchar(key);
			Sleep(100);
			choice_a();
			judge_end();
		}
		else if (key == 'B' || key == 'b') {
			putchar(key);
			Sleep(100);
			choice_b();
			judge_end();
		}
		else if (key == 'C' || key == 'c') {
			putchar(key);
			Sleep(100);
			choice_c();
			judge_end();
		}

		else if (key == 'D' || key == 'd') {
			putchar(key);
			Sleep(100);
			choice_d();
			judge_end();
		}		
		else if (key == 'E' || key == 'e') {
			putchar(key);
			Sleep(100);
			choice_e();
			judge_end();
		}
		else if (key == 'F' || key == 'f') {
			putchar(key);
			Sleep(100);
			choice_f();
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			judge_end();
		}
		
		else if (key == 'G' || key == 'g') {
			putchar(key);
			Sleep(100);
			choice_g();
			cct_setcursor(CURSOR_VISIBLE_NORMAL);
			judge_end();
		}
		
		 if (key == 'Q' || key == 'q') {
			putchar(key);
			Sleep(100);
			cct_cls();
			flag = judge_end();
		}
		
	}
}

int main()
{
	cct_setfontsize("新宋体", 28);
	cct_setconsoleborder(80,28,80,200);
	srand((unsigned int)(time(0)));
	menu();
	
	cct_showstr(0, 23, "请按任意键继续. . .");
	_getch();
	return 0;
}