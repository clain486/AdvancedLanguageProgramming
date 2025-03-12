/* 2151140 信07 王谦 */
/* 主函数及菜单部分函数 */
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
		<< "1.命令行找出可合成项并标识（非递归）" << endl
		<< "2.命令行找出可合成项并标识（递归）" << endl
		<< "3.命令行完成一次合成（分步骤显示）" << endl
		<< "4.命令行完整版（分步骤显示）" << endl
		<< "5.伪图形界面显示初始数组（无分隔线）" << endl
		<< "6.伪图形界面显示初始数组（有分隔线）" << endl
		<< "7.伪图形界面下用箭头键 / 鼠标选择当前色块" << endl
		<< "8.伪图形界面完成一次合成（分步骤）" << endl
		<< "9.伪图形界面完整版(支持鼠标)" << endl
		<< "----------------------------------------" << endl
		<< "A.命令行界面（网络自动解 - 基本版）" << endl
		//<< "B.伪图形界面（网络自动解 - 基本版）" << endl
		//<< "C.命令行界面（网络自动解 - 竞赛版）" << endl
		<< "----------------------------------------" << endl
		<< "0.退出" << endl
		<< "----------------------------------------" << endl
		<< "[请选择:] ";
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
		
		/*行列总数*/
		int hang_num, * p_hang_num = &hang_num;
		int lie_num, * p_lie_num = &lie_num;

		/*合成目标*/
		int goal, * p_goal = &goal;

		/*得分*/
		int score_now = 0, * p_score_now = &score_now;
		int score_sum = 0, * p_score_sum = &score_sum;
		
		/*输入坐标的char位置*/
		char char_hang, * p_char_hang = &char_hang;
		char char_lie, * p_char_lie = &char_lie;
		
		/*输入坐标的int位置*/
		int int_hang, * p_int_hang = &int_hang;
		int int_lie, * p_int_lie = &int_lie;

		/*输入坐标的int数字*/
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