/* 2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sort(int arr[], int n) {
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int i;
	int num[1000] = { 0 };
	printf("������ɼ������1000������������������\n");
	for (i=0; i < 1000; i++)
	{
		int temp;
		scanf("%d",&temp);
		if (temp >= 0)
			num[i] = temp;
		else
			break;
	}
	if (i == 0) {
		printf("����Ч����\n");
		return 0;
	}
	printf("���������Ϊ:\n");
	for (int j = 0; j < i; j++){
		printf("%d ", num[j]); 
		if ((j + 1) % 10==0&&j!=(i-1))
			printf("\n");
	}
	printf("\n");
	printf("�����������Ķ�Ӧ��ϵΪ:\n");
	sort(num, i);
	for (int j = 0; j < i;) 
	{
		int count = 0;
		for (int k = j; k < i; k++)
			if (num[k] == num[j])
					count++;
		printf("%d %d\n", num[j], count);
		j += count;
	}
	return 0;
}