/* 2151140 信07 王谦 */
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)(time(0)));

	int length, up_num, low_num, numb_num, other_num;
	static const char other[21] = "~!@#$%^&*()-_=+[],.?";
	int i, j;

	cout << "请输入密码长度(12-16)， 大写字母个数(≥2)， 小写字母个数(≥2)， 数字个数(≥2)， 其它符号个数(≥2)" << endl;
	cin >> length >> up_num >> low_num >> numb_num >> other_num;
	if (cin.fail() != 0) {
		cout << "输入非法" << endl;
	}
	else if (length < 12 || length>16) {
		cout << "密码长度[" << length << "]不正确" << endl;
	}
	else if (up_num<2 || up_num>length) {
		cout << "大写字母个数[" << up_num << "]不正确" << endl;
	}
	else if (low_num<2 || low_num>length) {
		cout << "小写字母个数[" << low_num << "]不正确" << endl;
	}
	else if (numb_num<2 || numb_num>length) {
		cout << "数字个数[" << numb_num << "]不正确" << endl;
	}
	else if (other_num<2 || other_num>length) {
		cout << "其它符号个数[" << other_num << "]不正确" << endl;
	}
	else if (length < up_num + low_num + numb_num + other_num) {
		cout << "所有字符类型之和[" << up_num << "+" << low_num << "+" << numb_num << "+" << other_num << "]大于总密码长度[" << length << "]" << endl;
	}
	else {
		cout << length << " " << up_num << " " << low_num << " " << numb_num << " " << other_num << endl;
		for (j = 0; j < 10; j++) {
			/*随机确定各类数量，记录各数量下每个随机的值*/
			int up_asc[16], low_asc[16], numb_asc[16], other_turn[16];
			int up_n, low_n, numb_n, other_n;
			while (1) {
				int left = length;
				up_n = rand() % (left - 7) + up_num;
				for (i = 0; i < up_n; i++) {
					up_asc[i] = rand() % 26 + 65;
				}

				left -= up_n;
				if (left >= low_num + numb_num + other_num) {
					low_n = rand() % (left - 5) + low_num;
					for (i = 0; i < low_n; i++) {
						low_asc[i] = rand() % 26 + 97;
					}
				}
				else {
					continue;
				}

				left -= low_n;
				if (left >= numb_num + other_num) {
					numb_n = rand() % (left - 3) + numb_num;
					for (i = 0; i < numb_n; i++) {
						numb_asc[i] = rand() % 10 + 48;
					}
				}
				else {
					continue;
				}

				left -= numb_n;
				if (left >= other_num) {
					other_n = left;
					for (i = 0; i < other_n; i++) {
						other_turn[i] = rand() % 20;
					}
					break;
				}
				else {
					continue;
				}
			}
			/*类似于转盘一样的方式组合密码*/
			char password[17] = { 0 };
			for (i = 0; i < length; i++) {
				int random = rand() % 4 + 1;
				if (random == 1) {
					if (up_n > 0) {
						password[i] = (char)up_asc[up_n - 1];
						up_n--;
					}
					else {
						i--;
						continue;
					}
				}
				else if (random == 2) {
					if (low_n > 0) {
						password[i] = (char)low_asc[low_n - 1];
						low_n--;
					}
					else {
						i--;
						continue;
					}
				}
				else if (random == 3) {
					if (numb_n > 0) {
						password[i] = (char)numb_asc[numb_n - 1];
						numb_n--;
					}
					else {
						i--;
						continue;
					}
				}
				else if (random == 4) {
					if (other_n > 0) {
						password[i] = other[other_turn[other_n - 1]];
						other_n--;
					}
					else {
						i--;
						continue;
					}
				}
			}
			cout << password << endl;
		}
	}

	return 0;
}