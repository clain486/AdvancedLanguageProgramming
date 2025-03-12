/* 2151140 信07 王谦 */
#pragma once

/* ------------------------------------------------------------------------------------------------------

	 本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */
int menu();
int input(char* SRC, char* TMP, char* DST);
int speedchose();
void hanoi(int choose, int n, char src, char tmp, char dst);
void speedcontrol();
void speedcontrol_ex();
void screen(int choose, int n, char src, char tmp, char dst);
void media(int choose, int n, char src, char tmp, char dst);
void trans(int choose, char src, char dst);
void printxABC();
void printyABC(int choose, char src, char dst);
void changexABC(int choose, char src, char dst, int y);
void changeyABC(int choose, char src, char dst, int y);
void printcolumn(int choose);
void startplate(int choose, int n, char src, char dst);
void movement_up(int choose, int n, char src, char dst);
void movement_down(int choose, int n, char src, char dst);
void freeplay(int choose, int n, char Src, char Dst);
void printstep1(int n, char src, char dst);
void printstep2(int n, char src, char dst);
void printstep3(int choose, int n, char src, char dst);
void printstep4(int choose, int n, char src, char dst);
void printstep8(int choose, int n, char src, char dst);
