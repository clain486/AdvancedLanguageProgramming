/* 2151140 信07 王谦 */
/* cmd伪图形界面方式实现的各函数 */
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

/*设置窗口大小并展示的函数
--1为菜单项5
--2为菜单项6*/
void my_setconsoleborder(int* p_hang_num, int* p_lie_num, int* p_goal, char judge)
{
	int cols;         //新的列数
	int lines;        //新的行数
	if (judge == '1') {
		cols = *p_lie_num * 6 + 7;
		lines = *p_hang_num * 3 + 8;
	}
	else {
		cols = *p_lie_num * 8 + 5;
		lines = *p_hang_num * 4 + 7;
	}

	cct_cls();
	cct_setconsoleborder(cols, lines, cols + 256, lines + 256);
	cct_gotoxy(0, 0);
	cout << "屏幕当前设置为：" << lines << "行" << cols << "列" << endl;
}

/*伪图形无分隔线打印数组（菜单项5的函数）*/
void print_visualized_array1(int* p_hang_num, int* p_lie_num, coordinate* p_co)
{
	int cols = *p_lie_num * 6 + 7;
	int lines = *p_hang_num * 3 + 8;
	char char_hang = 'A';

	int x = 6, y = 1;
	int x1 = 0, y1 = y + 3;
	int x2 = 2, y2 = 2;
	int x3 = 4, y3 = 3;

	cct_setcolor();//0-黑 7-白 15-亮白
	/*打横轴*/
	cct_gotoxy(x, y);
	for (int i = 0; i < *p_lie_num; i++) {
		cout << setiosflags(ios::left) << setw(6) << i;
	}
	/*打纵轴*/
	for (int i = 0; i < *p_hang_num; i++, char_hang++, y1 += 3) {
		cct_gotoxy(x1, y1);
		cout << char_hang;
	}

	/*打黑框和白底*/
	cct_setcolor(15, 0);
	cct_gotoxy(x2, y2);
	/*首行*/
	cout << "┏";
	for (int i = 0; i < *p_lie_num * 3; i++) {
		cout << "━";
		Sleep(3);
	}
	cout << "┓";
	/*中间*/
	for (int i = 0; i < *p_hang_num * 3; i++) {
		cct_gotoxy(x2, ++y2);
		cout << "┃";
		for (int j = 0; j < *p_lie_num * 3; j++) {
			cout << "  ";
			Sleep(3);
		}
		cout << "┃";
	}
	/*尾行*/
	cct_gotoxy(x2, ++y2);
	cout << "┗";
	for (int i = 0; i < *p_lie_num * 3; i++) {
		cout << "━";
		Sleep(3);
	}
	cout << "┛";
	cct_setcolor();

	/*打每个图形*/
	cct_gotoxy(x3, y3);
	for (int i = 1; i < *p_hang_num + 1; i++, y3 += 3) {
		int x4 = x3;
		for (int j = 1; j < *p_lie_num + 1; j++, x4 += 6) {
			cct_setcolor((p_co->array[i][j] % 14), 0);
			cct_gotoxy(x4, y3);
			cout << "┏━┓";
			cct_gotoxy(x4, y3 + 1);
			cout << "┃" << setw(2) << p_co->array[i][j] << "┃";
			cct_gotoxy(x4, y3 + 2);
			cout << "┗━┛";
		}
	}
	cct_setcolor();
	cct_gotoxy(0, lines - 4);
}

/*伪图形有分隔线打印数组（菜单项6的函数）*/
void print_visualized_array2(int* p_hang_num, int* p_lie_num, coordinate* p_co)
{
	int cols = *p_lie_num * 8 + 5;
	int lines = *p_hang_num * 4 + 7;
	char char_hang = 'A';

	int x = 6, y = 1;
	int x1 = 0, y1 = y + 3;
	int x2 = 2, y2 = 2;

	cct_setcolor();//0-黑 7-白 15-亮白
	/*打横轴*/
	cct_gotoxy(x, y);
	for (int i = 0; i < *p_lie_num; i++) {
		cout << setiosflags(ios::left) << setw(8) << i;
	}
	/*打纵轴*/
	for (int i = 0; i < *p_hang_num; i++, char_hang++, y1 += 4) {
		cct_gotoxy(x1, y1);
		cout << char_hang;
	}

	/*打黑框和白底*/
	cct_setcolor(15, 0);
	cct_gotoxy(x2, y2);
	/*首行*/
	cout << "┏";
	for (int i = 0; i < *p_lie_num - 1; i++) {
		cout << "━━━┳";
		Sleep(3);
	}
	cout << "━━━┓";
	/*中间*/
	for (int i = 0; i < *p_hang_num - 1; i++) {
		cct_gotoxy(x2, ++y2);
		cout << "┃";
		for (int j = 0; j < *p_lie_num; j++) {
			cout << "      ┃";
			Sleep(3);
		}
		cct_gotoxy(x2, ++y2);
		cout << "┃";
		for (int j = 0; j < *p_lie_num; j++) {
			cout << "      ┃";
			Sleep(3);
		}
		cct_gotoxy(x2, ++y2);
		cout << "┃";
		for (int j = 0; j < *p_lie_num; j++) {
			cout << "      ┃";
			Sleep(3);
		}
		cct_gotoxy(x2, ++y2);
		cout << "┣";
		for (int j = 0; j < *p_lie_num; j++) {
			cout << "━━━╋";
			Sleep(3);
		}
	}
	/*尾行*/
	cct_gotoxy(x2, ++y2);
	cout << "┃";
	for (int j = 0; j < *p_lie_num; j++) {
		cout << "      ┃";
		Sleep(3);
	}
	cct_gotoxy(x2, ++y2);
	cout << "┃";
	for (int j = 0; j < *p_lie_num; j++) {
		cout << "      ┃";
		Sleep(3);
	}
	cct_gotoxy(x2, ++y2);
	cout << "┃";
	for (int j = 0; j < *p_lie_num; j++) {
		cout << "      ┃";
		Sleep(3);
	}
	cct_gotoxy(x2, ++y2);
	cout << "┗";
	for (int i = 0; i < *p_lie_num - 1; i++) {
		cout << "━━━┻";
		Sleep(3);
	}
	cout << "━━━┛";
	cct_setcolor();
	print_all_color(p_hang_num, p_lie_num, p_co);
	cct_gotoxy(0, lines - 4);
}

/*还原每个图形的函数*/
void print_all_color(int* p_hang_num, int* p_lie_num, coordinate* p_co)
{
	int x3 = 4, y3 = 3;
	cct_gotoxy(x3, y3);
	for (int i = 1; i < *p_hang_num + 1; i++, y3 += 4) {
		int x4 = x3;
		for (int j = 1; j < *p_lie_num + 1; j++, x4 += 8) {
			int bg = p_co->array[i][j] % 14;
			cct_setcolor(bg, 0);
			cct_gotoxy(x4, y3);
			cout << "┏━┓";
			cct_gotoxy(x4, y3 + 1);
			cout << "┃" << setw(2) << p_co->array[i][j] << "┃";
			cct_gotoxy(x4, y3 + 2);
			cout << "┗━┛";
		}
	}
	cct_setcolor();
}

/*
键盘鼠标选择的函数
--1为菜单项7
--2为菜单项8
--3为菜单项9
*/
int choose_with_keymouse(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, int* p_goal, int* p_score_now, int* p_score_sum, char judge)
{
	int cols = *p_lie_num * 8 + 5;
	int lines = *p_hang_num * 4 + 7;

	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop = 1;

	cct_setcursor(CURSOR_INVISIBLE);	//关闭光标
	cct_enable_mouse();

	int x_rem = 1, y_rem = 1;
	while (loop) {

		for (int a = 0; a < *p_hang_num + 2; a++) {
			for (int b = 0; b < *p_lie_num + 2; b++) {
				p_co->position[a][b] = '0';
			}
		}

		int t = 0;
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		int x = (X + 4) / 8, y = (Y + 1) / 4;
		if (ret == CCT_MOUSE_EVENT) {
			cct_gotoxy(0, lines - 4);
			cout << "[当前鼠标] ";
			switch (maction) {
				case MOUSE_ONLY_MOVED:
					if (x > 0 && x < *p_lie_num + 1 && y > 0 && y < *p_hang_num + 1) {
						cout << (char)(y + 64) << "行" << x - 1 << "列                                                           ";
						if (x_rem != x || y_rem != y) {
							changcolor_for_one(y_rem, x_rem, p_co, 0);
						}
						changcolor_for_one(y, x, p_co, 7);
						x_rem = x;
						y_rem = y;
					}
					else {
						cout << "位置非法                                                                   ";
					}
					break;
				case MOUSE_LEFT_BUTTON_CLICK:			//按下左键
					if (x > 0 && x < *p_lie_num + 1 && y > 0 && y < *p_hang_num + 1) {
						if (judge == '1') {
							cout << "选中了" << (char)(y + 64) << "行" << x - 1 << "列                                              " << endl;
							cct_gotoxy(0, lines - 3);
							judge = '1';
							loop = 0;
						}
						else {
							*p_int_hang = y;
							*p_int_lie = x;
							*p_object = p_co->array[y][x];
							int loop2 = 1;
							if (same_choose(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co)) {
								same_choose_plus2(p_hang_num, p_lie_num, *p_int_hang, *p_int_lie, p_object, p_co);
								merge_confirm_visualized(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
								t = 1;
							}
							else {
								cct_setcolor(0, 6);
								cout << "周围无相同值，";
								cct_setcolor();
								cout << "箭头键/鼠标移动，回车键/单击左键选择，Q或单击右键结束                                         " << endl;
								break;
							}
							cct_disable_mouse();
							cct_enable_mouse();
							
							while (loop2) {
								ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
								int x0 = (X + 4) / 8, y0 = (Y + 1) / 4;
								if (ret == CCT_MOUSE_EVENT) {
									if (maction == MOUSE_LEFT_BUTTON_CLICK && t == 1 && x == x0 && y == y0) {
										loop = 0;
										loop2 = 0;
									}
									else if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
										judge = '1';
										loop = 0;
										loop2 = 0;
									}
									else if (maction == MOUSE_ONLY_MOVED && (x != x0 || y != y0)) {
										print_all_color(p_hang_num, p_lie_num, p_co);
										loop2 = 0;
									}
								}
								else if (ret == CCT_KEYBOARD_EVENT) {
									if (keycode1 == 224) {
										print_all_color(p_hang_num, p_lie_num, p_co);
										loop2 = 0;
									}
									else if (keycode1 == 13 && t == 1) {
										loop = 0;
										loop2 = 0;
									}
									else if (keycode1 == 'q' || keycode1 == 'Q') {
										judge = '1';
										loop = 0;
										loop2 = 0;
									}
								}
							}//end_of_loop2
						}
					}
					break;
				case MOUSE_RIGHT_BUTTON_CLICK:			//按下右键
					if (x > 0 && x <= *p_lie_num && y > 0 && y <= *p_hang_num) {
						if (judge == '1') {
							cout << "选中了" << (char)(y + 64) << "行" << x - 1 << "列                                              " << endl;
							cct_gotoxy(0, lines - 3);
							judge = '1';
							loop = 0;
						}
						else {
							judge = '1';
							loop = 0;
						}
					}
					else {
						cout << "位置非法                                              ";
					}
					break;
				default:
					break;
			} //end of switch(maction)
		} //end of if (CCT_MOUSE_EVENT)
		else if (ret == CCT_KEYBOARD_EVENT) {
			cct_gotoxy(0, lines - 4);
			x = x_rem;
			y = y_rem;
			cout << "[当前键盘] ";
			if (x > 0 && x < *p_lie_num + 1 && y > 0 && y < *p_hang_num + 1) {
				switch (keycode1) {
					case 224:
						switch (keycode2) {
							case KB_ARROW_UP:
								//cout << "上箭头    ";
								if (y == 1) {
									y = *p_hang_num;
								}
								else {
									--y;
								}
								cout << (char)(y + 64) << "行" << x - 1 << "列                                                               ";
								if (x_rem != x || y_rem != y) {
									changcolor_for_one(y_rem, x_rem, p_co, 0);
								}
								changcolor_for_one(y, x, p_co, 7);
								x_rem = x;
								y_rem = y;
								break;
							case KB_ARROW_DOWN:
								//cout << "下箭头    ";
								if (y == *p_hang_num) {
									y = 1;
								}
								else {
									++y;
								}
								cout << (char)(y + 64) << "行" << x - 1 << "列                                                                 ";
								if (x_rem != x || y_rem != y) {
									changcolor_for_one(y_rem, x_rem, p_co, 0);
								}
								changcolor_for_one(y, x, p_co, 7);
								x_rem = x;
								y_rem = y;
								break;
							case KB_ARROW_LEFT:
								//cout << "左箭头    ";
								if (x == 1) {
									x = *p_lie_num;
								}
								else {
									--x;
								}
								cout << (char)(y + 64) << "行" << x - 1 << "列                                                                  ";
								if (x_rem != x || y_rem != y) {
									changcolor_for_one(y_rem, x_rem, p_co, 0);
								}
								changcolor_for_one(y, x, p_co, 7);
								x_rem = x;
								y_rem = y;
								break;
							case KB_ARROW_RIGHT:
								//cout << "右箭头    ";
								if (x == *p_lie_num) {
									x = 1;
								}
								else {
									++x;
								}
								cout << (char)(y + 64) << "行" << x - 1 << "列                                                                  ";
								if (x_rem != x || y_rem != y) {
									changcolor_for_one(y_rem, x_rem, p_co, 0);
								}
								changcolor_for_one(y, x, p_co, 7);
								x_rem = x;
								y_rem = y;
								break;
						}
						break;
					case 13:
						if (judge == '1') {
							cout << "选中了" << (char)(y + 64) << "行" << x - 1 << "列                                                         " << endl;
							cct_gotoxy(0, lines - 3);
							judge = '1';
							loop = 0;
						}
						else {
							*p_int_hang = y;
							*p_int_lie = x;
							*p_object = p_co->array[y][x];
							if (same_choose(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co)) {
								same_choose_plus2(p_hang_num, p_lie_num, *p_int_hang, *p_int_lie, p_object, p_co);
								merge_confirm_visualized(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
								t = 1;
							}
							else {
								cct_setcolor(0, 6);
								cout << "周围无相同值，";
								cct_setcolor();
								cout << "箭头键/鼠标移动，回车键/单击左键选择，Q或单击右键结束                                          " << endl;
							}
							int loop2 = 1;
							while (loop2) {
								ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
								int x0 = (X + 4) / 8, y0 = (Y + 1) / 4;
								if (ret == CCT_MOUSE_EVENT) {
									if (maction == MOUSE_LEFT_BUTTON_CLICK && t == 1 && x == x0 && y == y0) {
										loop = 0;
										loop2 = 0;
									}
									else if (maction == MOUSE_RIGHT_BUTTON_CLICK) {
										judge = '1';
										loop = 0;
										loop2 = 0;
									}
									else if (maction == MOUSE_ONLY_MOVED && (x != x0 || y != y0)) {
										print_all_color(p_hang_num, p_lie_num, p_co);
										loop2 = 0;
									}
								}
								else if (ret == CCT_KEYBOARD_EVENT) {
									if (keycode1 == 224) {
										print_all_color(p_hang_num, p_lie_num, p_co);
										loop2 = 0;
									}
									else if (keycode1 == 13 && t == 1) {
										loop = 0;
										loop2 = 0;
									}
									else if (keycode1 == 'q' || keycode1 == 'Q') {
										judge = '1';
										loop = 0;
										loop2 = 0;
									}
								}
							}//end_of_loop2
						}
						break;
					case 'q':
					case 'Q':
						judge = '1';
						loop = 0;
						break;
					default:
						break;
				}//end of swicth(keycode1)
			}//end of if(x > 0 && x < *p_lie_num + 1 && y > 0 && y < *p_hang_num + 1)
		}//end of else if(ret == CCT_KEYBOARD_EVENT）
	} //end of while(1)
	if (judge == '1') {
		cct_disable_mouse();	//禁用鼠标
		cct_setcursor(CURSOR_VISIBLE_NORMAL);	//打开光标
		cct_gotoxy(0, lines - 4);
		return 0;
	}
	else if(judge=='2') {
		merge_near(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
		merge_visualized(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '2');
		cct_gotoxy(0, lines - 4);
		cout << "合成完成，回车键/单击左键下落0                                                                       ";
		need_judge(13);
		fall_visualized(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
		cct_gotoxy(0, lines - 4);
		cout << "下落0完成，回车键/单击左键填充新值                                                                   ";
		need_judge(13);
		add_new(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '2');
		print_all_color(p_hang_num, p_lie_num, p_co);
		cct_gotoxy(0, lines - 4);
		cct_setcolor(0, 6);
		cout << "本次合成结束，按C/单击左键继续新一次的合成                                                           ";
		cct_setcolor();
		need_judge('c', 'C');
	}
	else if (judge == '3') {
		merge_near(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
		merge_visualized(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '2');
		fall_visualized(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co);
		Sleep(50);
		add_new(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, '2');
		print_all_color(p_hang_num, p_lie_num, p_co);
	}
	cct_gotoxy(0, lines - 4);
	return 1;
}

/*菜单项9需要的循环整合的函数*/
void endless_keymouse(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, int* p_goal, int* p_score_now, int* p_score_sum)
{
	int lines = *p_hang_num * 4 + 7;
	int key = 1;
	while (key) {
		key = choose_with_keymouse(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum, '3');
		cct_gotoxy(0, 0);
		print_current_score(p_hang_num, p_lie_num, p_int_hang, p_int_lie, p_object, p_co, p_goal, p_score_now, p_score_sum);
		int n = 0;
		for (int i = 1; i < *p_hang_num + 1; i++) {
			for (int j = 1; j < *p_lie_num + 1; j++) {
				n += same_choose(p_hang_num, p_lie_num, i, j, p_co);
			}
		}
		if (n == 0) {
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			cct_gotoxy(0, lines - 4);
			cout << "无可合并的项，游戏结束！";
			cct_setcolor();
			cout << "按Q/单击鼠标左键退出                                                 " << endl;
			need_judge('q','Q');
			cct_gotoxy(0, lines - 4);
			cout << "                                                                                          " << endl;
			break;
		}
		if (*p_object >= *p_goal) {
			cct_setcolor(COLOR_BLACK, COLOR_HYELLOW);
			cct_gotoxy(0, lines - 4);
			cout << "已经合成到，" << *p_object;
			cct_setcolor();
			cout << "按回车键/单击左键继续向更高目标进发                                         " << endl;
			(*p_goal)++;
			need_judge(13);
		}
	}
	cct_gotoxy(0, lines - 4);
}

/*继续进行需要的提示输入函数*/
void need_judge(char key1, char key2)
{
	int X = 0, Y = 0;
	int ret, maction;
	int keycode1, keycode2;
	int loop3 = 1;

	cct_disable_mouse();
	cct_enable_mouse();
	while (loop3) {
		ret = cct_read_keyboard_and_mouse(X, Y, maction, keycode1, keycode2);
		if (ret == CCT_MOUSE_EVENT) {
			switch (maction) {
				case MOUSE_LEFT_BUTTON_CLICK:
					loop3 = 0;
					break;
			}
		}
		else if (ret == CCT_KEYBOARD_EVENT) {
			if (keycode1 == key1 || keycode1 == key2) {
				loop3 = 0;
			}
		}
	}
}

/*确认合并的函数*/
void merge_confirm_visualized(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, int* p_goal, int* p_score_now, int* p_score_sum)
{
	int i, j, n = 0;
	for (i = 1; i < *p_hang_num + 1; i++) {
		for (j = 1; j < *p_lie_num + 1; j++) {			
			if (i == *p_int_hang && j == *p_int_lie) {
				changcolor_for_one(i, j, p_co, 15);
				//*p_object += 1;
			}
			else if (p_co->position[i][j] == '*') {
				changcolor_for_one(i, j, p_co, 7);
				n++;
			}
		}
	}
	*p_score_now = (p_co->array[*p_int_hang][*p_int_lie] - 1) * (n + 1) * 3;
	*p_score_sum += *p_score_now;
	int lines = *p_hang_num * 4 + 7;
	cct_gotoxy(0, lines - 4);
	cout << "箭头键/鼠标移动取消当前选择，回车键/单击左键合成                                                                " << endl;
}

/*合并动画的函数*/
void merge_visualized(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co, char judge)
{
	int i, j;
	for (i = 1; i < *p_hang_num + 1; i++) {
		for (j = 1; j < *p_lie_num + 1; j++) {
			if (p_co->array[i][j] == 0) {
				int x = j * 8 - 4;
				int y = i * 4 - 1;
				cct_gotoxy(x, y);
				cct_setcolor(15, 15);
				cout << "┏━┓";
				cct_gotoxy(x, y + 1);
				cout << "┃" << setw(2) << p_co->array[i][j] << "┃";
				cct_gotoxy(x, y + 2);
				cout << "┗━┛";
				cct_setcolor();
			}
		}
	}
	for (i = 0; i < 5; i++) {
		changcolor_for_one(*p_int_hang, *p_int_lie, p_co, 15);
		Sleep(100);
		changcolor_for_one(*p_int_hang, *p_int_lie, p_co, 0);
		Sleep(100);
	}
}

/*下落一格动画的函数*/
void fall_for_one(int i, int j, coordinate* p_co)
{
	int x = j * 8 - 4;
	int y = i * 4 - 1;
	int bg = (p_co->array[i][j] % 14);

	if (p_co->array[i][j] == 0) {
		cct_setcolor(15, 15);
		cct_gotoxy(x, y + 4);
		cout << "┏━┓";
		cct_gotoxy(x, y + 5);
		cout << "┃" << setw(2) << p_co->array[i][j] << "┃";
		cct_gotoxy(x, y + 6);
		cout << "┗━┛";
	}
	else {
		for (int k = 0; k < 4; k++) {
			cct_setcolor(bg, 0);
			cct_gotoxy(x, y + 1);
			cout << "┏━┓";
			cct_gotoxy(x, y + 2);
			cout << "┃" << setw(2) << p_co->array[i][j] << "┃";
			cct_gotoxy(x, y + 3);
			cout << "┗━┛";
			cct_gotoxy(x, y);
			if (k < 3) {
				cct_setcolor(15, 15);
				cout << "      ";
			}
			else {
				cct_setcolor(15, 0);
				cout << "━━━";
			}
			++y;
			Sleep(5);
		}
	}
	cct_setcolor();
}

/*下落一列动画的函数*/
void fall_for_one_lie(int* p_hang_num, int* p_lie_num, int i, int j, coordinate* p_co)
{
	int k;
	for (k = i; k < *p_hang_num; k++) {
		if (p_co->array[k + 1][j] == 0) {
			fall_for_one(k, j, p_co);
			p_co->array[k + 1][j] = p_co->array[k][j];
			p_co->array[k][j] = 0;
		}
		else {
			break;
		}
	}
}

/*下落动画除0的函数*/
void fall_visualized(int* p_hang_num, int* p_lie_num, int* p_int_hang, int* p_int_lie, int* p_object, coordinate* p_co)
{
	int i, j, k;
	for (j = 1; j < *p_lie_num + 1; j++) {
		for (i = *p_hang_num; i > 1; i--) {
			for (k = i; k > 1; k--) {
				if (p_co->array[k][j] == 0) {
					if (p_co->array[k - 1][j] != 0) {
						fall_for_one_lie(p_hang_num, p_lie_num, k - 1, j, p_co);
					}
					else {
						fall_for_one_lie(p_hang_num, p_lie_num, k - 1, j, p_co);
					}
				}
			}
		}
		//p_co->array[1][j] = 0;
	}
	for (i = 0; i < *p_hang_num + 2; i++) {
		for (j = 0; j < *p_lie_num + 2; j++) {
			p_co->position[i][j] = '0';
		}
	}
}

/*改变一块颜色的函数*/
void changcolor_for_one(int i, int j, coordinate* p_co, int fg)
{
	int x = j * 8 - 4;
	int y = i * 4 - 1;
	int bg = (p_co->array[i][j] % 14);
	cct_gotoxy(x, y);
	cct_setcolor(bg, fg);
	cout << "┏━┓";
	cct_gotoxy(x, y + 1);
	cout << "┃" << setw(2) << p_co->array[i][j] << "┃";
	cct_gotoxy(x, y + 2);
	cout << "┗━┛";
	cct_setcolor();
}