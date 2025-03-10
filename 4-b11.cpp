/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		����   ��1����������һ�����������������ݹ麯�����������������ӵĺ����в������κ���ʽ��ѭ��
				 2��������ų���
				 3������const�ͱ���

		������ ��1������ȫ�ֱ���
				 2����print_tower֮������������в������徲̬�ֲ�����
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
	 �������ƣ�
	 ��    �ܣ���ӡ��ĸ��
	 ���������
	 �� �� ֵ��
	 ˵    �����βΰ�������
			   ��ʾ����һ������order��ָ������/����
   ***************************************************************************/


void print_tower(char c,int order,int number)//0��1����
{
	if (order == 0) {//����
		if (c < 'A') 
			return;
		print_tower(c - 1,0,number + 1);
		printspaces(number);
		print_backhalf(c, 'B');
		print_fronthalf(c,'A');
		cout << endl;
	}
	if (order == 1) {//����
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main�����е�...�����޸ģ�����λ�ò�׼�޸�
***************************************************************************/
int main()
{
	char end_ch;

	/* ������������ַ�(����д��Ч��Ϊ����ѭ�����֣��������������) */
	cout << "����������ַ�(A~Z)" << endl;
	end_ch = getchar();			//����������һ���ַ�
	if (end_ch < 'A' || end_ch > 'Z') {
		cout << "�����ַ����Ǵ�д��ĸ" << endl;
		return -1;
	}
	
	/* ��������ĸ��(�м�ΪA) */
	cout <<print_equal(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << print_equal(end_ch)<< endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch,0,0); //�����ӡ A~�����ַ� 
	cout << endl;
	
	/* ��������ĸ��(�м�ΪA) */
	cout << print_equal(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	cout << "��������ĸ��(" << end_ch << "->A)" << endl;
	cout << print_equal(end_ch) << endl; /* ����ĸ����������=(��������ѭ��) */
	print_tower(end_ch, 1, 0); //�����ӡ A~�����ַ� 
	cout << endl;


	/* ����������Ư�������Σ��м�ΪA�� */
	cout << print_equal(end_ch) << endl;/* ����ĸ����������= */
	cout << "����(" << end_ch << "->A)" << endl;
	cout << print_equal(end_ch) << endl;/* ����ĸ����������= */
	print_tower(end_ch, 0, 0);   //��ӡ A~�����ַ��������� 
	print_tower(end_ch-1, 1, 1);  //��ӡ A~�����ַ�-1�ĵ����� 
	cout << endl;

	return 0;
}