/* 2151140 ��07 ��ǫ */
/* ���������˵����ֺ��� */
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

char menu()
{
	srand((unsigned int)(time(0)));
	cct_cls();
	cout << "---------------------------------------" << endl
		<< "1.�������ҳ��ɺϳ����ʶ���ǵݹ飩" << endl
		<< "2.�������ҳ��ɺϳ����ʶ���ݹ飩" << endl
		<< "3.���������һ�κϳɣ��ֲ�����ʾ��" << endl
		<< "4.�����������棨�ֲ�����ʾ��" << endl
		<< "5.αͼ�ν�����ʾ��ʼ���飨�޷ָ��ߣ�" << endl
		<< "6.αͼ�ν�����ʾ��ʼ���飨�зָ��ߣ�" << endl
		<< "7.αͼ�ν������ü�ͷ�� / ���ѡ��ǰɫ��" << endl
		<< "8.αͼ�ν������һ�κϳɣ��ֲ��裩" << endl
		<< "9.αͼ�ν���������(֧�����)" << endl
		<< "----------------------------------------" << endl
		<< "A.�����н��棨�����Զ��� - �����棩" << endl
		//<< "B.αͼ�ν��棨�����Զ��� - �����棩" << endl
		//<< "C.�����н��棨�����Զ��� - �����棩" << endl
		<< "----------------------------------------" << endl
		<< "0.�˳�" << endl
		<< "----------------------------------------" << endl
		<< "[��ѡ��:] ";
	while (1) {
		char menu_choice = _getch();
		if ((menu_choice >= 48 && menu_choice <= 57) || (menu_choice >= 65 && menu_choice <= 67)) {
			putchar(menu_choice);
			Sleep(100);
			return menu_choice;
		}
		else if (menu_choice >= 97 && menu_choice <= 99) {
			putchar(menu_choice);
			Sleep(100);
			return (menu_choice - 32);
		}
		else {
			continue;
		}
	}
}

int main()
{
	int L = 1;
	while (L) {
		struct coordinate co;		
		struct coordinate* p_co = &co;

		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 12; j++) {
				p_co->array[i][j] = 0;
				p_co->position[i][j] = '0';
			}
		}
		
		/*��������*/
		int hang_num, * p_hang_num = &hang_num;
		int lie_num, * p_lie_num = &lie_num;

		/*�ϳ�Ŀ��*/
		int goal, * p_goal = &goal;

		/*�÷�*/
		int score_now = 0, * p_score_now = &score_now;
		int score_sum = 0, * p_score_sum = &score_sum;
		
		/*���������charλ��*/
		char char_hang, * p_char_hang = &char_hang;
		char char_lie, * p_char_lie = &char_lie;
		
		/*���������intλ��*/
		int int_hang, * p_int_hang = &int_hang;
		int int_lie, * p_int_lie = &int_lie;

		/*���������int����*/
		int object, * p_object = &object;
		
		char menu_choice = menu();
		switch (menu_choice) {
			case '1':
				input_hanglie(p_hang_num, p_lie_num);
				generate_array(p_hang_num, p_lie_num, p_co);
				print_current_array(p_hang_num, p_lie_num, p_co);
				input_and_judge(p_hang_num, p_lie_num, p_char_hang, p_char_lie, p_int_hang, p_int_lie, p_object, p_co);
				same_choose_plus1(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
				print_choose(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
				print_array_with_color(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co,'1');
				need_end();
				break;
			case '2':
				input_hanglie(p_hang_num, p_lie_num);
				generate_array(p_hang_num, p_lie_num, p_co);
				print_current_array(p_hang_num, p_lie_num, p_co);
				input_and_judge(p_hang_num, p_lie_num, p_char_hang, p_char_lie, p_int_hang, p_int_lie, p_object, p_co);
				same_choose_plus2(p_hang_num, p_lie_num, int_hang, int_lie, p_object, p_co);
				print_choose(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
				print_array_with_color(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co,'1');
				need_end();
				break;
			case '3':
				input_hanglie(p_hang_num, p_lie_num);
				input_goal(p_goal);
				generate_array(p_hang_num, p_lie_num, p_co);
				print_current_array(p_hang_num, p_lie_num, p_co);
				input_and_judge(p_hang_num, p_lie_num, p_char_hang, p_char_lie, p_int_hang, p_int_lie, p_object, p_co);
				same_choose_plus2(p_hang_num, p_lie_num, int_hang, int_lie, p_object, p_co);
				print_choose(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
				print_array_with_color(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co,'1');
				merge_for_one(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
				need_end();
				break;
			case '4':
				input_hanglie(p_hang_num, p_lie_num);
				input_goal(p_goal);
				generate_array(p_hang_num, p_lie_num, p_co);
				merge_for_all(p_hang_num, p_lie_num, p_int_hang, p_char_hang, p_char_lie, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
				need_end();
				break;
			case '5':
				input_hanglie(p_hang_num, p_lie_num);
				generate_array(p_hang_num, p_lie_num, p_co);
				my_setconsoleborder(p_hang_num, p_lie_num, p_goal, '1');
				print_visualized_array1(p_hang_num, p_lie_num, p_co);
				need_end();
				break;
			case '6':
				input_hanglie(p_hang_num, p_lie_num);
				generate_array(p_hang_num, p_lie_num, p_co);
				my_setconsoleborder(p_hang_num, p_lie_num, p_goal, '2');
				print_visualized_array2(p_hang_num, p_lie_num, p_co);
				need_end();
				break;
			case '7':
				input_hanglie(p_hang_num, p_lie_num);
				generate_array(p_hang_num, p_lie_num, p_co);
				my_setconsoleborder(p_hang_num, p_lie_num, p_goal, '2');
				print_visualized_array2(p_hang_num, p_lie_num, p_co);
				choose_with_keymouse(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum,'1');
				need_end();
				break;
			case '8':
				input_hanglie(p_hang_num, p_lie_num);
				generate_array(p_hang_num, p_lie_num, p_co);
				my_setconsoleborder(p_hang_num, p_lie_num, p_goal, '2');
				print_visualized_array2(p_hang_num, p_lie_num, p_co);
				choose_with_keymouse(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum, '2');
				need_end();
				break;
			case '9':
				input_hanglie(p_hang_num, p_lie_num);
				input_goal(p_goal);
				generate_array(p_hang_num, p_lie_num, p_co);
				my_setconsoleborder(p_hang_num, p_lie_num, p_goal, '2');
				print_visualized_array2(p_hang_num, p_lie_num, p_co);
				endless_keymouse(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
				need_end();
			case 'A':
				input_hanglie(p_hang_num, p_lie_num);
				main2(p_hang_num, p_lie_num, p_co);
				need_end();
				break;
			case 'B':
				break;
			case 'C':
				break;
			case '0':
				L = 0;
				break;
		}
	}
	return 0;
}