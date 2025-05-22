/* 计科 2354218 肖佳彤 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <iomanip>
#include <conio.h>
#include "cmd_console_tools.h"
#include "Windows.h"
char menu_h();
void choice_1();
void choice_2();
void choice_3();
void choice_4();
void choice_5();
void choice_6();
void choice_7();
void choice_8();
void choice_9();
void hanoi(char src, char tmp, char dst, int n, int choice);
void op(char src, char tmp, char dst, int n, int choice);
void Input_h(char* src, char* tmp, char* dst, int* n, int if_speed);
void push_pop(char src, char dst);
void print_v(char src, char dst, int speed,int x,int y);
void print_v_init(char src, char dst, int speed, int x, int y);
void print_w();
void init(int n, char src);
void move_plate(char src, char dst);


const int col_h = 12;
const int base_y = 15;
const int a_middle = 12;
const int b_middle = 44;
const int c_middle = 76;