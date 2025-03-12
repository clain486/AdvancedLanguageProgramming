/* 2151140 ��07 ��ǫ */
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

	 ���ļ����ܣ�
	1����main����
	2����ʼ����Ļ
	3�����ò˵�������hanoi_menu.cpp�У�������ѡ��
	4������ѡ����ò˵������Ӧ��ִ�к�����hanoi_multiple_solutions.cpp�У�

	 ���ļ�Ҫ��
	1����������ȫ�ֱ��������ⲿȫ�ֺ;�̬ȫ�֣�const��#define�������Ʒ�Χ�ڣ�
	2����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	3���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��

   ----------------------------------------------------------------------------------- */
extern int A[10], B[10], C[10];
extern int a, b, c;
extern int Count;
extern int speedchoice;

int main()
{
	int n, i;
	char src, tmp, dst;

	/* demo������ִ�д˾䣬��cmd��������Ϊ40��x120�У����������120�У�����9000�У���cmd�����Ҳ���д�ֱ�����ˣ�*/
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
			cout << "���س�������";
		}
		else {
			cct_showstr(0, 38, "���س�������", COLOR_BLACK, COLOR_WHITE, 1, -1);
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