/* 2151140 ��07 ��ǫ */
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char str[33];
	char* p = str, * p1 = str;
	unsigned int sum = 0;
	cout << "������һ��0/1��ɵ��ַ��������Ȳ�����32" << endl;
	cin >> p;
	int n = strlen(p);

	for (; p < p1 + n; p++) {
		sum = 2 * sum + (*p - 48);
	}
	cout << sum << endl;

	return 0;
}