/* 2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ret, x;
	while (1) {
		printf("������x��ֵ[0-100] : ");
		ret = scanf("%d", &x); //����x�ķ�ʽ������scanf�Ҹ�ʽ��Ϊ%d����׼�÷�scanf
		if (ret == 0) {
			while (getchar() != '\n')
				;
		}
		else if (ret == 1 && (x >= 0 && x <= 100))
			break;

		printf("�����д�[ret=%d x=%d],����������\n", ret, x);
	}
	printf("ret=%d x=%d\n", ret, x);
	return 0;
}