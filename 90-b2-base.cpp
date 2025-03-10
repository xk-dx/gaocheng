/* 2354218 肖佳彤 计科 */
#include "90-b2.h"

//打印内部数组
void print_shuzu(int shuzu[9][9], int line, int col)
{
	cout << "  |";
	int x, y;
	for (int i = 0; i < col; i++) {
		cout << "  " << i + 1;
	}
	cout << endl;
	cout << "--+";
	cct_getxy(x, y);
	cct_showstr(x, y, "---", 0, 7, col);
	cout << "-" << endl;
	for (int i = 0; i < line; i++) {
		cout << (char)('A' + i) << " |";
		for (int j = 0; j < col; j++) {
			cout << "  ";
			cct_getxy(x, y);
			if (shuzu[i][j] == 0) {
				cout << '0';
			}
			else {
				cct_showch(x, y, '0' + shuzu[i][j], COLOR_HYELLOW, shuzu[i][j]);
				cct_setcolor(0, 7);
			}
		}
		cout << endl;
	}
}

//打印结果数组
void print_shuzu_r(char result[9][9], int line, int col)
{
	cout << "  |";
	int x, y;
	for (int i = 0; i < col; i++) {
		cout << "  " << i + 1;
	}
	cout << endl;
	cout << "--+";
	cct_getxy(x, y);
	cct_showstr(x, y, "---", 0, 7, col);
	cout << "-" << endl;
	for (int i = 0; i < line; i++) {
		cout << (char)('A' + i) << " |";
		for (int j = 0; j < col; j++) {
			cout << "  ";
			cout << result[i][j];
		}
		cout << endl;
	}
}
//打印内部数组移动路径
void print_shuzu_path(int shuzu[9][9], char result[9][9], int line, int col)
{
	cout << "  |";
	int x, y;
	for (int i = 0; i < col; i++) {
		cout << "  " << i + 1;
	}
	cout << endl;
	cout << "--+";
	cct_getxy(x, y);
	cct_showstr(x, y, "---", 0, 7, col);
	cout << "-" << endl;
	for (int i = 0; i < line; i++) {
		cout << (char)('A' + i) << " |";
		for (int j = 0; j < col; j++) {
			cout << "  ";
			cct_getxy(x, y);
			if (result[i][j] == '*') {
				cct_showch(x, y, '0' + shuzu[i][j], COLOR_HYELLOW, COLOR_BLUE);
				cct_setcolor();
			}
			else {
				cout << shuzu[i][j];
			}
		}
		cout << endl;
	}
}


void choice_a()
{
	int line, col;
	int shuzu[9][9] = { 0 };
	cct_cls();
	input(line, col);
	cout << endl;
	cout << "初始数组：" << endl;
	init(shuzu, line, col, 5);
	//cin.ignore(65536, '\n');
	print_shuzu(shuzu, line, col);
}

void choice_b()
{
	int line, col, n;
	int start_x, start_y, end_x, end_y;
	int shuzu[9][9] = { 0 };
	char result[9][9] = { };
	int path_x[100], path_y[100], path_length = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			result[i][j] = '0';
		}
	}
	cct_cls();
	input(line, col);
	n = int(line * col * 0.6);
	cout << endl;
	cout << "当前数组：" << endl;
	init(shuzu, line, col, n);
	print_shuzu(shuzu, line, col);
	cout << endl << "下3个彩球的颜色分别是：";
	cout << rand() % 7 + 1 << " " << rand() % 7 + 1 << " " << rand() % 7 + 1 << endl;
	input_ball(shuzu, line, col, start_x, start_y, 0);
	input_ball(shuzu, line, col, end_x, end_y, 1);   //输入球起始坐标
	int ret = findway(shuzu, result, start_x, start_y, end_x, end_y, line, col, path_x, path_y, path_length);
	if (ret) {
		cout << endl << "查找结果数组：" << endl;;
		print_shuzu_r(result, line, col);
		cout << endl << "移动路径(不同色标识)：" << endl;
		print_shuzu_path(shuzu, result, line, col);
	}
	else {
		cout << "无法找到移动路径" << endl;
	}
	cout << endl;
}

void choice_c()
{
	int line, col, score = 0;
	int shuzu[9][9] = { 0 }, xiaochu[8] = {0};
	char result[9][9] = { };
	int path_x[100], path_y[100], path_length = 0;
	int rand3[3] = { 0 };
	bool ret_full = 1;
	cct_cls();
	input(line, col);
	init(shuzu, line, col, 5);
	while (1) {
		int start_x, start_y, end_x, end_y, n_score;
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				result[i][j] = '0';
			}
		}
		for (int i = 0; i < 3; i++) {
			rand3[i] = rand() % 7 + 1;
		}//生成随机3小球
		while (1) {
			cout << endl;
			cout << "当前数组：" << endl;;
			print_shuzu(shuzu, line, col);
			cout << endl << "下3个彩球的颜色分别是：";
			for (int i = 0; i < 3; i++) {
				cout << rand3[i] << " ";
			}//输出随机3小球
			cout << endl;
			if (ret_full == 0)
				break;
			input_ball(shuzu, line, col, start_x, start_y, 0);
			input_ball(shuzu, line, col, end_x, end_y, 1);     //输入球起始坐标
			int ret = findway(shuzu, result, start_x, start_y, end_x, end_y, line, col, path_x, path_y, path_length);
			if (ret) {
				shuzu[end_x][end_y] = shuzu[start_x][start_y];
				shuzu[start_x][start_y] = 0;
				n_score = cal_score(shuzu, line, col, xiaochu);
				score += n_score;
				if (!n_score)
					ret_full = generate(shuzu, rand3, line, col);
				cout << endl << "移动后的数组(不同色标识)：" << endl;
				print_shuzu(shuzu, line, col);
				cout << endl << "本次得分：" << n_score << "总得分：" << score << endl;
				break;
			}
			else {
				cout << "无法找到移动路径" << endl;
			}
		}
		if (ret_full == 0)
			break;
		else
			cout << endl;
	}
	cct_setcolor();
	cout << "无空位可移动，游戏结束!" << endl;
}
