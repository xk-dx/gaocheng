/* 2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int r;  // 闰年判断
    int year, month, day;

    printf("请输入年，月，日\n");
    scanf("%d %d %d", &year, &month, &day);

    r = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int daysInMonth;
    if (month == 1) {
        daysInMonth = 31;
    }
    else if (month == 2) {
        if (r) {
            daysInMonth = 29;  // 闰年2月29天
        }
        else {
            daysInMonth = 28;  // 平年2月28天
        }
    }
    else if (month == 3) {
        daysInMonth = 31;
    }
    else if (month == 4) {
        daysInMonth = 30;
    }
    else if (month == 5) {
        daysInMonth = 31;
    }
    else if (month == 6) {
        daysInMonth = 30;
    }
    else if (month == 7) {
        daysInMonth = 31;
    }
    else if (month == 8) {
        daysInMonth = 31;
    }
    else if (month == 9) {
        daysInMonth = 30;
    }
    else if (month == 10) {
        daysInMonth = 31;
    }
    else if (month == 11) {
        daysInMonth = 30;
    }
    else if (month == 12) {
        daysInMonth = 31;
    }
    else {
        // 月份不正确
        printf("输入错误-月份不正确\n");
        return 0;
    }

    // 检查日期是否合法
    if (day < 1 || day > daysInMonth) {
        printf("输入错误-日与月的关系非法\n");
        return 0;
    }

    // 计算输入日期是当年的第几天
    int days = day;
    if (month > 1) 
        days += 31;     
    if (month > 2) 
        days += r ? 29 : 28;  
    if (month > 3) 
        days += 31;      
    if (month > 4)
        days += 30;  
    if (month > 5) 
        days += 31; 
    if (month > 6) 
        days += 30; 
    if (month > 7) 
        days += 31;    
    if (month > 8) 
        days += 31;    
    if (month > 9) 
        days += 30;      
    if (month > 10)
        days += 31;      
    if (month > 11)
        days += 30;

    printf("%d-%d-%d是%d年的第%d天\n", year, month, day, year, days);

    return 0;
}

