/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
#include<math.h>
using namespace std;
unsigned int trans(char* str)
{
	unsigned int dec = 0;
	int len = strlen(str);
	char* p = str;
	for (; *p != '\0'; p++,len--) {
		dec += (*p - '0') * (unsigned int)(pow(2, len - 1));

	}
	return dec;
}


int main()
{
	char str[33];
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> str;
	unsigned int dec;

	dec = trans(str);
	cout << dec << endl;
	return 0;
}
