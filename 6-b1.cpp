/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;
	bool is_num;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	cout << "�����������������������ֵ��ַ���" << endl;
	cin.getline(str, 256);
	p = str;
	pa = a;
	is_num = 0;
	for (; *p != '\0'; p++) {
		//��ʼ
		if (*p >= '0' && *p <= '9') {
			if (!is_num) {
				*pa = *p - '0';
				is_num = 1;
			}
			else {
				*pa = *pa * 10 + *p - '0';
			}
		}
		else if (is_num) {
			if (pa - a < 9) {  
				pa++;
			}
			is_num = 0;  
		}
	}

	if (is_num && pa - a < 10) {
		pa++;
	}

	cout << "����" << pa - a << "������" << endl;
	for (pnum = a; pnum < pa; pnum++) {
		cout << *pnum << ' ';
	}
	cout << endl;
	return 0;
}
