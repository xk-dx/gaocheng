/* 2354218 Ф��ͮ �ƿ� */
#pragma once

/* --- �������Ҫ��ͷ�ļ�������ռ䣬д�ڴ˴� --- */

/* --- �������Ҫ�ĺ궨�塢ֻ��ȫ�ֱ����ȣ�д�ڴ˴� --- */

/* --- ���������ȫ�ֺ�����Ҫ������д�ڴ˴� --- */

/* ��ȫDate��Ķ��壬���г�Ա����������ʵ�֣���Ҫ�ڴ˴�����ʵ�� */
class Date {
private:
	int year;
	int month;
	int day;
	/* ������������ݳ�Ա */

public:
	/* ������Ҫ��������ĳ�Ա��������Ԫ������(������������ݳ�Ա) */
	Date();
	Date(int y, int m, int d);
	Date(int days);
	void set(int y, int m = 1, int d = 1);
	void get(int& y, int& m, int& d);
	void show();
};
