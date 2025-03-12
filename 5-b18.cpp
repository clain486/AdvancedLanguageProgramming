/* 2151140 ĞÅ07 ÍõÇ« */
#include <iostream>
#include <cstring>
using namespace std;


int judge(char password[18], int length, int standard_up, int standard_low, int standard_numb, int standard_other)
{
	int k;
	int up_num = 0, low_num = 0, numb_num = 0, space_num = 0, other_num = 0;
	for (k = 0; k < length; k++) {
		if (password[k] == 32) {
			space_num++;
		}
		else if (password[k] >= 65 && password[k] <= 90) {
			up_num++;
		}
		else if (password[k] >= 97 && password[k] <= 122) {
			low_num++;
		}
		else if (password[k] >= 48 && password[k] <= 57) {
			numb_num++;
		}
		else if (password[k] == '~' || password[k] == '!' || password[k] == '@' || password[k] == '#'
			|| password[k] == '$' || password[k] == '%' || password[k] == '^' || password[k] == '&'
			|| password[k] == '*' || password[k] == '(' || password[k] == ')' || password[k] == '-'
			|| password[k] == '_' || password[k] == '=' || password[k] == '+' || password[k] == '['
			|| password[k] == ']' || password[k] == ',' || password[k] == '.' || password[k] == '?') {
			other_num++;
		}
		else {
			return 0;
		}
	}
	if (up_num >= standard_up && low_num >= standard_low && numb_num >= standard_numb && other_num >= standard_other) {
		return 1;
	}
	else {
		return 0;
	}
}


int main()
{
	char space[100];
	int standard[5];
	char password[10][18];
	int length[10];
	int i, judge_every = 0, judge_sum = 0;

	fgets(space, 100, stdin);
	for (i = 0; i < 5; i++) {
		cin >> standard[i];
	}
	for (i = 0; i < 10; i++) {
		cin >> password[i];
		length[i] = strlen(password[i]);
	}

	for (i = 0; i < 10; i++) {
		judge_every = judge(password[i], length[i], standard[1], standard[2], standard[3], standard[4]);
		if (standard[0] < 12 || standard[0]>16) {
			cout << "´íÎó" << endl;
			break;
		}
		else if (standard[1] < 2 || standard[2] < 2 || standard[3] < 2 || standard[4] < 2 || standard[1] + standard[2] + standard[3] + standard[4] >standard[0]) {
			cout << "´íÎó" << endl;
			break;
		}
		else if (length[i] != standard[0]) {
			cout << "´íÎó" << endl;
			break;
		}
		else if (judge_every == 0) {
			cout << "´íÎó" << endl;
			break;
		}
		else {
			judge_sum++;
		}
	}
	if (judge_sum == 10) {
		cout << "ÕıÈ·" << endl;
	}
	return 0;
}