/* 2151140 信07 王谦 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <tchar.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
#include "hanoi.h"
#include "cmd_console_tools.h"
using namespace std;
/* ----------------------------------------------------------------------------------

	 本文件功能：
	1、放main函数
	2、初始化屏幕
	3、调用菜单函数（hanoi_menu.cpp中）并返回选项
	4、根据选项调用菜单各项对应的执行函数（hanoi_multiple_solutions.cpp中）

	 本文件要求：
	1、不允许定义全局变量（含外部全局和静态全局，const及#define不在限制范围内）
	2、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
	3、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */
extern int A[10], B[10], C[10];
extern int a, b, c;
extern int Count;
extern int speedchoice;

int main()
{
	int n, i;
	char src, tmp, dst;

	/* demo中首先执行此句，将cmd窗口设置为40行x120列（缓冲区宽度120列，行数9000行，即cmd窗口右侧带有垂直滚动杆）*/
	cct_setconsoleborder(120, 40, 120, 9000);
	while (1) {
		int choose = menu();
		if (choose == 0) {
			break;
		}
		else if (choose == 4) {
			n = input(&src, &tmp, &dst);
			speedchoice = speedchose();
			screen(choose, n, src, tmp, dst);
			hanoi(choose, n, src, tmp, dst);
		}
		else if (choose == 5) {
			cct_cls();
			printcolumn(choose);
		}
		else if (choose == 6) {
			n = input(&src, &tmp, &dst);
			cct_cls();
			startplate(choose, n, src, dst);
		}
		else if (choose == 7) {
			speedchoice = 2;
			n = input(&src, &tmp, &dst);
			cct_cls();
			startplate(choose, n, src, dst);
			trans(choose, src, dst);
			movement_up(choose, n, src, dst);
			movement_down(choose, n, src, dst);
		}
		else if (choose == 8) {
			n = input(&src, &tmp, &dst);
			speedchoice = speedchose();
			screen(choose, n, src, tmp, dst);
			hanoi(choose, n, src, tmp, dst);
		}
		else if (choose == 9) {
			speedchoice = 4;
			n = input(&src, &tmp, &dst);
			screen(choose, n, src, tmp, dst);
			freeplay(choose, n, src, dst);
		}
		else {
			n = input(&src, &tmp, &dst);
			hanoi(choose, n, src, tmp, dst);
		}
		if (choose == 1 || choose == 2 || choose == 3) {
			cout << "按回车键继续";
		}
		else {
			cct_showstr(0, 38, "按回车键继续", COLOR_BLACK, COLOR_WHITE, 1, -1);
		}
		while (1) {
			int back = _getch();
			if (back == '\n' || back == '\r') {
				break;
			}
		}
		cct_cls();
		Count = 0;
		speedchoice = 5;
		for (i = 0; i < 10; i++) {
			A[i] = 0;
			B[i] = 0;
			C[i] = 0;
		}
		a = 0, b = 0, c = 0;
	}
	return 0;
}