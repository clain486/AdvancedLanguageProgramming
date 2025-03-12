/* 2151140 ��07 ��ǫ */
/* �ڲ����鷽ʽʵ�ֵĸ����� */
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

/*��ӡ��ǰ����ĺ���*/
void print_current_array(int* p_hang_num, int* p_lie_num, coordinate* p_co)
{
	int i, j;
	cout << endl
		<< "��ǰ���飺" << endl
		<< "  |";
	for (i = 0; i < *p_lie_num; i++) {
		cout << setw(3) << i;
	}
	cout << endl << "--+";
	for (i = 0; i < *p_lie_num; i++) {
		cout << "---";
	}
	cout << "-" << endl;
	for (i = 1; i < *p_hang_num + 1; i++) {
		cout << (char)(i + 64) << " |";
		for (j = 1; j < *p_lie_num + 1; j++) {
			cout << setw(3) << p_co->array[i][j];
		}
		cout << endl;
	}
}

/*��������ĺ���*/
void input_position(int* p_hang_num, int* p_lie_num, char* p_char_hang, char* p_char_lie)
{
	int x, y;
	cout << endl << "������ĸ+������ʽ[����c2]����������꣺";
	cct_getxy(x, y);
	while (1) {
		cin >> *p_char_hang >> *p_char_lie;
		cin.clear();
		cin.ignore(65536, '\n');

		/*ͳһ��Сд*/
		if (*p_char_hang >= 97 && *p_char_hang <= *p_hang_num + 96) {
			*p_char_hang -= 32;
		}
		/*�ж�������ȷ��*/
		if (*p_char_hang >= 65 && *p_char_hang <= *p_hang_num + 64 && *p_char_lie >= 48 && *p_char_lie <= *p_lie_num + 47) {
			cout << "����Ϊ" << *p_char_hang << "��" << *p_char_lie << "��";
			cct_getxy(x, y);
			cct_showstr(x, y, " ", COLOR_BLACK, COLOR_WHITE, 32);
			cout << endl;
			break;
		}
		else {
			cout << "�����������������.";
			cct_showstr(x, y, " ", COLOR_BLACK, COLOR_WHITE, 64);
			cct_gotoxy(x, y);
		}
	}
}

/*�������char����ת��Ϊint���ֵĺ���*/
void trans_position_to_int(char* p_char_hang, char* p_char_lie, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	*p_int_hang = *p_char_hang - 64;
	*p_int_lie = *p_char_lie - 47;
	*p_object = p_co->array[*p_int_hang][*p_int_lie];
}

/*�����������ж��������ֵĺ���*/
void input_and_judge(int* p_hang_num, int* p_lie_num, char* p_char_hang, char* p_char_lie, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	while (1) {
		input_position(p_hang_num, p_lie_num, p_char_hang, p_char_lie);
		trans_position_to_int(p_char_hang, p_char_lie, p_int_hang, p_int_lie, p_object, p_co);
		int n = same_choose(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
		if (n == 0) {
			for (int i = 0; i < *p_hang_num + 2; i++) {
				for (int j = 0; j < *p_lie_num + 2; j++) {
					p_co->position[i][j] = '0';
				}
			}
			cout << "����ľ�������λ�ô���������ֵͬ������������" << endl;
			continue;
		}
		else {
			break;
		}
	}
}

/*����position����ѭ���жϵĺ������˵���1��Ҫ��ķǵݹ麯����*/
void same_choose_plus1(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	int i, j, k;
	for (k = 0; k < 10; k++) {
		for (i = 1; i < *p_hang_num + 1; i++) {
			for (j = 1; j < *p_lie_num; j++) {
				if (p_co->position[i][j] == '*' || p_co->position[i][j] == '+') {
					p_co->position[i][j] = '*';
					if (p_co->array[i - 1][j] == *p_object) {
						p_co->position[i - 1][j] = '*';
					}
					if (p_co->array[i + 1][j] == *p_object) {
						p_co->position[i + 1][j] = '*';
					}
					if (p_co->array[i][j - 1] == *p_object) {
						p_co->position[i][j - 1] = '*';
					}
					if (p_co->array[i][j + 1] == *p_object) {
						p_co->position[i][j + 1] = '*';
					}
				}
			}
		}
	}
}

/*����position���еݹ��жϵĺ������˵���2��Ҫ��� �ݹ麯���� */
void same_choose_plus2(int* p_hang_num, int* p_lie_num, int hang, int lie, int* p_object, coordinate* p_co)
{
	if (p_co->array[hang][lie] == *p_object) {
		p_co->position[hang][lie] = '*';
	}
	if ((p_co->array[hang - 1][lie] == *p_object) && (p_co->position[hang - 1][lie] != '*')) {
		p_co->position[hang - 1][lie] = '*';
		if (hang > 0) {
			same_choose_plus2(p_hang_num, p_lie_num, hang - 1, lie, p_object, p_co);
		}
	}
	if ((p_co->array[hang][lie - 1] == *p_object) && (p_co->position[hang][lie - 1] != '*')) {
		p_co->position[hang][lie - 1] = '*';
		if (lie > 0) {
			same_choose_plus2(p_hang_num, p_lie_num, hang, lie - 1, p_object, p_co);
		}
	}
	if ((p_co->array[hang][lie + 1] == *p_object) && (p_co->position[hang][lie + 1] != '*')) {
		p_co->position[hang][lie + 1] = '*';
		if (lie < *p_lie_num) {
			same_choose_plus2(p_hang_num, p_lie_num, hang, lie + 1, p_object, p_co);
		}
	}
	if ((p_co->array[hang + 1][lie] == *p_object) && (p_co->position[hang + 1][lie] != '*')) {
		p_co->position[hang + 1][lie] = '*';
		if (hang < *p_hang_num) {
			same_choose_plus2(p_hang_num, p_lie_num, hang + 1, lie, p_object, p_co);
		}
	}
}

/*��ӡ���ҽ������ĺ���*/
void print_choose(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	int i, j;
	int bg_color, fg_color;
	cout << endl
		<< "���ҽ�����飺" << endl
		<< "  |";
	for (i = 0; i < *p_lie_num; i++) {
		cout << setw(3) << i;
	}
	cout << endl << "--+";
	for (i = 0; i < *p_lie_num; i++) {
		cout << "---";
	}
	cout << "-" << endl;
	for (i = 1; i < *p_hang_num + 1; i++) {
		cout << (char)(i + 64) << " |";
		for (j = 1; j < *p_lie_num + 1; j++) {
			if (i == *p_int_hang && j == *p_int_lie) {
				cct_getcolor(bg_color, fg_color);
				cout << "  ";
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << p_co->position[i][j];
				cct_setcolor(bg_color, fg_color);
			}
			else {
				cout << setw(3) << p_co->position[i][j];
			}
		}
		cout << endl;
	}
}

/*
��ӡ��ǰ���飨��ͬɫ��ʶ���ĺ���--1
��ӡ��ֵͬ�鲢������飨��ͬɫ��ʶ���ĺ���--2
*/
void print_array_with_color(int* p_hang_num, int* p_lie_num, int* p_hang, int* p_lie, int* p_object, coordinate* p_co, char menu_choice)
{
	int i, j;
	int bg_color, fg_color;
	cout << endl;
	if (menu_choice == '1') {
		cout << "��ǰ����(��ͬɫ��ʶ)��" << endl;
	}
	else if (menu_choice == '2') {
		cout << "��ֵͬ�鲢�������(��ͬɫ��ʶ)��" << endl;
	}
	cout << "  |";
	for (i = 0; i < *p_lie_num; i++) {
		cout << setw(3) << i;
	}
	cout << endl << "--+";
	for (i = 0; i < *p_lie_num; i++) {
		cout << "---";
	}
	cout << "-" << endl;
	for (i = 1; i < *p_hang_num + 1; i++) {
		cout << (char)(i + 64) << " |";
		for (j = 1; j < *p_lie_num + 1; j++) {
			if (p_co->position[i][j] == '*' && *p_object < 10) {
				cct_getcolor(bg_color, fg_color);
				cout << "  ";
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << p_co->array[i][j];
				cct_setcolor(bg_color, fg_color);
			}
			else if (p_co->position[i][j] == '*' && *p_object >= 10) {
				cct_getcolor(bg_color, fg_color);
				cout << " ";
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << p_co->array[i][j];
				cct_setcolor(bg_color, fg_color);
			}
			else {
				cout << setw(3) << p_co->array[i][j];
			}
		}
		cout << endl;
	}
}

/*ȷ���Ƿ�����ڵ���ֵͬ�ϲ��ĺ���*/
char merge_confirm(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	int x, y;
	cout << "��ȷ���Ƿ�����ڵ���ֵͬ�ϲ���" << char(*p_int_hang + 64) << char(*p_int_lie + 47) << "��(Y/N/Q)��";
	cct_getxy(x, y);
	while (1) {
		cct_gotoxy(x, y);
		char judge = _getch();
		if (judge == 'y' || judge == 'Y') {
			cout << judge << endl;
			return 'Y';
		}
		else if (judge == 'n' || judge == 'N') {
			cout << judge << endl;
			return 'N';
		}
		else if (judge == 'q' || judge == 'Q') {
			cout << judge << endl;
			return 'Q';
		}
	}
}

/*�����0�ĺ���*/
void fall(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	char ch;
	cout << endl
		<< "���س����������������0����...";
	while (1) {
		ch = _getch();
		if (ch == '\n' || ch == '\r') {
			break;
		}
	}
	int i, j, k;
	for (i = 2; i < *p_hang_num + 1; i++) {
		for (j = 1; j < *p_lie_num + 1; j++) {
			if (p_co->array[i][j] == 0) {
				for (k = i; k > 1; k--) {
					p_co->array[k][j] = p_co->array[k - 1][j];
				}
				p_co->array[1][j] = 0;
			}
		}
	}
	for (i = 0; i < *p_hang_num + 2; i++) {
		for (j = 0; j < *p_lie_num + 2; j++) {
			p_co->position[i][j] = '0';
		}
	}
}

/*��ӡ��0������飨��ͬɫ��ʶ���ĺ���*/
void print_after_fall(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	int i, j;
	int bg_color, fg_color;
	cout << endl
		<< "��0�������(��ͬɫ��ʶ)��" << endl
		<< "  |";
	for (i = 0; i < *p_lie_num; i++) {
		cout << setw(3) << i;
	}
	cout << endl << "--+";
	for (i = 0; i < *p_lie_num; i++) {
		cout << "---";
	}
	cout << "-" << endl;
	for (i = 1; i < *p_hang_num + 1; i++) {
		cout << (char)(i + 64) << " |";
		for (j = 1; j < *p_lie_num + 1; j++) {
			if (p_co->array[i][j] == 0) {
				cct_getcolor(bg_color, fg_color);
				cout << "  ";
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << p_co->array[i][j];
				cct_setcolor(bg_color, fg_color);
			}
			else {
				cout << setw(3) << p_co->array[i][j];
			}
		}
		cout << endl;
	}
}

/*��ӡ��ֵ��������飨��ͬɫ��ʶ��*/
void print_after_new(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	int i, j;
	int bg_color, fg_color;
	cout << endl
		<< "��ֵ���������(��ͬɫ��ʶ)��" << endl
		<< "  |";
	for (i = 0; i < *p_lie_num; i++) {
		cout << setw(3) << i;
	}
	cout << endl << "--+";
	for (i = 0; i < *p_lie_num; i++) {
		cout << "---";
	}
	cout << "-" << endl;
	for (i = 1; i < *p_hang_num + 1; i++) {
		cout << (char)(i + 64) << " |";
		for (j = 1; j < *p_lie_num + 1; j++) {
			if (p_co->position[i][j] == '*' && p_co->array[i][j] < 10) {
				cct_getcolor(bg_color, fg_color);
				cout << "  ";
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << p_co->array[i][j];
				cct_setcolor(bg_color, fg_color);
			}
			else if (p_co->position[i][j] == '*' && p_co->array[i][j] >= 10) {
				cct_getcolor(bg_color, fg_color);
				cout << " ";
				cct_setcolor(COLOR_HYELLOW, COLOR_BLACK);
				cout << p_co->array[i][j];
				cct_setcolor(bg_color, fg_color);
			}
			else {
				cout << setw(3) << p_co->array[i][j];
			}
		}
		cout << endl;
	}
	for (i = 0; i < *p_hang_num + 2; i++) {
		for (j = 0; j < *p_lie_num + 2; j++) {
			p_co->position[i][j] = '0';
		}
	}
}

/*�ϳɵ������ϵĺ������˵���3����Ӧ�����Ϻ�����*/
void merge_for_one(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, int* p_goal, int* p_score_now, int* p_score_sum)
{
	int hang = *p_int_hang;
	int lie = *p_int_lie;
	char confirm = merge_confirm(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
	if (confirm == 'Y') {
		merge_near(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
		print_array_with_color(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '2');
		print_current_score(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
		fall(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
		print_after_fall(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
		add_new(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '1');
		print_after_new(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
	}
	else {
		;
	}
}

/*�ϳ��������ϵĺ������˵���3����Ӧ�����Ϻ�����*/
void merge_for_all(int* p_hang_num, int* p_lie_num, int* p_int_hang, char* p_char_hang, char* p_char_lie, int* p_int_lie, int* p_object, coordinate* p_co, int* p_goal, int* p_score_now, int* p_score_sum)
{

	while (1) {
		print_current_array(p_hang_num, p_lie_num, p_co);
		input_and_judge(p_hang_num, p_lie_num, p_char_hang, p_char_lie, p_int_hang, p_int_lie, p_object, p_co);
		int hang = *p_int_hang;
		int lie = *p_int_lie;
		same_choose_plus2(p_hang_num, p_lie_num, hang, lie, p_object, p_co);
		print_choose(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
		print_array_with_color(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '1');
		char confirm = merge_confirm(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
		if (confirm == 'Y') {
			merge_near(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
			print_array_with_color(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '2');
			cout << endl;
			print_current_score(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
			fall(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
			print_after_fall(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
			add_new(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '1');
			print_after_new(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
			cout << endl
				<< "���κϳɽ��������س���������һ�εĺϳ�..." << endl;
			int n = 0;
			for (int i = 1; i < *p_hang_num + 1; i++) {
				for (int j = 1; j < *p_lie_num + 1; j++) {
					n += same_choose(p_hang_num, p_lie_num, i, j, p_co);
				}
			}
			if (n == 0) {
				cout << "�޿ɺϲ������Ϸ������";
				break;
			}
			int bg, fg;
			while (1) {
				char ch = _getch();
				if (ch == '\n' || ch == '\r') {
					break;
				}
			}
			if (*p_object >= *p_goal) {
				cct_getcolor(bg, fg);
				cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
				cout << "�Ѿ��ϳɵ�" << *p_object;
				cct_setcolor(bg, fg);
				cout << endl
					<< "���س������������Ŀ�����..." << endl;
				(*p_goal)++;
				while (1) {
					char ch = _getch();
					if (ch == '\n' || ch == '\r') {
						break;
					}
				}
			}
			continue;
		}
		else if (confirm == 'N') {
			for (int i = 0; i < *p_hang_num + 2; i++) {
				for (int j = 0; j < *p_lie_num + 2; j++) {
					p_co->position[i][j] = '0';
				}
			}
			continue;
		}
		else if (confirm == 'Q') {
			break;
		}
	}
}

