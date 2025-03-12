/* 2151140 信07 王谦 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char num[10][8], name[10][9];
	int grades[10] = { 0 }, order[10] = { 0 };
	int i, j, k, l, n = 0, ret, mid;
	char med[9];
	for (i = 0; i < 10; i++) {
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		ret = scanf("%s %s %d", num[i], name[i], &grades[i]);
		if (grades[i] >= 60) {
			n++;
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9; j++) {
			for (k = 0; k < 8; k++) {
				if (num[j][k] > num[j + 1][k]) {
					break;
				}
				else if (num[j][k] < num[j + 1][k]) {
					strcpy(med, num[j]);
					strcpy(num[j], num[j + 1]);
					strcpy(num[j + 1], med);

					strcpy(med, name[j]);
					strcpy(name[j], name[j + 1]);
					strcpy(name[j + 1], med);

					mid = grades[j];
					grades[j] = grades[j + 1];
					grades[j + 1] = mid;

					break;
				}
			}
		}
	}
	printf("\n及格名单(学号降序):\n");
	for (l = 0; l < n; l++) {
		if (grades[l] >= 60) {
			printf("%s %s %d\n", name[l], num[l], grades[l]);
		}
		else {
			n += 1;
		}
	}

	return 0;
}
