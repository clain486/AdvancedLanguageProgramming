/* 2151140 ��07 ��ǫ */
#pragma once

/* ------------------------------------------------------------------------------------------------------

	 ���ļ����ܣ�
	1��Ϊ�˱�֤ hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp ���໥���ʺ����ĺ�������
	2��һ�����ϵ�cpp���õ��ĺ궨�壨#define����ȫ��ֻ����const����������������
	3�����Բο� cmd_console_tools.h ��д���������Ķ�����ᣩ
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
