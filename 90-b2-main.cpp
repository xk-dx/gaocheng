/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include "90-b2.h"
using namespace std;
void menu()
{
	int flag = 1;
	while (flag) {
		cct_cls();
		cout << "--------------------------------------------" << endl;
		cout << "A.�ڲ����飬������ɳ�ʼ5����" << endl;
		cout << "B.�ڲ����飬�������60%����Ѱ���ƶ�·��" << endl;
		cout << "C.�ڲ����飬������" << endl;
		cout << "D.����n*n�Ŀ�ܣ��޷ָ��ߣ��������ʾ5����" << endl;
		cout << "E.����n*n�Ŀ�ܣ��зָ��ߣ��������ʾ5����" << endl;
		cout << "F.n*n�Ŀ�ܣ�60%����֧����꣬���һ���ƶ�" << endl;
		cout << "G.cmdͼ�ν���������" << endl;
		cout << "Q.�˳�" << endl;
		cout << "--------------------------------------------" << endl;
		cout << "��ѡ��:";
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
	cct_setfontsize("������", 28);
	cct_setconsoleborder(80,28,80,200);
	srand((unsigned int)(time(0)));
	menu();
	
	cct_showstr(0, 23, "�밴���������. . .");
	_getch();
	return 0;
}