/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
using namespace std;

/* �ɸ�����Ҫ�����Ӧ������ */

/***************************************************************************
  �������ƣ�daxie
  ��    �ܣ������д��0~9
  ���������
  �� �� ֵ��
  ˵    �������������⣬�������κκ�����������㡱-������!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
	/* ������Ա��������κ��޸� */
	switch (num) {
		case 0:
			if (flag_of_zero)	//�˱��ʲô��˼������˼��
				cout << "��";
			break;
		case 1:
			cout << "Ҽ";
			break;
		case 2:
			cout << "��";
			break;
		case 3:
			cout << "��";
			break;
		case 4:
			cout << "��";
			break;
		case 5:
			cout << "��";
			break;
		case 6:
			cout << "½";
			break;
		case 7:
			cout << "��";
			break;
		case 8:
			cout << "��";
			break;
		case 9:
			cout << "��";
			break;
		default:
			cout << "error";
			break;
	}
}

/* �ɸ�����Ҫ�Զ�����������(Ҳ���Բ�����) */

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	/* ������� */
	double a;
	cout << "������[0-100��)֮�������:" << endl;
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

	cout << "��д�����:" << endl;
	int flag_of_zero = 0;
	int f_y=0;
	int f_w = 0;
	daxie(sy, flag_of_zero);
	if (sy != 0)
		cout << "ʰ";
	daxie(yi, flag_of_zero);
	if (sy != 0 || yi != 0) {
		f_y = 1;
		cout << "��";
	}

	//qianwan 
	if (bw != 0 &&f_y )
		flag_of_zero = 1;
	daxie(qw, flag_of_zero);
	if (qw != 0)
	    cout << "Ǫ";
	flag_of_zero = 0;

	//baiwan
	if (sw !=0 && (f_y+qw>0))
		flag_of_zero = 1;
	daxie(bw, flag_of_zero);
	if (bw != 0)
		cout << "��";
	flag_of_zero = 0;

	//shiwan 
	if (w!= 0 && (f_y+qw+bw>0))
		flag_of_zero = 1;
	daxie(sw, flag_of_zero);
	if (sw != 0)
		cout << "ʰ";
	flag_of_zero = 0;

	//wan
	daxie(w, flag_of_zero);
	if (qw + bw + sw + w > 0) {
		f_w = 1;
		cout << "��";
	}

	//qian 
	if (b != 0&& (f_y||f_w))
		flag_of_zero = 1;
	daxie(q, flag_of_zero);
	if (q != 0)
		cout << "Ǫ";
	flag_of_zero = 0;

	//bai
	if (s != 0 && (f_y + f_w+q>0))
		flag_of_zero = 1;
	daxie(b, flag_of_zero);
	if (b != 0)
		cout << "��";
	flag_of_zero = 0;

	//shi
	if (y != 0 && (f_y + f_w+q+b>0))
		flag_of_zero = 1;
	daxie(s, flag_of_zero);
	if (s != 0)
		cout << "ʰ";
	flag_of_zero = 0;

	int f_z = 0;
	//yuan
	if ((f_y+f_w+q+b+s+j+f)==0)
		flag_of_zero = 1;
	daxie(y, flag_of_zero);
	if ((f_y + f_w + q + b + s + y) > 0) {
		f_z = 1;
		cout << "Բ";
	}
	if ((f_y + f_w + q + b + s + j + f) == 0)
		cout << "Բ";
	flag_of_zero = 0;

	//jiao
	if (f!=0&&f_z!=0)
		flag_of_zero = 1;
	daxie(j, flag_of_zero);
	if (j != 0)
		cout << "��";
	flag_of_zero = 0;

	//fen
	daxie(f, flag_of_zero);
	if (f != 0)
		cout << "��";
	else if (f == 0 )
		cout << "��";
	cout << endl;

	return 0;
}