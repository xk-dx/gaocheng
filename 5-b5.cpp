/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
using namespace std;

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
	cout<<"������ɼ������1000������������������"<<endl;
	for (i = 0; i < 1000; i++)
	{
		int temp;
		cin >> temp;
		if (temp >= 0)
			num[i] = temp;
		else
			break;
	}
	if (i == 0) {
		cout<<"����Ч����"<<endl;
		return 0;
	}
	cout<<"���������Ϊ:"<<endl;
	for (int j = 0; j < i; j++) {
		cout << num[j]<<" ";
		if ((j + 1) % 10 == 0 && j != (i - 1))
			cout << endl;
	}
	cout<<endl;
	cout<<"���������εĶ�Ӧ��ϵΪ:"<<endl;
	sort(num, i);
	int rank=0;
	for (int j = 0; j < i; ) {
		int count = 0;
		for (int k = j; k < i; k++) {
			if (num[k] == num[j]) {
				cout << num[j] <<" " << j + 1 << endl;
				count++;
			}
		}
		j += count;
	} 
}