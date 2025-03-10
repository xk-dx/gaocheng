/* 2354218 肖佳彤 计科 */
#include "90-b2.h"
//判断结束
int judge_end()
{
	
	cout << "本小题结束，请输入End继续...";
	int x, y;
	cct_getxy(x, y);
	while (1) {
		char end[4] = { 0 };
		cin.getline(end, 4);
		for (int i = 0; i < 3; i++) {
			if (end[i] > 'a' && end[i] < 'z')
				end[i] = end[i] - 32;
		}
		if (strcmp(end, "END") == 0) {
			return 0;
		}
		else {
			cct_showstr(0, y+1, "输入错误，请重新输入", 0,7 , 1);
			cin.clear();
			cct_gotoxy(x, y);
			cout << "            ";
			cct_gotoxy(x, y);
		}
	}
}
//输入函数
void input(int &line,int &col)
{
	while (true)
	{
		cout << "请输入行数(7 - 9)：" << endl;
		cin >> line;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (line <= 9 && line >= 7) {
			break;
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	while (true)
	{
		cout << "请输入列数(7 - 9)：" << endl;
		cin >> col;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (col <= 9 && col >= 7) {
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
	}
}

//内部数组，初始生成n小球
void init(int shuzu[9][9], int line, int col, int n)
{
	int r_line, r_col, r_value, i = 0;
	while (i < n)
	{
		r_line = rand() % line;
		r_col = rand() % col;
		r_value = rand() % 7;
		if (shuzu[r_line][r_col] == 0) {
			shuzu[r_line][r_col] = r_value + 1;
			i++;
		}
	}
}
//生成3个小球,并判断是否数组满，满则返回0
bool generate(int shuzu[][9], int rand3[], int line, int col,int g)
{
	int r_line, r_col, k = 0;
	bool flag = 0;
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			if (shuzu[i][j] == 0) {
				flag = 1;
			}
		}
	}
	while (k < 3 && flag)
	{
		flag = 0;
		for (int i = 0; i < line; i++) {
			for (int j = 0; j < col; j++) {
				if (shuzu[i][j] == 0) {
					flag = 1;
				}
			}
		}
		if (flag) {
			r_line = rand() % line;
			r_col = rand() % col;
			if (shuzu[r_line][r_col] == 0) {
				shuzu[r_line][r_col] = rand3[k];
				if (g) {
					cct_showstr(4 * r_col + 2, 2 * r_line + 2, "〇", rand3[k], COLOR_HWHITE);
				}
				k++;
			}
		}
	}
	flag = 0;
	for (int i = 0; i < line; i++) {
		for (int j = 0; j < col; j++) {
			if (shuzu[i][j] == 0) {
				flag = 1;
			}
		}
	}
	return flag;
}

//输入球坐标，0起始，1目的
void input_ball(int shuzu[][9], int line, int col, int& ball_x, int& ball_y, int io)
{
	while (1) {
		if (io == 0)
			cout << "请以字母+数字形式[例：c2]输入要移动球的矩阵坐标：";
		else
			cout << "请以字母+数字形式[例：c2]输入要移动球的目的坐标：";
		int x, y;
		cct_getxy(x, y);
		char start[3] = { 0 };

		cin.getline(start, 3);
		if (start[0] >= 'a' && start[0] <= 'z')
			start[0] = start[0] - 32;

		if (start[0] >= 'A' && start[0] <= ('A' + line - 1) && start[1] >= '1' && start[1] <= '0' + col) {//格式判断
			int n_line = start[0] - 'A', n_col = start[1] - '1';
			if (shuzu[n_line][n_col] != 0 && io == 0 || shuzu[n_line][n_col] == 0 && io == 1) {
				cout << "输入为" << start[0] << "行" << start[1] << "列" << endl;
				ball_x = n_line;
				ball_y = n_col;
				break;
			}
			else if (io == 0) {
				cout << "起始位置为空，请重新输入.       " << endl;
				continue;
			}
			else if (io == 1) {
				cout << "目标位置非空，请重新输入.       " << endl;
				continue;
			}
		}
		else {
			cct_showstr(0, y + 1, "输入错误，请重新输入.", 0, 7, 1);
			cin.clear();
			cct_gotoxy(x, y);
			cout << "            ";
			cct_gotoxy(0, y);
		}
	}
}
//寻路算法,返回是否存在路径以及结果数组，记录路径
bool findway(int shuzu[][9], char result[][9], int sr, int sc, int er, int ec, int line, int col, int path_x[], int path_y[], int& path_length) {
	int dr[] = { -1, 1, 0, 0 };
	int dc[] = { 0, 0, -1, 1 };
	bool visited[9][9] = { false };
	int queue_x[100], queue_y[100];
	int front = 0, rear = 0; // 队列的头尾指针
	int parent_x[9][9];
	int parent_y[9][9];
	for (int i = 0; i < line; ++i) {
		for (int j = 0; j < col; ++j) {
			parent_x[i][j] = -1;
			parent_y[i][j] = -1;
		}
	}
	queue_x[rear] = sr;
	queue_y[rear] = sc;
	rear++;
	visited[sr][sc] = true;

	while (front < rear) {
		int x = queue_x[front];
		int y = queue_y[front];
		front++;

		if (x == er && y == ec) {
			int px = x, py = y;
			while (px != -1 && py != -1) {
				path_x[path_length] = px;
				path_y[path_length] = py;
				path_length++;
				int tmp_x = parent_x[px][py];
				int tmp_y = parent_y[px][py];
				px = tmp_x;
				py = tmp_y;
			}
			return true;
		}

		for (int i = 0; i < 4; ++i) {
			int nr = x + dr[i];
			int nc = y + dc[i];

			if (nr >= 0 && nr < line && nc >= 0 && nc < col && !visited[nr][nc] && shuzu[nr][nc] == 0) {
				queue_x[rear] = nr;
				queue_y[rear] = nc;
				rear++;
				visited[nr][nc] = true;
				parent_x[nr][nc] = x;
				parent_y[nr][nc] = y;
			}
		}
	}
	return false;
}


//计算分数，并将连续5个以上置零，返回值是是否有计分活动
int cal_score(int shuzu[][9], int line, int col,int xiaochu[8],int g)
{
	int score = 0, flag1 = 0, flag2 = 0,count_total = 0,count1, count2, color;
	int i1, j1, i2, j2;;
	for (i1 = 0; i1 < line; ++i1) {
		for (j1 = 0; j1 <= col - 5; ++j1) {
			count1 = 1;
			if (shuzu[i1][j1] != 0) {
				while (j1 + count1 < col && shuzu[i1][j1 + count1] == shuzu[i1][j1]) 
					count1++;
				if (count1 >= 5) {
					count_total += count1;
					flag1 = 1;
					color = shuzu[i1][j1];
					break;
				}
			}
		}
		if (flag1)
			break;
	}//行
	for (j2 = 0; j2 < col; ++j2) {
		for (i2 = 0; i2 <= line - 5; ++i2) {
			count2 = 1;
			if (shuzu[i2][j2] != 0) {
				while (i2 + count2 < line && shuzu[i2 + count2][j2] == shuzu[i2][j2]) 
					count2++;
				if (count2 >= 5) {
					if (flag1)
						count_total = count_total + count2 - 1;
					else
						count_total += count2;
					flag2 = 1;
					color = shuzu[i2][j2];
					break;
				}
			}
			
		}
		if (flag2)
			break;
	}//列
	if (flag1) {
		for (int k = 0; k < count1; ++k) {
			shuzu[i1][j1 + k] = 0;
			if (g) {
				Sleep(20);
				cct_showstr(4 * (j1 + k) + 2, 2 * i1 + 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
			}
		}
	}
	if (flag2) {
		for (int k = 0; k < count2; ++k) {
			shuzu[i2 + k][j2] = 0;
			if (g) {
				Sleep(20);
				cct_showstr(4 * j2 + 2, 2 * (i2 + k) + 2, "  ", COLOR_HWHITE, COLOR_HWHITE);
			}
		}
	}
	//置零
	if (count_total) {
		xiaochu[color] += count_total;
		score = (count_total - 1) * (count_total - 2);
	}
	return score;
}
