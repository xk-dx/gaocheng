/* 2354218 肖佳彤 计科 */
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */
	int count = 0;
	int a, b, c, d, e, f, g, h, i;
	for (a = 1; a < 10; a++) {
		for (b = 1; b < 10; b++) {
			if (b == a)
				continue;
			for (c = 1; c < 10; c++) {
				if (c == a || c == b)
					continue;
				int num1 = 100 * a + 10 * b + c;
				//第二个数
				for (d = 1; d < 10; d++) {
					if (d == c || d == a || d == b)
						continue;
					for (e = 1; e < 10; e++) {
						if (e == d || e == c || e == a || e == b)
							continue;
						for (f = 1; f < 10; f++) {
							if (f == e || f == d || f == c || f == a || f == b)
								continue;
							int num2 = 100 * d + 10 * e + f;
							//第三数
							for (g = 1; g < 10; g++) {
								if (g == f || g == e || g == d || g == c || g == a || g == b)
									continue;
								for (h = 1; h < 10; h++) {
									if (h == g || h == f || h == e || h == d || h == c || h == a || h == b)
										continue;
									for (i = 1; i < 10; i++) {
										if (i == h || i == g || i == f || i == e || i == d || i == c || i == a || i == b)
											continue;
										int num3 = 100 * g + 10 * h + i;									
										if (num1 < num2 && num2 < num3 && num1 + num2 + num3 == 1953)
											printf("No.%3d : %d+%d+%d=1953\n", ++count,num1,num2,num3);
									}
								}
							}
						}
					}

				}
			}
		}
	}
	printf("total=%d\n", count);
	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	printf("计数器频率 : %lldHz\n", tick.QuadPart);
	printf("计数器计数 : %lld\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);

	return 0;
}