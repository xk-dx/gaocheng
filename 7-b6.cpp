/* 2354218 肖佳彤 计科 */
#include <iostream>
#include <conio.h>
#include "7-b6.h"
using namespace std;

/* 给出 Date 类的所有成员函数的体外实现 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
Date::Date()
{
	year = 2000;
	month = 1;
	day = 1;
}

Date::Date(int y, int m, int d)
{
	int days_month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	if (y >= 1900 && y <= 2099)
		year = y;
	else
		year = 2000;
	if (m >= 1 && m <= 12)
		month = m;
	else
		month = 1;
	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		days_month[2]++;
	if (d >= 1 && d <= days_month[month])
		day = d;
	else
		day = 1;
}
bool isLeapYear(int year);
Date::Date(int days)
{
	int days_month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	year = 1900;
	month = 1;
	day = 1;
	if (days > 0) {
		while (days >= (isLeapYear(year) ? 366 : 365)) {
			days -= (isLeapYear(year) ? 366 : 365);
			year++;
		}
		if (isLeapYear(year))
			days_month[2]++;
		while (days >= days_month[month]) {
			days -= days_month[month];
			month++;
		}
		day = days;
	}
	if (year > 2099)
	{
		year = 2099;
		month = 12;
		day = 31;
	}
}

void Date::set(int y, int m, int d)
{
	int days_month[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (y) {
		if (y >= 1900 && y <= 2099)
			year = y;
		else
			year = 2000;
	}
	if (m) {
		if (m >= 1 && m <= 12)
			month = m;
		else
			month = 1;
	}
	if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
		days_month[2]++;

	if (d == 0) {
		if (day < 1 || day > days_month[month])
			day = 1;
	}
	else {
		if (d >= 1 && d <= days_month[month])
			day = d;
		else
			day = 1;
	}
	
}

void Date::get(int& y, int& m, int& d)
{
	y = year;
	m = month;
	d = day;
}

void Date::show()
{
	cout << year << '.' << month << '.' << day<<endl;
}
/* 如果有需要的其它全局函数的实现，可以写于此处 */
/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}