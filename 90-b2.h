#pragma once
#include <iostream>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "cmd_console_tools.h"
#include <iomanip>
using namespace std;

int judge_end();
void input(int& line, int& col);

void print_shuzu(int shuzu[9][9], int line, int col);
void init(int shuzu[9][9], int line, int col,int n);
void input_ball(int shuzu[][9], int line, int col, int& ball_x, int& ball_y, int io);
void print_shuzu_r(char shuzu[9][9], int line, int col); bool findway(int shuzu[][9], char result[][9], int sr, int sc, int er, int ec, int line, int col, int path_x[], int path_y[], int& path_length);
void print_shuzu_path(int shuzu[9][9], char result[9][9], int line, int col);
bool generate(int shuzu[][9], int rand3[], int line, int col, int g=0);
int cal_score(int shuzu[][9], int line, int col, int xiaochu[8],int g=0);

void choice_a();
void choice_b();
void choice_c();
void choice_d();
void choice_e();
void choice_f();
void choice_g();

