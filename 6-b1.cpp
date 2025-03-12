/* 2151140 信07 王谦 */
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

#define  N  10	/* 假设最多转换10个数字 */

/* 不允许再定义其它函数、全局变量 */

int main()
{
	/* 如果有不需要的变量，允许删除，但不允许添加或替换为其它类型的变量 */
	char str[256], * p;
	int  a[N] = { 0 }, * pnum, * pa;

	/* 上面的定义不准动(删除不需要的变量除外)，下面为程序的具体实现，要求不得再定义任何变量、常量、常变量 */
	p = str;
	pa = a;
	pnum = a;
	cout << "请输入间隔含有若干正负数字的字符串" << endl;
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
	cout << "共有" << pnum-a << "个整数" << endl;
	for (;pa<pnum; pa++) {
		cout << *pa << " ";
	}
	cout << endl;

	return 0;
}