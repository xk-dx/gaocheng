/* 2354218 Ф��ͮ �ƿ� */
#include "90-b2.h"
//�жϽ���
int judge_end()
{
	
	cout << "��С�������������End����...";
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
			cct_showstr(0, y+1, "�����������������", 0,7 , 1);
			cin.clear();
			cct_gotoxy(x, y);
			cout << "            ";
			cct_gotoxy(x, y);
		}
	}
}
//���뺯��
void input(int &line,int &col)
{
	while (true)
	{
		cout << "����������(7 - 9)��" << endl;
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
		cout << "����������(7 - 9)��" << endl;
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

//�ڲ����飬��ʼ����nС��
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
//����3��С��,���ж��Ƿ������������򷵻�0
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
					cct_showstr(4 * r_col + 2, 2 * r_line + 2, "��", rand3[k], COLOR_HWHITE);
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

//���������꣬0��ʼ��1Ŀ��
void input_ball(int shuzu[][9], int line, int col, int& ball_x, int& ball_y, int io)
{
	while (1) {
		if (io == 0)
			cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ���ľ������꣺";
		else
			cout << "������ĸ+������ʽ[����c2]����Ҫ�ƶ����Ŀ�����꣺";
		int x, y;
		cct_getxy(x, y);
		char start[3] = { 0 };

		cin.getline(start, 3);
		if (start[0] >= 'a' && start[0] <= 'z')
			start[0] = start[0] - 32;

		if (start[0] >= 'A' && start[0] <= ('A' + line - 1) && start[1] >= '1' && start[1] <= '0' + col) {//��ʽ�ж�
			int n_line = start[0] - 'A', n_col = start[1] - '1';
			if (shuzu[n_line][n_col] != 0 && io == 0 || shuzu[n_line][n_col] == 0 && io == 1) {
				cout << "����Ϊ" << start[0] << "��" << start[1] << "��" << endl;
				ball_x = n_line;
				ball_y = n_col;
				break;
			}
			else if (io == 0) {
				cout << "��ʼλ��Ϊ�գ�����������.       " << endl;
				continue;
			}
			else if (io == 1) {
				cout << "Ŀ��λ�÷ǿգ�����������.       " << endl;
				continue;
			}
		}
		else {
			cct_showstr(0, y + 1, "�����������������.", 0, 7, 1);
			cin.clear();
			cct_gotoxy(x, y);
			cout << "            ";
			cct_gotoxy(0, y);
		}
	}
}
//Ѱ·�㷨,�����Ƿ����·���Լ�������飬��¼·��
bool findway(int shuzu[][9], char result[][9], int sr, int sc, int er, int ec, int line, int col, int path_x[], int path_y[], int& path_length) {
	int dr[] = { -1, 1, 0, 0 };
	int dc[] = { 0, 0, -1, 1 };
	bool visited[9][9] = { false };
	int queue_x[100], queue_y[100];
	int front = 0, rear = 0; // ���е�ͷβָ��
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


//�����������������5���������㣬����ֵ���Ƿ��мƷֻ
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
	}//��
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
	}//��
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
	//����
	if (count_total) {
		xiaochu[color] += count_total;
		score = (count_total - 1) * (count_total - 2);
	}
	return score;
}
