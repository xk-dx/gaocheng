/* 2354218 Ф��ͮ �ƿ� */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    int r;  // �����ж�
    int year, month, day;

    printf("�������꣬�£���\n");
    scanf("%d %d %d", &year, &month, &day);

    r = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    int daysInMonth;
    if (month == 1) {
        daysInMonth = 31;
    }
    else if (month == 2) {
        if (r) {
            daysInMonth = 29;  // ����2��29��
        }
        else {
            daysInMonth = 28;  // ƽ��2��28��
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
        // �·ݲ���ȷ
        printf("�������-�·ݲ���ȷ\n");
        return 0;
    }

    // ��������Ƿ�Ϸ�
    if (day < 1 || day > daysInMonth) {
        printf("�������-�����µĹ�ϵ�Ƿ�\n");
        return 0;
    }

    // �������������ǵ���ĵڼ���
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

    printf("%d-%d-%d��%d��ĵ�%d��\n", year, month, day, year, days);

    return 0;
}

