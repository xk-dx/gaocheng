/* 2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int is_leap(int year)
{
	int le;
	return le = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int cal_days(int year, int month, int day)
{
	int leap;
	leap = is_leap(year);
	int days=0;
	int mon_days[12] = { 31,28 + leap,31,30,31,30,31,31,30,31,30,31 };
	if (day <= 0 || day > mon_days[month - 1])
		return 0;
	for (int i = 0; i < month - 1; i++) {
		days += mon_days[i];
	}
	days += day;
	return days;
}
int main()
{
	int year, month, day;
	printf("请输入年，月，日\n");
	scanf("%d %d %d", &year, &month, &day);

	if (month < 1 || month > 12)
	{
		printf("输入错误-月份不正确\n");
		return 0;
	}
	int days;
	days = cal_days(year, month, day);
	if (days == 0)
	{
		printf("输入错误-日与月的关系非法\n");
		return 0;
	}
	printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);
	return 0;
}