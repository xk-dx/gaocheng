/* 2354218 Ф��ͮ �ƿ� */
#include <iostream>
using namespace std;

int main()
{
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
	//ʮ��
	cout << "��д�����:" << endl;
	if (sy == 1) {
		cout<<"Ҽʰ";
	}
	else if (sy == 2) {
		cout<< "��ʰ";
	}
	else if (sy == 3) {
		cout<< "��ʰ";
	}
	else if (sy == 4) {
		cout<< "��ʰ";
	}
	else if (sy == 5) {
		cout<< "��ʰ";
	}
	else if (sy == 6) {
		cout<< "½ʰ";
	}
	else if (sy == 7) {
		cout<< "��ʰ";
	}
	else if (sy == 8) {
		cout<< "��ʰ";
	}
	else if (sy == 9) {
		cout<< "��ʰ";
	}
	//��
	if (yi == 1) {
		cout<< "Ҽ";
	}
	else if (yi == 2) {
		cout<< "��";
	}
	else if (yi == 3) {
		cout<< "��";
	}
	else if (yi == 4) {
		cout<< "��";
	}
	else if (yi == 5) {
		cout<< "��";
	}
	else if (yi == 6) {
		cout<< "½";
	}
	else if (yi == 7) {
		cout<< "��";
	}
	else if (yi == 8) {
		cout<< "��";
	}
	else if (yi == 9) {
		cout<< "��";
	}
	if (sy != 0 || yi != 0)
		cout<< "��";

	//ǧ��
	if (qw == 1) {
		cout<< "ҼǪ";
	}
	else if (qw == 2) {
		cout<< "��Ǫ";
	}
	else if (qw == 3) {
		cout<< "��Ǫ";
	}
	else if (qw == 4) {
		cout<< "��Ǫ";
	}
	else if (qw == 5) {
		cout<< "��Ǫ";
	}
	else if (qw == 6) {
		cout<< "½Ǫ";
	}
	else if (qw == 7) {
		cout<< "��Ǫ";
	}
	else if (qw == 8) {
		cout<< "��Ǫ";
	}
	else if (qw == 9) {
		cout<< "��Ǫ";
	}
	else if (qw == 0 && (sy != 0 || yi != 0) && (sw != 0 || bw != 0 || w != 0)) {
		cout<< "��";
	}
	//����
	if (bw == 1) {
		cout<< "Ҽ��";
	}
	else if (bw == 2) {
		cout<< "����";
	}
	else if (bw == 3) {
		cout<< "����";
	}
	else if (bw == 4) {
		cout<< "����";
	}
	else if (bw == 5) {
		cout<< "���";
	}
	else if (bw == 6) {
		cout<< "½��";
	}
	else if (bw == 7) {
		cout<< "���";
	}
	else if (bw == 8) {
		cout<< "�ư�";
	}
	else if (bw == 9) {
		cout<< "����";
	}
	else if (qw != 0 && bw == 0 && (sw != 0 || w != 0)) {
		cout<< "��";  // ǧλ���ڵ���λΪ��ʱ������㡱
	}
	//ʮ��
	if (sw == 1) {
		cout<< "Ҽʰ";
	}
	else if (sw == 2) {
		cout<< "��ʰ";
	}
	else if (sw == 3) {
		cout<< "��ʰ";
	}
	else if (sw == 4) {
		cout<< "��ʰ";
	}
	else if (sw == 5) {
		cout<< "��ʰ";
	}
	else if (sw == 6) {
		cout<< "½ʰ";
	}
	else if (sw == 7) {
		cout<< "��ʰ";
	}
	else if (sw == 8) {
		cout<< "��ʰ";
	}
	else if (sw == 9) {
		cout<< "��ʰ";
	}
	else if (bw != 0 && sw == 0 && w != 0) {
		cout<< "��";  // ��λ���ڵ�ʮλΪ��ʱ������㡱
	}

	// �жϲ�ת����λ
	if (w == 1) {
		cout<< "Ҽ";
	}
	else if (w == 2) {
		cout<< "��";
	}
	else if (w == 3) {
		cout<< "��";
	}
	else if (w == 4) {
		cout<< "��";
	}
	else if (w == 5) {
		cout<< "��";
	}
	else if (w == 6) {
		cout<< "½";
	}
	else if (w == 7) {
		cout<< "��";
	}
	else if (w == 8) {
		cout<< "��";
	}
	else if (w == 9) {
		cout<< "��";
	}
	if (sw != 0 || bw != 0 || qw != 0 || w != 0)
		cout<< "��";

	//ǧ
	if (q == 1) {
		cout<< "ҼǪ";
	}
	else if (q == 2) {
		cout<< "��Ǫ";
	}
	else if (q == 3) {
		cout<< "��Ǫ";
	}
	else if (q == 4) {
		cout<< "��Ǫ";
	}
	else if (q == 5) {
		cout<< "��Ǫ";
	}
	else if (q == 6) {
		cout<< "½Ǫ";
	}
	else if (q == 7) {
		cout<< "��Ǫ";
	}
	else if (q == 8) {
		cout<< "��Ǫ";
	}
	else if (q == 9) {
		cout<< "��Ǫ";
	}
	else if (q == 0 && (sy != 0 || yi != 0 || sw != 0 || bw != 0 || qw != 0 || w != 0) && (b != 0 || s != 0 || y != 0)) {
		cout<< "��";
	}
	//��
	if (b == 1) {
		cout<< "Ҽ��";
	}
	else if (b == 2) {
		cout<< "����";
	}
	else if (b == 3) {
		cout<< "����";
	}
	else if (b == 4) {
		cout<< "����";
	}
	else if (b == 5) {
		cout<< "���";
	}
	else if (b == 6) {
		cout<< "½��";
	}
	else if (b == 7) {
		cout<< "���";
	}
	else if (b == 8) {
		cout<< "�ư�";
	}
	else if (b == 9) {
		cout<< "����";
	}
	else if (q != 0 && b == 0 && (s != 0 || y != 0)) {
		cout<< "��";  // ǧλ���ڵ���λΪ��ʱ������㡱
	}
	//ʮ
	if (s == 1) {
		cout<< "Ҽʰ";
	}
	else if (s == 2) {
		cout<< "��ʰ";
	}
	else if (s == 3) {
		cout<< "��ʰ";
	}
	else if (s == 4) {
		cout<< "��ʰ";
	}
	else if (s == 5) {
		cout<< "��ʰ";
	}
	else if (s == 6) {
		cout<< "½ʰ";
	}
	else if (s == 7) {
		cout<< "��ʰ";
	}
	else if (s == 8) {
		cout<< "��ʰ";
	}
	else if (s == 9) {
		cout<< "��ʰ";
	}
	else if (b != 0 && s == 0 && y != 0) {
		cout<< "��";  // ��λ���ڵ�ʮλΪ��ʱ������㡱
	}

	// �жϲ�ת����λ
	if (y == 1) {
		cout<< "Ҽ";
	}
	else if (y == 2) {
		cout<< "��";
	}
	else if (y == 3) {
		cout<< "��";
	}
	else if (y == 4) {
		cout<< "��";
	}
	else if (y == 5) {
		cout<< "��";
	}
	else if (y == 6) {
		cout<< "½";
	}
	else if (y == 7) {
		cout<< "��";
	}
	else if (y == 8) {
		cout<< "��";
	}
	else if (y == 9) {
		cout<< "��";
	}
	bool is_z(sy != 0 || yi != 0 || sw != 0 || bw != 0 || qw != 0 || w != 0 || q != 0 || b != 0 || s != 0 || y != 0);//�������ֲ�Ϊ��
	if (is_z)
		cout<< "Բ";

	//С��

	if (j == 1) {
		cout<< "Ҽ��";
	}
	else if (j == 2) {
		cout<< "����";
	}
	else if (j == 3) {
		cout<< "����";
	}
	else if (j == 4) {
		cout<< "����";
	}
	else if (j == 5) {
		cout<< "���";
	}
	else if (j == 6) {
		cout<< "½��";
	}
	else if (j == 7) {
		cout<< "���";
	}
	else if (j == 8) {
		cout<< "�ƽ�";
	}
	else if (j == 9) {
		cout<< "����";
	}
	else if (j == 0 && f != 0 && is_z) {
		cout<< "��";
	}
	else if (j == 0 && f == 0 && is_z) {
		cout<< "��";
	}
	else if (j == 0 && f == 0 && !is_z) {
		cout<< "��Բ��";
	}
	//��
	if (f == 1) {
		cout<< "Ҽ��";
	}
	else if (f == 2) {
		cout<< "����";
	}
	else if (f == 3) {
		cout<< "����";
	}
	else if (f == 4) {
		cout<< "����";
	}
	else if (f == 5) {
		cout<< "���";
	}
	else if (f == 6) {
		cout<< "½��";
	}
	else if (f == 7) {
		cout<< "���";
	}
	else if (f == 8) {
		cout<< "�Ʒ�";
	}
	else if (f == 9) {
		cout<< "����";
	}
	else if (f == 0 && j != 0) {
		cout<< "��";
	}
	cout<<endl;
	return 0;
}





