/* 2151140 ��07 ��ǫ */
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define  N  10	/* �������ת��10������ */

/* �������ٶ�������������ȫ�ֱ��� */

int main()
{
	/* ����в���Ҫ�ı���������ɾ��������������ӻ��滻Ϊ�������͵ı��� */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;

	/* ����Ķ��岻׼��(ɾ������Ҫ�ı�������)������Ϊ����ľ���ʵ�֣�Ҫ�󲻵��ٶ����κα����������������� */
	p = str;
	pa = a;
	pnum = a;
	cout << "�����������������������ֵ��ַ���" << endl;
	gets_s(str);
	for (; *p != '\0'&& a+10 > pnum; p++) {
		if (*p >= 48 && *p <= 57&& *(p+1) >= 48 && *(p+1) <= 57) {
			//*(p + 1) = 10 * (*p) + *(p + 1);
			*pa = 10 * (*pa) + (*p - 48);
		}
		else if (*p >= 48 && *p <= 57) {
			*pa = 10 * (*pa) + (*p - 48);
			pa++;
			pnum++;
		}
	}
	pa -= (pnum-a);
	cout << "����" << pnum-a << "������" << endl;
	for (;pa<pnum; pa++) {
		cout << *pa << " ";
	}
	cout << endl;

	return 0;
}