/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//����*��ɵı߿�Ŀ��
const int MAX_Y = 17;	//����*��ɵı߿�ĸ߶�

/***************************************************************************
  �������ƣ�
  ��    �ܣ������system("cls")һ���Ĺ��ܣ���Ч�ʸ�
  ���������
  �� �� ֵ��
  ˵    �������������Ļ���������������ǿɼ���������(ʹ�õ�ǰ��ɫ)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* ȡ��ǰ��������Ϣ */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* ����ַ� */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* ������� */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* ���ص�(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  �������ƣ�gotoxy
  ��    �ܣ�������ƶ���ָ��λ��
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  �������ƣ�showch
  ��    �ܣ���ָ��λ�ô���ӡһ��ָ�����ַ�
  ���������HANDLE hout ������豸���
			int X       ��ָ��λ�õ�x����
			int Y       ��ָ��λ�õ�y����
			char ch     ��Ҫ��ӡ���ַ�
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  �������ƣ�init_border
  ��    �ܣ���ʾ��ʼ�ı߿�����ַ�
  ���������HANDLE hout������豸���
  �� �� ֵ����
  ˵    �����˺�����׼�޸�
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//����ƻ����Ͻ�(0,0)
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

	/* �����ʾ20����д��ĸ����ĸ��ֵ��XY���궼�����ʾ
	   rand()�����Ĺ��ܣ��������һ���� 0-32767 ֮�������
	   ˼������ʲô����£��������ѭ��ִ�����ɺ��㿴����ʵ����ĸ��������20���� */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- �������ӵ����ɺ������Է��ڴ˴� --*/
char menu()
{
	cout << "1.��I��J��K��L��������������(��Сд���ɣ������ͷ��겻�������ƣ��߽�ֹͣ)" << endl;
	cout << "2.��I��J��K��L��������������(��Сд���ɣ������ͷ��겻�������ƣ��߽����)" << endl;
	cout << "3.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽�ֹͣ��" << endl;
	cout << "4.�ü�ͷ�������������ң�����дHPKM�������ƶ���꣬�߽���ƣ�" << endl;
	cout << "0.�˳�" << endl;
	cout << "[��ѡ��0-4]";
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
			putchar(32);//�ո�
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
	cout << "��Ϸ���������س������ز˵�.";
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
			putchar(32);//�ո�
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
	cout << "��Ϸ���������س������ز˵�.";
	while (1) {
		int direction = _getch();
		if (direction == 13)
			break;
	};
	cls(hout);
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main���������ڳ�ʼ��ʾ�����԰���ĿҪ��ȫ���Ʒ���д
***************************************************************************/
int main()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //ȡ��׼����豸��Ӧ�ľ��
	
	/* ����α����������ӣ�ֻ���ڳ���ʼʱִ��һ�μ��� */
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