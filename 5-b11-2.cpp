/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <string>
using namespace std;

const char chnstr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/

void daxie(int num, int flag_of_zero)
{
	char tmp[10];
	tmp[0] = chnstr[num * 2];
	tmp[1] = chnstr[num * 2 + 1];
	tmp[2] = '\0';
	if (num)
		result = result + tmp;
	else
		if (flag_of_zero)
			result = result + tmp;
}
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	double a;
	while (1)
	{
		cout << "请输入[0-100亿)之间的数字: " << endl;
		cin >> a;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (a < 0.0 || a>1e10)
		{
			continue;
		}
		break;
	}
	int sy = (int)(a / 1000000000) % 10;
	int yi = (int)(a / 100000000) % 10;
	int qw = (int)(a / 10000000) % 10;
	int bw = (int)(a / 1000000) % 10;
	int sw = (int)(a / 100000) % 10;
	int w = (int)(a / 10000) % 10;
	int q = (int)(a / 1000) % 10;
	int b = (int)(a / 100) % 10;
	a /= 100;
	a -= (int)(a);
	a *= 10000;
	a += 0.001;
	int s = (int)(a / 1000) % 10;
	int y = (int)(a / 100) % 10;
	int j = (int)(a / 10) % 10;
	int f = (int)(a) % 10;

	int flag_of_zero = 0;
	int f_y = 0;
	int f_w = 0;
	daxie(sy, flag_of_zero);
	if (sy != 0) {
		result = result + "拾";
	}
	daxie(yi, flag_of_zero);
	if (sy != 0 || yi != 0) {
		f_y = 1;
		result = result + "亿";
	}

	//qianwan 
	if (bw != 0 && f_y)
		flag_of_zero = 1;
	daxie(qw, flag_of_zero);
	if (qw != 0) {
		result = result + "仟";
	}
	flag_of_zero = 0;

	//baiwan
	if (sw != 0 && (f_y + qw > 0))
		flag_of_zero = 1;
	daxie(bw, flag_of_zero);
	if (bw != 0) {
		result = result + "佰";
	}
	flag_of_zero = 0;

	//shiwan 
	if (w != 0 && (f_y + qw + bw > 0))
		flag_of_zero = 1;
	daxie(sw, flag_of_zero);
	if (sw != 0) {
		result = result + "拾";
	}
	flag_of_zero = 0;

	//wan
	daxie(w, flag_of_zero);
	if (qw + bw + sw + w > 0) {
		f_w = 1;
		result = result + "万";
	}

	//qian 
	if (b != 0 && (f_y || f_w))
		flag_of_zero = 1;
	daxie(q, flag_of_zero);
	if (q != 0) {
		result = result + "仟";
	}
	flag_of_zero = 0;

	//bai
	if (s != 0 && (f_y + f_w + q > 0))
		flag_of_zero = 1;
	daxie(b, flag_of_zero);
	if (b != 0) {
		result = result + "佰";
	}
	flag_of_zero = 0;

	//shi
	if (y != 0 && (f_y + f_w + q + b > 0))
		flag_of_zero = 1;
	daxie(s, flag_of_zero);
	if (s != 0) {
		result = result + "拾";
	}
	flag_of_zero = 0;

	int f_z = 0;
	//yuan
	if ((f_y + f_w + q + b + s + j + f) == 0)
		flag_of_zero = 1;
	daxie(y, flag_of_zero);
	if ((f_y + f_w + q + b + s + y) > 0) {
		f_z = 1;
		result = result + "圆";
	}
	else if ((f_y + f_w + q + b + s + j + f) == 0) {
		result = result + "圆";
	}
	flag_of_zero = 0;

	//jiao
	if (f != 0 && f_z != 0)
		flag_of_zero = 1;
	daxie(j, flag_of_zero);
	if (j != 0) {
		result = result + "角";
	}
	flag_of_zero = 0;

	//fen
	daxie(f, flag_of_zero);
	if (f != 0) {
		result = result + "分";
	}
	else if (f == 0) {
		result = result + "整";
	}
	cout<<"大写结果是"<<endl;
    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，其它地方不允许以任何形式对大写结果进行全部/部分输出 */
    return 0;
}
