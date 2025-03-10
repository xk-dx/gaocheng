/* 2354218 肖佳彤 计科 */
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
	cout<<"请输入成绩（最多1000个），负数结束输入"<<endl;
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
		cout<<"无有效输入"<<endl;
		return 0;
	}
	cout<<"输入的数组为:"<<endl;
	for (int j = 0; j < i; j++) {
		cout << num[j]<<" ";
		if ((j + 1) % 10 == 0 && j != (i - 1))
			cout << endl;
	}
	cout<<endl;
	cout<<"分数与名次的对应关系为:"<<endl;
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