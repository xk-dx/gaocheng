/* 2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
//�ɰ���������Ҫ��ͷ�ļ�

const char chnstr[] = "��Ҽ��������½��ƾ�"; /* ���������д "��" ~ "��" �ĵط���ֻ��������������ȡֵ */
char result[256];  /* ��result�⣬�����������κ���ʽ��ȫ�ֱ��� */

/* --���������Ҫ�ĺ��� --*/
void daxie(int num, int flag_of_zero)
{
		char tmp[10];
		tmp[0] = chnstr[num * 2];
		tmp[1] = chnstr[num * 2 + 1];
		tmp[2] = '\0';
		if (num)
		    strcat(result, tmp);
		else
			if (flag_of_zero)
				strcat(result, tmp);
}
/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main()
{
	double a;
	while (1)
	{
		printf("������[0-100��)֮�������: \n");
		int x = scanf("%lf", &a);
		if (x == 0)
		{
			while ((getchar()) != '\n' )
				;
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
	int f_y=0;
	int f_w = 0;
	daxie(sy, flag_of_zero);
	if (sy != 0) {
		strcat(result, "ʰ");
	}
	daxie(yi, flag_of_zero);
	if (sy != 0 || yi != 0) {
		f_y = 1;
		strcat(result, "��");
	}

	//qianwan 
	if (bw != 0 &&f_y )
		flag_of_zero = 1;
	daxie(qw, flag_of_zero);
	if (qw != 0) {
		strcat(result, "Ǫ");
	}
	flag_of_zero = 0;

	//baiwan
	if (sw !=0 && (f_y+qw>0))
		flag_of_zero = 1;
	daxie(bw, flag_of_zero);
	if (bw != 0) {
		strcat(result, "��");
	}
	flag_of_zero = 0;

	//shiwan 
	if (w!= 0 && (f_y+qw+bw>0))
		flag_of_zero = 1;
	daxie(sw, flag_of_zero);
	if (sw != 0) {
		strcat(result, "ʰ");
	}
	flag_of_zero = 0;

	//wan
	daxie(w, flag_of_zero);
	if (qw + bw + sw + w > 0) {
		f_w = 1;
		strcat(result, "��");
	}

	//qian 
	if (b != 0&& (f_y||f_w))
		flag_of_zero = 1;
	daxie(q, flag_of_zero);
	if (q != 0) {
		strcat(result, "Ǫ");
	}
	flag_of_zero = 0;

	//bai
	if (s != 0 && (f_y + f_w+q>0))
		flag_of_zero = 1;
	daxie(b, flag_of_zero);
	if (b != 0) {
		strcat(result, "��");
	}
	flag_of_zero = 0;

	//shi
	if (y != 0 && (f_y + f_w+q+b>0))
		flag_of_zero = 1;
	daxie(s, flag_of_zero);
	if (s != 0) {
		strcat(result, "ʰ");
	}
	flag_of_zero = 0;

	int f_z = 0;
	//yuan
	if ((f_y+f_w+q+b+s+j+f)==0)
		flag_of_zero = 1;
	daxie(y, flag_of_zero);
	if ((f_y + f_w + q + b + s + y) > 0) {
		f_z = 1;
		strcat(result, "Բ");
	}
	else if ((f_y + f_w + q + b + s + j + f) == 0) {
		strcat(result, "Բ");
	}
	flag_of_zero = 0;

	//jiao
	if (f!=0&&f_z!=0)
		flag_of_zero = 1;
	daxie(j, flag_of_zero);
	if (j != 0) {
		strcat(result, "��");
	}
	flag_of_zero = 0;

	//fen
	daxie(f, flag_of_zero);
	if (f != 0) {
		strcat(result, "��");
	}
	else if (f == 0) {
		strcat(result, "��");
	}
    printf("��д�����:\n");
    printf("%s\n", result);  /* ת���õ��Ĵ�д�����ֻ�����ñ��������������ط����������κ���ʽ�Դ�д�������ȫ��/������� */
    return 0;
}