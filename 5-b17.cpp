/* 2151140 ��07 ��ǫ */
#include <iostream>
#include <time.h>
using namespace std;

int main()
{
	srand((unsigned int)(time(0)));

	int length, up_num, low_num, numb_num, other_num;
	static const char other[21] = "~!@#$%^&*()-_=+[],.?";
	int i, j;

	cout << "���������볤��(12-16)�� ��д��ĸ����(��2)�� Сд��ĸ����(��2)�� ���ָ���(��2)�� �������Ÿ���(��2)" << endl;
	cin >> length >> up_num >> low_num >> numb_num >> other_num;
	if (cin.fail() != 0) {
		cout << "����Ƿ�" << endl;
	}
	else if (length < 12 || length>16) {
		cout << "���볤��[" << length << "]����ȷ" << endl;
	}
	else if (up_num<2 || up_num>length) {
		cout << "��д��ĸ����[" << up_num << "]����ȷ" << endl;
	}
	else if (low_num<2 || low_num>length) {
		cout << "Сд��ĸ����[" << low_num << "]����ȷ" << endl;
	}
	else if (numb_num<2 || numb_num>length) {
		cout << "���ָ���[" << numb_num << "]����ȷ" << endl;
	}
	else if (other_num<2 || other_num>length) {
		cout << "�������Ÿ���[" << other_num << "]����ȷ" << endl;
	}
	else if (length < up_num + low_num + numb_num + other_num) {
		cout << "�����ַ�����֮��[" << up_num << "+" << low_num << "+" << numb_num << "+" << other_num << "]���������볤��[" << length << "]" << endl;
	}
	else {
		cout << length << " " << up_num << " " << low_num << " " << numb_num << " " << other_num << endl;
		for (j = 0; j < 10; j++) {
			/*���ȷ��������������¼��������ÿ�������ֵ*/
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
			/*������ת��һ���ķ�ʽ�������*/
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