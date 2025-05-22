/* 计科 2354218 肖佳彤 */
#include <iostream>
#include "cmd_console_tools.h"
#include "hanoi.h"
using namespace std;

/* ----------------------------------------------------------------------------------

     本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

     本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{

	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	char choice;
	while (1) {
		choice = menu_h();
		if (choice == '0') { 
			cct_gotoxy(0, 37);
			return 0;
		}
		if (choice == '1')
			choice_1();		
		else if (choice == '2')
			choice_2();
	    else if (choice == '3')
			choice_3();
		else if (choice == '4')
			choice_4();
		else if (choice == '5')
			choice_5();
		else if (choice == '6')
			choice_6();
		else if (choice == '7')
			choice_7();
		else if (choice == '8')
			choice_8();
		else if (choice == '9')
			choice_9();
	}

	return 0;
}
