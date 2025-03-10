/* 2354218 Ф��ͮ �ƿ� */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include "read_stulist.h"
using namespace std;

#define MAX_FILENAME_LEN		512	//�����ļ�������󳤶�
/* stu_metge ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_merge {
private:
	int  stu_no;					//ѧ��
	char stu_name[MAX_NAME_LEN];  //����
	int round[2];
	friend class stu_list;
	/* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */

public:
	//���಻�������κεĹ������ݳ�Ա����Ա����
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	student list_round_1[MAX_STU_NUM];	//��һ��ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_1;						//��һ��ѡ�ε�ѧ������

	student list_round_2[MAX_STU_NUM];	//�ڶ���ѡ�ε�ѧ�������������򡢲�ȥ�أ�
	int list_num_2;						//�ڶ���ѡ�ε�ѧ������

	stu_merge list_merge[MAX_STU_NUM];	//�ϲ����ѧ��������ȥ�أ����������У�
	int list_merge_num;					//�ϲ����ѧ��������Ŀǰ����ӡ�����������ڲ������������Ҫ��Ҳ��Ҫɾ����

	/* ���������private���ݳ�Ա�ͳ�Ա����
	   ע�⣬���������array / set / map / vector��STL���� */

public:
	stu_list();										//���캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
	int read(const char* filename, const int round);	//���ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
	int print(const char* prompt = NULL);				//��ӡ���յ�ѡ������
	void merge();
	/* �������������public��Ա��������ʾ���ϲ���ȥ�ء�����ȣ�
	   �������幫�е����ݳ�Ա
	   �������ڳ�Ա������ʹ��array / set / map / vector��STL���� */

};

/* --- ������Ը���stu_merge/stu_list������ĳ�Ա����������ʵ�� --- */
void stu_list::merge()
{
	int total_num = list_num_1 + list_num_2;
	for (int i = 0; i < list_num_1; ++i) {
		list_merge[i].stu_no = list_round_1[i].no;
		strcpy(list_merge[i].stu_name, list_round_1[i].name);
		list_merge[i].round[0] = 1;  
		list_merge[i].round[1] = 0; 
	}
	for (int i = 0; i < list_num_2; ++i) {
		list_merge[list_num_1 + i].stu_no = list_round_2[i].no;
		strcpy(list_merge[list_num_1 + i].stu_name, list_round_2[i].name);
		list_merge[list_num_1 + i].round[0] = 0;  
		list_merge[list_num_1 + i].round[1] = 1; 
	}

	// ʹ�ò��������������
	for (int i = 1; i < total_num; ++i) {
		stu_merge temp = list_merge[i];
		int j = i - 1;
		while (j >= 0 && list_merge[j].stu_no > temp.stu_no) {
			list_merge[j + 1] = list_merge[j];
			--j;
		}
		list_merge[j + 1] = temp;
	}

	// ȥ�ز��ϲ��ִ���Ϣ
	int uniqueSize = 0;  
	for (int i = 0; i < total_num; ++i) {
		if (uniqueSize == 0 || list_merge[i].stu_no != list_merge[uniqueSize - 1].stu_no) {
			list_merge[uniqueSize++] = list_merge[i];
		}
		else {
			list_merge[uniqueSize - 1].round[0] |= list_merge[i].round[0];
			list_merge[uniqueSize - 1].round[1] |= list_merge[i].round[1];
		}
	}
	list_merge_num = uniqueSize;
}



/***************************************************************************
  �������ƣ�
  ��    �ܣ����ļ��ж���ѡ����Ϣ��roundΪ1/2����ʾѡ���ִ�
  ���������
  �� �� ֵ��
  ˵    �������캯����������ɳ�ʼ�����ܣ��������Ҫ�������պ�������
***************************************************************************/
stu_list::stu_list()
{
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ���ʾ��̬���ӿ��ʹ�ã��������е��þ�̬���ӿ��е�Ԥ�ú���
  ���������
  �� �� ֵ��
  ˵    ��������������Ҫ�޸� 
***************************************************************************/
int stu_list::read(const char* filename, const int round)
{
	int ret = 0;
	/* ��ȡ��1/2�ֵ�ѡ����������ӡ */
	switch (round) {
		case 1:
			this->list_num_1 = read_stulist(filename, this->list_round_1, MAX_STU_NUM);
			if (this->list_num_1 > 0)
				print_stulist("��һ��ѡ��������", this->list_round_1, this->list_num_1);
			else
				ret = -1;
			break;
		case 2:
			this->list_num_2 = read_stulist(filename, this->list_round_2, MAX_STU_NUM);
			if (this->list_num_2 > 0)
				print_stulist("�ڶ���ѡ��������", this->list_round_2, this->list_num_2);
			else
				ret = -1;
			break;
		default:
			ret = -1;
			break;
	}

	return ret;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ������ӡ���յ�ѡ������
***************************************************************************/
int stu_list::print(const char* prompt)
{
	merge();
	cout << "����ѡ������" << endl;
	cout << "============================================================" << endl;
	cout << "��� ѧ��     ����                             ��һ�� �ڶ���" << endl;
	cout << "============================================================" << endl;
	for (int i = 0; i < list_merge_num; i++)
	{
		cout << left << setw(5) << i + 1<< list_merge[i].stu_no << "  " << setw(33) << list_merge[i].stu_name;
		if (list_merge[i].round[0] == 0) {
			cout << "/      ";
			if (list_merge[i].round[1] == 0) {
				cout << "/";
			}
			else 
				cout << "��ѡ";
		}
		else {
			cout << "Y      ";
			if (list_merge[i].round[1] == 0) {
				cout << "�˿�";
			}
			else
				cout << "Y";
		}
		cout << endl;
	}
	cout << "============================================================" << endl;
	return 0;
}

/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����
***************************************************************************/
int main(int argc, char** argv)
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	gets_s(file1); //cin���ܶ��пո���ļ�

	cout << "�������һ��ѡ�ε������ļ� : ";
	gets_s(file2);

	stu_list list;

	/* �������� */
	if (list.read(file1, 1) < 0)
		return -1;
	if (list.read(file2, 2) < 0)
		return -1;

	/* �������� */


	/* ��ӡ */
	list.print("����ѡ������");

	return 0;
}

