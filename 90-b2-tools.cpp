/* 2151140 信07 王谦 */
/* 一些内部数组/图形方式公用的函数，如判断结束等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include "90-b2.h"
#include <Windows.h>
#include <conio.h>
#include <time.h>
#include "cmd_console_tools.h"

using namespace std;

/*本小题结束的判断函数*/
void need_end()
{
	int x, y;
	char the_end[4];
	cct_getxy(x, y);
	y += 1;
	cout << endl
		<< "本小题结束，请输入End继续...                                                      ";
	cct_gotoxy(x + 29, y);
	while (1) {
		for (int i = 0; i < 3; i++) {
			cin >> the_end[i];
		}
		cin.clear();
		cin.ignore(65536, '\n');

		if ((the_end[0] == 'e' || the_end[0] == 'E') && (the_end[1] == 'n' || the_end[1] == 'N') && (the_end[2] == 'd' || the_end[2] == 'D')) {
			break;
		}
		else {
			cct_showch(x, y, ' ', COLOR_BLACK, COLOR_WHITE, 64);
			cct_showstr(0, y + 1, "输入错误，请重新输入                                                  ", COLOR_BLACK, COLOR_WHITE, 1);
			cct_gotoxy(x, y);
		}
	}
}

/*输入行列并记录的函数*/
void input_hanglie(int* p_hang_num, int* p_lie_num)
{
	cct_cls();

	while (1) {
		cout << "请输入行数(5-8)：" << endl;
		cin >> *p_hang_num;
		if (*p_hang_num >= 5 && *p_hang_num <= 8 && cin.fail() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
	}
	while (1) {
		cout << "请输入列数(5-10)：" << endl;
		cin >> *p_lie_num;
		if (*p_lie_num >= 5 && *p_lie_num <= 10 && cin.fail() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
	}
}

/*输入目标并记录的函数*/
void input_goal(int* p_goal)
{
	while (1) {
		cout << "请输入合成目标(5-20)：" << endl;
		cin >> *p_goal;
		if (*p_goal >= 5 && *p_goal <= 20 && cin.fail() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
	}
}

/*生成数组并记录的函数*/
void generate_array(int* p_hang_num, int* p_lie_num, coordinate* p_co)
{
	/*随机为数组赋值1-3并记录*/
	int i, j;
	for (i = 1; i < *p_hang_num + 1; i++) {
		for (j = 1; j < *p_lie_num + 1; j++) {
			p_co->array[i][j] = rand() % 3 + 1;
		}
	}
}

/*判断四周相同项的函数及其重载*/
int same_choose(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	int n = 0;
	if (p_co->array[*p_int_hang][*p_int_lie] == *p_object) {
		p_co->position[*p_int_hang][*p_int_lie] = '+';
	}
	if (p_co->array[*p_int_hang - 1][*p_int_lie] == *p_object) {
		p_co->position[*p_int_hang - 1][*p_int_lie] = '+';
		n++;
	}
	if (p_co->array[*p_int_hang][*p_int_lie - 1] == *p_object) {
		p_co->position[*p_int_hang][*p_int_lie - 1] = '+';
		n++;
	}
	if (p_co->array[*p_int_hang][*p_int_lie + 1] == *p_object) {
		p_co->position[*p_int_hang][*p_int_lie + 1] = '+';
		n++;
	}
	if (p_co->array[*p_int_hang + 1][*p_int_lie] == *p_object) {
		p_co->position[*p_int_hang + 1][*p_int_lie] = '+';
		n++;
	}
	return n;
}
int same_choose(int* p_hang_num, int* p_lie_num, int i, int j, coordinate* p_co)
{
	int n = 0;
	int object = p_co->array[i][j];
	if (p_co->array[i - 1][j] == object) {
		p_co->position[i - 1][j] = '+';
		n++;
	}
	if (p_co->array[i][j - 1] == object) {
		p_co->position[i][j - 1] = '+';
		n++;
	}
	if (p_co->array[i][j + 1] == object) {
		p_co->position[i][j + 1] = '+';
		n++;
	}
	if (p_co->array[i + 1][j] == object) {
		p_co->position[i + 1][j] = '+';
		n++;
	}
	return n;
}

/*实现合并同时记分的函数*/
void merge_near(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, int* p_goal, int* p_score_now, int* p_score_sum)
{
	int i, j, n = 0;
	for (i = 0; i < *p_hang_num + 2; i++) {
		for (j = 0; j < *p_lie_num + 2; j++) {
			if (i == *p_int_hang && j == *p_int_lie) {
				p_co->array[i][j] += 1;
				*p_object += 1;
			}
			else if (p_co->position[i][j] == '*') {
				p_co->array[i][j] = 0;
				n++;
			}
		}
	}
	*p_score_now = (p_co->array[*p_int_hang][*p_int_lie] - 1) * (n + 1) * 3;
	*p_score_sum += *p_score_now;
}

/*实现新值填充的函数
1-需要回车
2-不需要*/
void add_new(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, char judge='1')
{
	if (judge == '1') {
		char ch;
		cout << endl
			<< "按回车键进行新值填充...";
		while (1) {
			ch = _getch();
			if (ch == '\n' || ch == '\r') {
				break;
			}
		}
	}
	int i, j, m = 3;
	for (i = 1; i < *p_hang_num + 1; i++) {
		for (j = 1; j < *p_lie_num + 1; j++) {
			if (m < p_co->array[i][j]) {
				m = p_co->array[i][j];
			}
		}
	}
	for (i = 1; i < *p_hang_num + 1; i++) {
		for (j = 1; j < *p_lie_num + 1; j++) {
			if (p_co->array[i][j] == 0) {
				int p;
				if (m == 3) {
					p_co->array[i][j] = rand() % m + 1;
					p_co->position[i][j] = '*';
				}
				else if (m == 4) {
					p = rand() % 10000 + 1;
					if (p > 0 && p <= 9000) {
						p_co->array[i][j] = rand() % (m - 1) + 1;
						p_co->position[i][j] = '*';
					}
					else if (p > 9000 && p <= 10000) {
						p_co->array[i][j] = 4;
						p_co->position[i][j] = '*';
					}
				}
				else if (m == 5) {
					p = rand() % 10000 + 1;
					if (p > 0 && p <= 7500) {
						p_co->array[i][j] = rand() % (m - 2) + 1;
						p_co->position[i][j] = '*';
					}
					else if (p > 7500 && p <= 9000) {
						p_co->array[i][j] = 4;
						p_co->position[i][j] = '*';
					}
					else if (p > 9000 && p <= 10000) {
						p_co->array[i][j] = 5;
						p_co->position[i][j] = '*';
					}
				}
				else if (m == 6) {
					p = rand() % 10000 + 1;
					if (p > 0 && p <= 8000) {
						p_co->array[i][j] = rand() % (m - 2) + 1;
						p_co->position[i][j] = '*';
					}
					else if (p > 8000 && p <= 9500) {
						p_co->array[i][j] = 5;
						p_co->position[i][j] = '*';
					}
					else if (p > 9500 && p <= 10000) {
						p_co->array[i][j] = 6;
						p_co->position[i][j] = '*';
					}
				}
				else if (m > 6) {//大于6时的概率设置
					p = rand() % 10000 + 1;
					if (p > 0 && p <= 8000) {
						p_co->array[i][j] = rand() % (m - 3) + 1;
						p_co->position[i][j] = '*';
					}
					else if (p > 8000 && p <= 9000) {
						p_co->array[i][j] = (m - 2);
						p_co->position[i][j] = '*';
					}
					else if (p > 9000 && p <= 10000) {
						p_co->array[i][j] = rand() % 2 + m - 1;
						p_co->position[i][j] = '*';
					}
				}
			}
		}
	}
}

/*展示计分的函数*/
void print_current_score(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, int* p_goal, int* p_score_now, int* p_score_sum)
{
	cout << "本次得分：" << *p_score_now << " 总得分：" << *p_score_sum << " 合成目标：" << *p_goal << endl;
}