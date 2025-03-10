/* 2354218 肖佳彤 计科 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int y, m, xq,ret1,ret2;
	while (1) {
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		ret1 = scanf("%d %d", &y,&m);
		if (ret1 != 2) {
			while (getchar() != '\n')
				;
		}
		else if (y >= 2000 && y <= 2030 && m >= 1 && m <= 12)
			break;

		printf("输入非法，请重新输入\n");
	}
	while (1) {
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ",y,m);
		ret2 = scanf("%d", &xq); 
		if (ret2 ==0 ) {
			while (getchar() != '\n')
				;
		}
		else if (xq >= 0 && xq <= 6)
			break;

		printf("输入非法，请重新输入\n");
	}
	printf("\n");

	int days;
	int run = (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		days = 31;
	else if (m == 4 || m == 6 || m == 9 || m == 11)
		days = 30;
	else if (m == 2 && run)
		days = 29;
	else if (m == 2 &&!run)
		days = 28;
	printf("%d年%d月的月历为:\n", y, m);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	for (int i = 0; i < xq; ++i) {
		printf("        ");
	}
	for (int day = 1; day <= days; ++day) {
		printf("  %2d    ", day);  
		if ((day + xq) % 7 == 0) {
			printf("\n");
		}
	}
	printf("\n");
	return 0;
}