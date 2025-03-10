/* 2354218 肖佳彤 计科 */
#include "90-b2.h"
void g_init(int x,int y,int shuzu[9][9],int line,int col)
{
	cct_showstr(x, y, "╔", COLOR_HWHITE, 0);
	cct_showstr(x + 2, y, "═", COLOR_HWHITE, 0, col);
	cct_showstr(x + 2+col*2, y, "╗", COLOR_HWHITE, 0 );
	
	for (int i = 0; i < line; i++) {
		cct_showstr(x, y+i+1, "║", COLOR_HWHITE, 0);
		cct_showstr(x + 2 + col * 2, y + i + 1, "║", COLOR_HWHITE, 0);
	}
	cct_showstr(x, y+line+1, "╚", COLOR_HWHITE, 0);
	cct_showstr(x + 2, y+line+1, "═", COLOR_HWHITE, 0, col);
	cct_showstr(x + 2 + col * 2, y+line+1, "╝", COLOR_HWHITE, 0);
   //框架
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			if (shuzu[i][j] == 0)
				cct_showstr(x + 2 + 2*j ,y + 1 + i, "〇", COLOR_HWHITE, COLOR_HWHITE);
			else
				cct_showstr(x + 2 + 2*j,y + 1 +  i , "〇", shuzu[i][j], COLOR_HWHITE);
		}
	}
	cct_setcolor();
	cout << endl << endl;
}

void g_init_c(int x, int y, int line, int col)
{
	int nx, ny;
	cct_showstr(x, y, "╔", COLOR_HWHITE, 0);
	cct_showstr(x + 2, y, "═╦", COLOR_HWHITE, 0, col-1);
	cct_getxy(nx,ny);
	cct_showstr(nx, ny, "═╗", COLOR_HWHITE, 0);
	for (int i = 0; i < 2*line-1; i++) {
		if (i % 2 == 0) {
			cct_showstr(x, y + 1+i, "║  ", COLOR_HWHITE, 0, col);
			cct_getxy(nx, ny);
			cct_showstr(nx, ny, "║", COLOR_HWHITE, 0);
		}
		else {
			cct_showstr(x, y + 1 + i, "╠", COLOR_HWHITE, 0);
			cct_showstr(x+2, y + 1 + i, "═╬", COLOR_HWHITE, 0,col-1);
			cct_getxy(nx, ny);
			cct_showstr(nx, ny, "═╣", COLOR_HWHITE, 0);
		}
	}
	cct_showstr(x, y+2*line, "╚", COLOR_HWHITE, 0);
	cct_showstr(x + 2, y+2*line, "═╩", COLOR_HWHITE, 0, col - 1);
	cct_getxy(nx, ny);
	cct_showstr(nx, ny, "═╝", COLOR_HWHITE, 0);
}

void g_init_c2(int x, int y, int shuzu[9][9], int line, int col)
{
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			if (shuzu[i][j] != 0)
				cct_showstr(x + 2 + 4 * j, y + 1 + 2 * i, "〇", shuzu[i][j], COLOR_HWHITE);
		}
	}
	cct_setcolor();
}
//移动一格
void move_a_step(int nr, int nc, int er, int ec,int color)
{
	int dr = er - nr, dc = ec - nc;
	if (dr) {
		Sleep(200);
		cct_showstr(4 * nc + 2, 2 * nr + 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
		cct_showstr(4 * nc + 2 , 2 * nr + 2+dr, "◎",color, COLOR_HWHITE);
		Sleep(200);
		cct_showstr(4 * nc + 2, 2 * nr + 2+dr, "═", COLOR_HWHITE, 0);
		cct_showstr(4 * nc + 2, 2 * nr + 2+2*dr, "◎", color, COLOR_HWHITE);
	}
	if (dc) {
		Sleep(200);
		cct_showstr(4 * nc + 2, 2 * nr + 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
		cct_showstr(4 * nc + 2+2*dc, 2 * nr + 2, "◎", color, COLOR_HWHITE);
		Sleep(200);
		cct_showstr(4 * nc + 2+2*dc, 2 * nr + 2, "║", COLOR_HWHITE, 0);
		cct_showstr(4 * nc + 2+4*dc,2 * nr + 2, "◎", color, COLOR_HWHITE);
	}
}
//图形移动一步
bool move_path(int line, int col, int shuzu[][9],int flag2)
{
	int X = 0, Y = 0;
	int ret, maction, flag = 0;
	int keycode1, keycode2;
	static int start_c, start_r, end_c, end_r;
	char result[9][9] = { };
	int path_x[100], path_y[100], path_length = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			result[i][j] = '0';
		}
	}
	while (1) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(0, 2 * line + 2);
			cout << "[当前光标] ";
			if ((X % 4 == 2 || X % 4 == 3) && X < (2 + 4 * col) && Y % 2 == 0 && Y>0 && Y < (2 + line * 2)) {//鼠标有效
				int nc = (X + 2) / 4;
				int nl = Y / 2;
				cout << (char)('A' + nl - 1) << "行" << nc << "列            ";
				if (maction == MOUSE_LEFT_BUTTON_CLICK && shuzu[nl - 1][nc - 1]) {
					if (flag == 1)
						cct_showstr(start_c * 4 + 2, start_r * 2 + 2, "〇", shuzu[start_r][start_c], COLOR_HWHITE);
					if (flag2)
						cct_showstr(end_c * 4 + 2, end_r * 2 + 2, "〇", shuzu[end_r][end_c], COLOR_HWHITE);
					start_c = nc - 1;
					start_r = nl - 1;
					cct_showstr(nc * 4 - 2, nl * 2, "◎", shuzu[start_r][start_c], COLOR_HWHITE);
					cct_setcolor();
					flag = 1;
				}
				if (maction == MOUSE_LEFT_BUTTON_CLICK && !shuzu[nl - 1][nc - 1] && flag == 1) {
					end_c = nc - 1;
					end_r = nl - 1;
					ret = findway(shuzu, result, start_r, start_c, end_r, end_c, line, col, path_x, path_y, path_length);
					if (ret) {
						cct_gotoxy(0, 2 * line + 2);
						cout << "[提示]可以从["<< (char)('A' + start_r)<< start_c+1<<"]移动到["<< (char)('A' + end_r)<< end_c + 1<<"]";
						for (int i = path_length - 1; i > 0; i--)
							move_a_step(path_x[i], path_y[i], path_x[i - 1], path_y[i - 1], shuzu[start_r][start_c]);
						shuzu[end_r][end_c] = shuzu[start_r][start_c];
						shuzu[start_r][start_c] = 0;
						cct_setcolor();
						cct_gotoxy(0, 2 * line + 2);
						return 1;
					}
					else {
						cct_gotoxy(0, 2 * line + 2);
						cout << "[错误] 无法从[" << (char)('A' + start_r) << start_c + 1 << "]移动到[" << (char)('A' + end_r) << end_c + 1 << "]";
					}
				}
				if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
					cct_gotoxy(0, 2 * line + 2);
					return  0;
				}
			}
			else
				cout << "位置非法            ";
		}
	}
}

void tongji(int shuzu[][9],int line,int col,int ret[8])
{
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			ret[shuzu[i][j]]++;
		}
	}
}
void column_1(int shuzu[][9],int rand3[], int score,int line,int col,int x = 40, int y = 1)
{
	cct_showstr(x, y,     "╔═════╗", COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(x, y + 1, "║得分：    ║", COLOR_HWHITE, COLOR_BLACK);
	cct_showint(x + 8, y + 1, score, COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(x, y+2,   "╚═════╝", COLOR_HWHITE, COLOR_BLACK);

	cct_showstr(x, y + 4, "╔═╦═╦═╗", COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(x, y + 5, "║  ║  ║  ║", COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(x, y + 6, "╚═╩═╩═╝", COLOR_HWHITE, COLOR_BLACK);
	cct_showstr(x+2, y + 5, "〇", rand3[0], COLOR_HWHITE);
	cct_showstr(x + 6, y + 5, "〇", rand3[1], COLOR_HWHITE);
	cct_showstr(x + 10, y + 5, "〇", rand3[2], COLOR_HWHITE);

}

void column_2(int shuzu[][9], int xiaochu[8], int score, int line, int col, int x = 40, int y = 1)
{
	int ret[8] = { 0 };
	tongji(shuzu, line, col, ret);
	cct_showstr(x, y + 8, "╔════════════╗", COLOR_HWHITE, COLOR_BLACK);
	for (int i = 0; i < 8; i++)
	{
		cct_showstr(x, y + 9 + i, "║                        ║", COLOR_HWHITE, COLOR_BLACK);
		if (i == 0)
			cct_showstr(x + 2, y + 9 + i, "〇", COLOR_HWHITE, COLOR_HWHITE);
		else {
			cct_showstr(x + 2, y + 9 + i, "〇", i, COLOR_HWHITE);
		}
		cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
		cout << setfill('0') << setw(2) << ret[i] << "/(" << fixed << setprecision(2) << setw(5) << ((double)ret[i] / (line * col)) * 100 << "%) 消除-"<<xiaochu[i];
	};
	cct_showstr(x, y + 17, "╚════════════╝", COLOR_HWHITE, COLOR_BLACK);
	cct_setcolor();
}
void choice_d()
{
	int line, col;
	int shuzu[9][9] = { 0 };
	cct_cls();
	input(line, col);
	cout << endl;
	cout << "初始数组：" << endl;
	init(shuzu, line, col, 5);;
	print_shuzu(shuzu, line, col);
	cout << endl<<"按回车键显示图形...";
	while (_getch() != '\r')
		;
	g_init(0, 1, shuzu, line, col);
}

void choice_e()
{
	int line, col;
	int shuzu[9][9] = { 0 };
	cct_cls();
	input(line, col);
	cout << endl;
	cout << "初始数组：" << endl;
	init(shuzu, line, col, 5);;
	print_shuzu(shuzu, line, col);
	cout << endl << "按回车键显示图形...";
	while (_getch() != '\r')
		;
	g_init_c(0, 1, line, col);
	g_init_c2(0, 1, shuzu, line, col);
	cct_gotoxy(0, 2 * line + 2);
}

void choice_f()
{
	cct_enable_mouse();
	int line, col, n;
    bool flag=0;
	int shuzu[9][9] = { 0 };
	cct_cls();
	input(line, col);
	n = int(line * col * 0.6);
	init(shuzu, line, col, n);
	cct_setcursor(CURSOR_INVISIBLE);
	cct_showstr(0, 0, "鼠标移动，左键单击选择，右键退出");
	g_init_c(0, 1 , line, col);
	g_init_c2(0, 1, shuzu, line, col);
	move_path(line, col, shuzu,flag=0);
}

void choice_g()
{
	cct_enable_mouse();
	int line, col,score=0;
	int shuzu[9][9] = { 0 };
	int rand3[3] = { 0 }, xiaochu[8] = { 0 };
	bool ret_full = 1,flag2=0;
	cct_cls();
	input(line, col);
	init(shuzu, line, col, 5);
	cct_setcursor(CURSOR_INVISIBLE);
	cct_showstr(0, 0, "鼠标移动，左键单击选择，右键退出");
	g_init_c(0, 1, line, col);
	g_init_c2(0, 1, shuzu, line, col);
	while (1) {
		int n_score;
		for (int i = 0; i < 3; i++) {
			rand3[i] = rand() % 7 + 1;
		}
		if (ret_full == 0)
			break;
		column_1(shuzu, rand3, score, line, col);
		column_2(shuzu, xiaochu, score, line, col);

		if (move_path(line, col, shuzu, flag2)) {
			flag2= 0;
			n_score = cal_score(shuzu, line, col, xiaochu, 1);
			score += n_score;
			if (!n_score) {
				ret_full = generate(shuzu, rand3, line, col, 1);
				n_score = cal_score(shuzu, line, col, xiaochu, 1);
				score += n_score;
				flag2 = 1;
			}
		}
		else
			return;
	}
	cct_gotoxy(0, 2 * line + 2);
	cct_setcolor();
	return;
}

