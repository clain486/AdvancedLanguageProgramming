/* 2151140 ��07 ��ǫ */
/* һЩ�ڲ�����/ͼ�η�ʽ���õĺ��������жϽ����� */
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

/*��С��������жϺ���*/
void need_end()
{
	int x, y;
	char the_end[4];
	cct_getxy(x, y);
	y += 1;
	cout << endl
		<< "��С�������������End����...                                                      ";
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
			cct_showstr(0, y + 1, "�����������������                                                  ", COLOR_BLACK, COLOR_WHITE, 1);
			cct_gotoxy(x, y);
		}
	}
}

/*�������в���¼�ĺ���*/
void input_hanglie(int* p_hang_num, int* p_lie_num)
{
	cct_cls();

	while (1) {
		cout << "����������(5-8)��" << endl;
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
		cout << "����������(5-10)��" << endl;
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

/*����Ŀ�겢��¼�ĺ���*/
void input_goal(int* p_goal)
{
	while (1) {
		cout << "������ϳ�Ŀ��(5-20)��" << endl;
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

/*�������鲢��¼�ĺ���*/
void generate_array(int* p_hang_num, int* p_lie_num, coordinate* p_co)
{
	/*���Ϊ���鸳ֵ1-3����¼*/
	int i, j;
	for (i = 1; i < *p_hang_num + 1; i++) {
		for (j = 1; j < *p_lie_num + 1; j++) {
			p_co->array[i][j] = rand() % 3 + 1;
		}
	}
}

/*�ж�������ͬ��ĺ�����������*/
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

/*ʵ�ֺϲ�ͬʱ�Ƿֵĺ���*/
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

/*ʵ����ֵ���ĺ���
1-��Ҫ�س�
2-����Ҫ*/
void add_new(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, char judge='1')
{
	if (judge == '1') {
		char ch;
		cout << endl
			<< "���س���������ֵ���...";
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
				else if (m > 6) {//����6ʱ�ĸ�������
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

/*չʾ�Ʒֵĺ���*/
void print_current_score(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, int* p_goal, int* p_score_now, int* p_score_sum)
{
	cout << "���ε÷֣�" << *p_score_now << " �ܵ÷֣�" << *p_score_sum << " �ϳ�Ŀ�꣺" << *p_goal << endl;
}