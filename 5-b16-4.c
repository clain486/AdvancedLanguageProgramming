/* 2151140 ��07 ��ǫ */
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
		printf("�������%d���˵�ѧ�š��������ɼ�\n", i + 1);
		ret = scanf("%s %s %d", num[i], name[i], &grades[i]);
		if (grades[i] >= 60) {
			n++;
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9; j++) {
			if (grades[j] > grades[j + 1]) {
				continue;
			}
			else if (grades[j] < grades[j + 1]) {
				strcpy(med, num[j]);
				strcpy(num[j], num[j + 1]);
				strcpy(num[j + 1], med);

				strcpy(med, name[j]);
				strcpy(name[j], name[j + 1]);
				strcpy(name[j + 1], med);

				mid = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = mid;
			}
		}
	}
	printf("\nȫ��ѧ��(�ɼ�����):\n");
	for (l = 0; l < 10; l++) {
		printf("%s %s %d\n", name[l], num[l], grades[l]);
	}

	return 0;
}
