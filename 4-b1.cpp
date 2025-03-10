/* 2354218 肖佳彤 计科 */
#include <iostream>
using namespace std;

/* 可根据需要添加相应的内容 */

/***************************************************************************
  函数名称：daxie
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* 不允许对本函数做任何修改 */
	switch (num) {
		case 0:
			if (flag_of_zero)	//此标记什么意思请自行思考
				cout << "零";
			break;
		case 1:
			cout << "壹";
			break;
		case 2:
			cout << "贰";
			break;
		case 3:
			cout << "叁";
			break;
		case 4:
			cout << "肆";
			break;
		case 5:
			cout << "伍";
			break;
		case 6:
			cout << "陆";
			break;
		case 7:
			cout << "柒";
			break;
		case 8:
			cout << "捌";
			break;
		case 9:
			cout << "玖";
			break;
		default:
			cout << "error";
			break;
	}
}

/* 可根据需要自定义其它函数(也可以不定义) */

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
	/* 按需完成 */
	double a;
	cout << "请输入[0-100亿)之间的数字:" << endl;
	cin >> a;
	int sy = int(a / 1000000000) % 10;
	int yi = int(a / 100000000) % 10;
	int qw = int(a / 10000000) % 10;
	int bw = int(a / 1000000) % 10;
	int sw = int(a / 100000) % 10;
	int w = int(a / 10000) % 10;
	int q = int(a / 1000) % 10;
	int b = int(a / 100) % 10;
	a /= 100;
	a -= int(a);
	a *= 10000;
	a += 0.001;
	int s = int(a / 1000) % 10;
	int y = int(a / 100) % 10;
	int j = int(a / 10) % 10;
	int f = int(a) % 10;

	cout << "大写结果是:" << endl;
	int flag_of_zero = 0;
	int f_y=0;
	int f_w = 0;
	daxie(sy, flag_of_zero);
	if (sy != 0)
		cout << "拾";
	daxie(yi, flag_of_zero);
	if (sy != 0 || yi != 0) {
		f_y = 1;
		cout << "亿";
	}

	//qianwan 
	if (bw != 0 &&f_y )
		flag_of_zero = 1;
	daxie(qw, flag_of_zero);
	if (qw != 0)
	    cout << "仟";
	flag_of_zero = 0;

	//baiwan
	if (sw !=0 && (f_y+qw>0))
		flag_of_zero = 1;
	daxie(bw, flag_of_zero);
	if (bw != 0)
		cout << "佰";
	flag_of_zero = 0;

	//shiwan 
	if (w!= 0 && (f_y+qw+bw>0))
		flag_of_zero = 1;
	daxie(sw, flag_of_zero);
	if (sw != 0)
		cout << "拾";
	flag_of_zero = 0;

	//wan
	daxie(w, flag_of_zero);
	if (qw + bw + sw + w > 0) {
		f_w = 1;
		cout << "万";
	}

	//qian 
	if (b != 0&& (f_y||f_w))
		flag_of_zero = 1;
	daxie(q, flag_of_zero);
	if (q != 0)
		cout << "仟";
	flag_of_zero = 0;

	//bai
	if (s != 0 && (f_y + f_w+q>0))
		flag_of_zero = 1;
	daxie(b, flag_of_zero);
	if (b != 0)
		cout << "佰";
	flag_of_zero = 0;

	//shi
	if (y != 0 && (f_y + f_w+q+b>0))
		flag_of_zero = 1;
	daxie(s, flag_of_zero);
	if (s != 0)
		cout << "拾";
	flag_of_zero = 0;

	int f_z = 0;
	//yuan
	if ((f_y+f_w+q+b+s+j+f)==0)
		flag_of_zero = 1;
	daxie(y, flag_of_zero);
	if ((f_y + f_w + q + b + s + y) > 0) {
		f_z = 1;
		cout << "圆";
	}
	if ((f_y + f_w + q + b + s + j + f) == 0)
		cout << "圆";
	flag_of_zero = 0;

	//jiao
	if (f!=0&&f_z!=0)
		flag_of_zero = 1;
	daxie(j, flag_of_zero);
	if (j != 0)
		cout << "角";
	flag_of_zero = 0;

	//fen
	daxie(f, flag_of_zero);
	if (f != 0)
		cout << "分";
	else if (f == 0 )
		cout << "整";
	cout << endl;

	return 0;
}