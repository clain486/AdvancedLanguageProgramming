/* 2151140 信07 王谦 */
#include <iostream>
#include <string>
using namespace std;

int main()
{
	char str[33];
	char* p = str, * p1 = str;
	unsigned int sum = 0;
	cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
	cin >> p;
	int n = strlen(p);

	for (; p < p1 + n; p++) {
		sum = 2 * sum + (*p - 48);
	}
	cout << sum << endl;

	return 0;
}