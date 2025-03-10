/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：1、按需增加一个或多个函数（包括递归函数），但是所有增加的函数中不允许任何形式的循环
				 2、定义符号常量
				 3、定义const型变量

		不允许 ：1、定义全局变量
				 2、除print_tower之外的其他函数中不允许定义静态局部变量
   ----------------------------------------------------------------------------------- */
void printspaces(int number)
{
	if (number > 0)
	{
		cout << " ";
		printspaces(number - 1);
	}
}

void print_fronthalf(char end_ch,char limit)
{
	if (end_ch >= limit)
	{
		print_fronthalf(end_ch - 1,limit);
		cout << end_ch;
	}
}

void print_backhalf(char end_ch,char limit)
{
	if (end_ch >=limit)
	{
		cout << end_ch;
		print_backhalf(end_ch - 1,limit);
	}
}

   /***************************************************************************
	 函数名称：
	 功    能：打印字母塔
	 输入参数：
	 返 回 值：
	 说    明：形参按需设置
			   提示：有一个参数order，指定正序/倒序
   ***************************************************************************/


void print_tower(char c,int order,int number)//0正1倒序
{
	if (order == 0) {//正序
		if (c < 'A') 
			return;
		print_tower(c - 1,0,number + 1);
		printspaces(number);
		print_backhalf(c, 'B');
		print_fronthalf(c,'A');
		cout << endl;
	}
	if (order == 1) {//逆序
			if (c < 'A')
				return;
			printspaces(number);
			print_backhalf(c, 'B');
			print_fronthalf(c, 'A');
			cout << endl;
			print_tower(c - 1, 1, number + 1);
	}
}

char print_equal(char end_ch)
{
	int number = end_ch - 'A';
	if (number > 0)
		cout << print_equal(end_ch - 1) << "=";
	return '=';
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数中的...允许修改，其余位置不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效，为避免循环出现，不处理输入错误) */
	cout << "请输入结束字符(A~Z)" << endl;
	end_ch = getchar();			//读缓冲区第一个字符
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "结束字符不是大写字母" << endl;
		return -1;
	}
	
	/* 正三角字母塔(中间为A) */
	cout <<print_equal(end_ch) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "正三角字母塔(" << end_ch << "->A)" << endl;
	cout << print_equal(end_ch)<< endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch,0,0); //正序打印 A~结束字符 
	cout << endl;
	
	/* 倒三角字母塔(中间为A) */
	cout << print_equal(end_ch) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	cout << "倒三角字母塔(" << end_ch << "->A)" << endl;
	cout << print_equal(end_ch) << endl; /* 按字母塔最大宽度输出=(不允许用循环) */
	print_tower(end_ch, 1, 0); //逆序打印 A~结束字符 
	cout << endl;


	/* 合起来就是漂亮的菱形（中间为A） */
	cout << print_equal(end_ch) << endl;/* 按字母塔最大宽度输出= */
	cout << "菱形(" << end_ch << "->A)" << endl;
	cout << print_equal(end_ch) << endl;/* 按字母塔最大宽度输出= */
	print_tower(end_ch, 0, 0);   //打印 A~结束字符的正三角 
	print_tower(end_ch-1, 1, 1);  //打印 A~结束字符-1的倒三角 
	cout << endl;

	return 0;
}