/* 2151140 ��07 ��ǫ */
#include <iostream>
#include <string>
using namespace std;

void judge(char *p)
{
	char str2[82];
	int n = strlen(p) - 1;
	char* p1 = p,* p2 = str2;
	int num = 0;

	for (; p1 + n > p; p1--, p2++) {
		*p2 = *(p1 + n-1);
	}	
	for (p1 = p, p2 = str2; p1 < p + n; p1++, p2++) {
		if (*p1 == *p2) {
			num++;
		}
		else {
			cout << "no" << endl;
			break;
		}
	}
	if (num == n) {
		cout << "yes" << endl;
	}
}

int main()
{
	char str[82];
	cout << "������һ������С��80���ַ��������Ĵ���" << endl;
    fgets(str, 82, stdin);
	judge(str);
	return 0;
}