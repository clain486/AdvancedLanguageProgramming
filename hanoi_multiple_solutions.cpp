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
	1����ű� hanoi_main.cpp �и��ݲ˵�����ֵ���õĸ��˵����Ӧ��ִ�к���

	 ���ļ�Ҫ��
	1�����������ⲿȫ�ֱ�����const��#define�������Ʒ�Χ�ڣ�
	2�������徲̬ȫ�ֱ�����������Ҫ��������Ҫ�����ĵ���ʾ��ȫ�ֱ�����ʹ��׼���ǣ����á����á��ܲ��þ������ã�
	3����̬�ֲ����������������ƣ���ʹ��׼��Ҳ�ǣ����á����á��ܲ��þ�������
	4���������ϵͳͷ�ļ����Զ���ͷ�ļ��������ռ��
   ----------------------------------------------------------------------------------- */
   /*ȫ�ֱ�����¼�������*/
int A[10] = { 0 }, B[10] = { 0 }, C[10] = { 0 };
int a = 0, b = 0, c = 0;
/*Count��¼����*/
int Count = 0;
/*speedchoice��¼�ٶ�ѡ��*/
int speedchoice = 5;

/*���õ����뺯��*/
int input(char* SRC, char* TMP, char* DST)
{
	int n, i;
	/*����n*/
	while (1) {
		cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
		cin >> n;
		if (n > 0 && n <= 10 && cin.good() == 1) {
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	while (1) {
		cout << "��������ʼ��(A-C)��" << endl;
		cin >> *SRC;
		if ((*SRC == 'A' || *SRC == 'a') && (cin.good() == 1)) {
			*SRC = 'A';
			a = n;
			for (i = 0; i < n; i++) {
				A[i] = n - i;
			}
			int* Src = A;
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else if ((*SRC == 'B' || *SRC == 'b') && (cin.good() == 1)) {
			*SRC = 'B';
			b = n;
			for (i = 0; i < n; i++) {
				B[i] = n - i;
			}
			int* Src = B;
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else if ((*SRC == 'C' || *SRC == 'c') && (cin.good() == 1)) {
			*SRC = 'C';
			c = n;
			for (i = 0; i < n; i++) {
				C[i] = n - i;
			}
			int* Src = C;
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	while (1) {
		cout << "������Ŀ����(A-C)��" << endl;
		cin >> *DST;
		if ((*DST == 'A' || *DST == 'a') && (cin.good() == 1)) {
			*DST = 'A';
			if (*SRC == *DST) {
				cout << "Ŀ����(" << *SRC << ")��������ʼ��(" << *SRC << ")��ͬ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				//int* Dst = A;
				cin.clear();
				cin.ignore(65536, '\n');
				break;
			}
		}
		else if ((*DST == 'B' || *DST == 'b') && (cin.good() == 1)) {
			*DST = 'B';
			if (*SRC == *DST) {
				cout << "Ŀ����(" << *SRC << ")��������ʼ��(" << *SRC << ")��ͬ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				//int* Dst = B;
				cin.clear();
				cin.ignore(65536, '\n');
				break;
			}
		}
		else if ((*DST == 'C' || *DST == 'c') && (cin.good() == 1)) {
			*DST = 'C';
			if (*SRC == *DST) {
				cout << "Ŀ����(" << *SRC << ")��������ʼ��(" << *SRC << ")��ͬ" << endl;
				cin.clear();
				cin.ignore(65536, '\n');
			}
			else {
				//int* Dst = C;
				cin.clear();
				cin.ignore(65536, '\n');
				break;
			}
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	*TMP = 198 - *SRC - *DST;
	return n;
}

/*������ٶ�ѡ����*/
int speedchose()
{
	int speedchoice;
	while (1) {
		cout << "�������ƶ��ٶ�(0-5��0-���س�������ʾ 1-��ʱ� 5-��ʱ���) ";
		cin >> speedchoice;
		if (speedchoice >= 0 && speedchoice <= 5 && cin.fail() == 0) {
			cin.clear();
			cin.ignore(65536, '\n');
			break;
		}
		else {
			cin.clear();
			cin.ignore(65536, '\n');
		}
	}
	cct_setcursor(CURSOR_INVISIBLE);
	return speedchoice;
}

/*�����е�ʱ��������*/
void speedcontrol()
{
	if (speedchoice == 0) {
		int h;
		while (1) {
			h = _getch();
			if (h == '\r' || h == '\n') {
				break;
			}
			else {
				continue;
			}
		}
	}
	else {
		Sleep(10 * (5 - speedchoice) * (5 - speedchoice) * (5 - speedchoice));
	}
}

/*ʱ���������ġ����ػ�0�����*/
void speedcontrol_ex()
{
	if (speedchoice != 0) {
		speedcontrol();
	}
	else {
		Sleep(80);
	}
}

/*489ר�õĽ����л�*/
void screen(int choose, int n, char src, char tmp, char dst)
{
	int i;
	int dengxian_x = 10, dengxian_y = 12;
	if (choose != 4) {
		dengxian_y += 15;
	}
	cct_cls();
	cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��";
	if (choose != 9) {
		cout << "����ʱ����Ϊ " << speedchoice << endl;
	}
	cct_gotoxy(dengxian_x, dengxian_y);
	for (i = 0; i < 25; i++) {
		cout << "=";
	}
	printyABC(choose, src, dst);

	cct_gotoxy(0, dengxian_y + 5);
	cout << "��ʼ:  ";
	printxABC();
	if (choose != 4) {
		startplate(choose, n, src, dst);
	}
	cct_setcursor(CURSOR_INVISIBLE);
}

/*Ψһ�ĺ�ŵ���ݹ麯��*/
void hanoi(int choose, int n, char src, char tmp, char dst)
{
	if (n == 1) {
		media(choose, n, src, tmp, dst);
		//cout << setw(2) << n << "# " << src << "-->" << dst << endl;
	}
	else {
		hanoi(choose, n - 1, src, dst, tmp);
		media(choose, n, src, tmp, dst);
		//cout << setw(2) << n << "# " << src << "-->" << dst << endl;
		hanoi(choose, n - 1, tmp, src, dst);
	}
}

/*�����ת��ý�麯��*/
void media(int choose, int n, char src, char tmp, char dst)
{
	switch (choose) {
		case 1:
			printstep1(n, src, dst);
			break;
		case 2:
			printstep2(n, src, dst);
			break;
		case 3:
			printstep3(choose, n, src, dst);
			break;
		case 4:
			printstep4(choose, n, src, dst);
			break;
		case 8:
			printstep8(choose, n, src, dst);
			break;
	}
}

/*src-->dst������仯����*/
void trans(int choose, char src, char dst)
{
	if (src == 'A' && dst == 'B') {
		B[b++] = A[--a];
		A[a] = 0;
	}
	else if (src == 'A' && dst == 'C') {
		C[c++] = A[--a];
		A[a] = 0;
	}
	else if (src == 'B' && dst == 'A') {
		A[a++] = B[--b];
		B[b] = 0;
	}
	else if (src == 'B' && dst == 'C') {
		C[c++] = B[--b];
		B[b] = 0;
	}
	else if (src == 'C' && dst == 'A') {
		A[a++] = C[--c];
		C[c] = 0;
	}
	else if (src == 'C' && dst == 'B') {
		B[b++] = C[--c];
		C[c] = 0;
	}
}

/*���������������*/
void printxABC()
{
	int i;
	cout << "A:";
	if (A[0] > 0) {
		cout << setw(2) << A[0];
	}
	else {
		cout << "  ";
	}
	for (i = 1; i < 10; i++) {
		if (A[i] > 0) {
			cout << setw(2) << A[i];
		}
		else {
			cout << "  ";
		}
	}
	cout << " B:";
	if (B[0] > 0) {
		cout << setw(2) << B[0];
	}
	else {
		cout << "  ";
	}
	for (i = 1; i < 10; i++) {
		if (B[i] > 0) {
			cout << setw(2) << B[i];
		}
		else {
			cout << "  ";
		}
	}
	cout << " C:";
	if (C[0] > 0) {
		cout << setw(2) << C[0];
	}
	else {
		cout << "  ";
	}
	for (i = 1; i < 10; i++) {
		if (C[i] > 0) {
			cout << setw(2) << C[i];
		}
		else {
			cout << "  ";
		}
	}
	cout << endl;
}

/*�������󻯸ı亯��*/
void changexABC(int choose, char src, char dst, int y)
{
	int x1 = 23, x2 = x1 + 23, x3 = x2 + 23;
	int x4 = 25, x5 = x4 + 23, x6 = x5 + 23;
	if (src == 'A' && dst == 'B') {
		cct_gotoxy(x4 + 2 * a, y);
		cout << "  ";
		cct_gotoxy(x2 + 2 * b, y);
		cout << setw(2) << B[b - 1];
	}
	else if (src == 'A' && dst == 'C') {
		cct_gotoxy(x4 + 2 * a, y);
		cout << "  ";
		cct_gotoxy(x3 + 2 * c, y);
		cout << setw(2) << C[c - 1];
	}
	else if (src == 'B' && dst == 'A') {
		cct_gotoxy(x5 + 2 * b, y);
		cout << "  ";
		cct_gotoxy(x1 + 2 * a, y);
		cout << setw(2) << A[a - 1];
	}
	else if (src == 'B' && dst == 'C') {
		cct_gotoxy(x5 + 2 * b, y);
		cout << "  ";
		cct_gotoxy(x3 + 2 * c, y);
		cout << setw(2) << C[c - 1];
	}
	else if (src == 'C' && dst == 'A') {
		cct_gotoxy(x6 + 2 * c, y);
		cout << "  ";
		cct_gotoxy(x1 + 2 * a, y);
		cout << setw(2) << A[a - 1];
	}
	else if (src == 'C' && dst == 'B') {
		cct_gotoxy(x6 + 2 * c, y);
		cout << "  ";
		cct_gotoxy(x2 + 2 * b, y);
		cout << setw(2) << B[b - 1];
	}
}

/*���������������*/
void printyABC(int choose, char src, char dst)
{
	int i, xa = 11, ya = 11, xb = xa + 10, yb = ya, xc = xb + 10, yc = yb;
	if (choose != 4) {
		ya += 15;
		yb = ya;
		yc = yb;
	}
	cct_gotoxy(xa + 1, ya + 2);
	cout << "A" << setw(10) << "B" << setw(10) << "C";
	for (i = 0; i < 10; i++) {
		cct_gotoxy(xa, ya);
		if (A[i] > 0) {
			cout << setw(2) << A[i];
			ya--;
		}
		else {
			cout << "  ";
			ya--;
		}
	}
	for (i = 0; i < 10; i++) {
		cct_gotoxy(xb, yb);
		if (B[i] > 0) {
			cout << setw(2) << B[i];
			yb--;
		}
		else {
			cout << "  ";
			yb--;
		}
	}
	for (i = 0; i < 10; i++) {
		cct_gotoxy(xc, yc);
		if (C[i] > 0) {
			cout << setw(2) << C[i];
			yc--;
		}
		else {
			cout << "  ";
			yc--;
		}
	}
}

/*�������󻯸ı亯��*/
void changeyABC(int choose, char src, char dst, int y)
{
	int x1 = 11, x2 = x1 + 10, x3 = x2 + 10;
	if (src == 'A' && dst == 'B') {
		cct_gotoxy(x1, y - a - 3);
		cout << "  ";
		cct_gotoxy(x2, y - b - 2);
		cout << setw(2) << B[b - 1];
	}
	else if (src == 'A' && dst == 'C') {
		cct_gotoxy(x1, y - a - 3);
		cout << "  ";
		cct_gotoxy(x3, y - c - 2);
		cout << setw(2) << C[c - 1];
	}
	else if (src == 'B' && dst == 'A') {
		cct_gotoxy(x2, y - b - 3);
		cout << "  ";
		cct_gotoxy(x1, y - a - 2);
		cout << setw(2) << A[a - 1];
	}
	else if (src == 'B' && dst == 'C') {
		cct_gotoxy(x2, y - b - 3);
		cout << "  ";
		cct_gotoxy(x3, y - c - 2);
		cout << setw(2) << C[c - 1];
	}
	else if (src == 'C' && dst == 'A') {
		cct_gotoxy(x3, y - c - 3);
		cout << "  ";
		cct_gotoxy(x1, y - a - 2);
		cout << setw(2) << A[a - 1];
	}
	else if (src == 'C' && dst == 'B') {
		cct_gotoxy(x3, y - c - 3);
		cout << "  ";
		cct_gotoxy(x2, y - b - 2);
		cout << setw(2) << B[b - 1];
	}

}

/*ͼ�λ��������-������*/
void printcolumn(int choose)
{
	int x1 = 1, x2 = x1 + 32, x3 = x2 + 32;
	int y1 = 15;
	cct_showstr(x1, y1, " ", COLOR_HYELLOW, COLOR_WHITE, 23, -1);
	cct_showstr(x2, y1, " ", COLOR_HYELLOW, COLOR_WHITE, 23, -1);
	cct_showstr(x3, y1, " ", COLOR_HYELLOW, COLOR_WHITE, 23, -1);
	int x4 = 12, x5 = x4 + 32, x6 = x5 + 32;
	int y2 = 14;
	for (y2 = 14; y2 > 2; y2--) {
		cct_showstr(x4, y2, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
		Sleep(50);
		cct_showstr(x5, y2, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
		Sleep(50);
		cct_showstr(x6, y2, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
		cct_setcursor(CURSOR_INVISIBLE);
		Sleep(80);
	}
}

/*ͼ�λ��������-��ʼ��*/
void startplate(int choose, int n, char src, char dst)
{
	int i;
	if (choose != 8 && choose != 9) {
		cout << "�� " << src << " �ƶ��� " << dst << "���� " << n << " ��" << endl;
	}
	printcolumn(choose);
	int x4 = 12, x5 = x4 + 32, x6 = x5 + 32;
	int y2 = 14;
	if (src == 'A') {
		for (i = 0; i < n; i++) {
			cct_showstr(x4 - A[i], y2, " ", A[i], COLOR_WHITE, 2 * A[i] + 1, -1);
			y2--;
			Sleep(50);
		}
	}
	else if (src == 'B') {
		for (i = 0; i < n; i++) {
			cct_showstr(x5 - B[i], y2, " ", B[i], COLOR_WHITE, 2 * B[i] + 1, -1);
			y2--;
			Sleep(50);
		}
	}
	else if (src == 'C') {
		for (i = 0; i < n; i++) {
			cct_showstr(x6 - C[i], y2, " ", C[i], COLOR_WHITE, 2 * C[i] + 1, -1);
			y2--;
			Sleep(50);
		}
	}
	cct_setcursor(CURSOR_INVISIBLE);
}

/*ͼ�λ������������һ���ƶ�����trans�����������*/
void movement_up(int choose, int n, char src, char dst)
{
	int i;
	int x4 = 12, x5 = x4 + 32, x6 = x5 + 32;
	int y2 = 14;
	if (src == 'A' && dst == 'B') {
		for (i = a; y2 - i > 1; i++) {
			cct_showstr(x4 - B[b - 1], y2 - i - 1, " ", B[b - 1], COLOR_WHITE, 2 * B[b - 1] + 1, -1);
			cct_showstr(x4 - B[b - 1], y2 - i, " ", COLOR_BLACK, COLOR_WHITE, 2 * B[b - 1] + 1, -1);
			if (y2 - i > 2) {
				cct_showstr(x4, y2 - i, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
		for (i = x4 - B[b - 1]; i < x5 - B[b - 1]; i++) {
			cct_showstr(i + 1, 1, " ", B[b - 1], COLOR_WHITE, 2 * B[b - 1] + 1, -1);
			cct_showstr(i, 1, " ", COLOR_BLACK, COLOR_WHITE, 1, -1);
			speedcontrol_ex();
		}
	}
	else if (src == 'A' && dst == 'C') {
		for (i = a; y2 - i > 1; i++) {
			cct_showstr(x4 - C[c - 1], y2 - i - 1, " ", C[c - 1], COLOR_WHITE, 2 * C[c - 1] + 1, -1);
			cct_showstr(x4 - C[c - 1], y2 - i, " ", COLOR_BLACK, COLOR_WHITE, 2 * C[c - 1] + 1, -1);
			if (y2 - i > 2) {
				cct_showstr(x4, y2 - i, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
		for (i = x4 - C[c - 1]; i < x6 - C[c - 1]; i++) {
			cct_showstr(i + 1, 1, " ", C[c - 1], COLOR_WHITE, 2 * C[c - 1] + 1, -1);
			cct_showstr(i, 1, " ", COLOR_BLACK, COLOR_WHITE, 1, -1);
			speedcontrol_ex();
		}
	}
	else if (src == 'B' && dst == 'A') {
		for (i = b; y2 - i > 1; i++) {
			cct_showstr(x5 - A[a - 1], y2 - i - 1, " ", A[a - 1], COLOR_WHITE, 2 * A[a - 1] + 1, -1);
			cct_showstr(x5 - A[a - 1], y2 - i, " ", COLOR_BLACK, COLOR_WHITE, 2 * A[a - 1] + 1, -1);
			if (y2 - i > 2) {
				cct_showstr(x5, y2 - i, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
		for (i = x5 - A[a - 1]; i > x4 - A[a - 1]; i--) {
			cct_showstr(i - 1, 1, " ", A[a - 1], COLOR_WHITE, 2 * A[a - 1] + 1, -1);
			cct_showstr(i + 2 * A[a - 1], 1, " ", COLOR_BLACK, COLOR_WHITE, A[a - 1], -1);
			speedcontrol_ex();
		}
	}
	else if (src == 'B' && dst == 'C') {
		for (i = b; y2 - i > 1; i++) {
			cct_showstr(x5 - C[c - 1], y2 - i - 1, " ", C[c - 1], COLOR_WHITE, 2 * C[c - 1] + 1, -1);
			cct_showstr(x5 - C[c - 1], y2 - i, " ", COLOR_BLACK, COLOR_WHITE, 2 * C[c - 1] + 1, -1);
			if (y2 - i > 2) {
				cct_showstr(x5, y2 - i, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
		for (i = x5 - C[c - 1]; i < x6 - C[c - 1]; i++) {
			cct_showstr(i + 1, 1, " ", C[c - 1], COLOR_WHITE, 2 * C[c - 1] + 1, -1);
			cct_showstr(i, 1, " ", COLOR_BLACK, COLOR_WHITE, 1, -1);
			speedcontrol_ex();
		}
	}
	else if (src == 'C' && dst == 'A') {
		for (i = c; y2 - i > 1; i++) {
			cct_showstr(x6 - A[a - 1], y2 - i - 1, " ", A[a - 1], COLOR_WHITE, 2 * A[a - 1] + 1, -1);
			cct_showstr(x6 - A[a - 1], y2 - i, " ", COLOR_BLACK, COLOR_WHITE, 2 * A[a - 1] + 1, -1);
			if (y2 - i > 2) {
				cct_showstr(x6, y2 - i, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
		for (i = x6 - A[a - 1]; i > x4 - A[a - 1]; i--) {
			cct_showstr(i - 1, 1, " ", A[a - 1], COLOR_WHITE, 2 * A[a - 1] + 1, -1);
			cct_showstr(i + 2 * A[a - 1], 1, " ", COLOR_BLACK, COLOR_WHITE, A[a - 1], -1);
			speedcontrol_ex();
		}
	}
	else if (src == 'C' && dst == 'B') {
		for (i = c; y2 - i > 1; i++) {
			cct_showstr(x6 - B[b - 1], y2 - i - 1, " ", B[b - 1], COLOR_WHITE, 2 * B[b - 1] + 1, -1);
			cct_showstr(x6 - B[b - 1], y2 - i, " ", COLOR_BLACK, COLOR_WHITE, 2 * B[b - 1] + 1, -1);
			if (y2 - i > 2) {
				cct_showstr(x6, y2 - i, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
		for (i = x6 - B[b - 1]; i > x5 - B[b - 1]; i--) {
			cct_showstr(i - 1, 1, " ", B[b - 1], COLOR_WHITE, 2 * B[b - 1] + 1, -1);
			cct_showstr(i + 2 * B[b - 1], 1, " ", COLOR_BLACK, COLOR_WHITE, B[b - 1], -1);
			speedcontrol_ex();
		}
	}
}

/*ͼ�λ������������һ���ƶ�����trans���½�*/
void movement_down(int choose, int n, char src, char dst)
{
	int i;
	int x4 = 12, x5 = x4 + 32, x6 = x5 + 32;
	int y2 = 14;
	if (dst == 'A') {
		for (i = a - 1; y2 - i > 0; i++) {
			cct_showstr(x4 - A[a - 1], i - a + 2, " ", A[a - 1], COLOR_WHITE, 2 * A[a - 1] + 1, -1);
			if (i != a - 1) {
				cct_showstr(x4 - A[a - 1], i - a + 1, " ", COLOR_BLACK, COLOR_WHITE, 2 * A[a - 1] + 1, -1);
			}
			if (i > a + 1) {
				cct_showstr(x4, i - a + 1, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
	}
	else if (dst == 'B') {
		for (i = b - 1; y2 - i > 0; i++) {
			cct_showstr(x5 - B[b - 1], i - b + 2, " ", B[b - 1], COLOR_WHITE, 2 * B[b - 1] + 1, -1);
			if (i != b - 1) {
				cct_showstr(x5 - B[b - 1], i - b + 1, " ", COLOR_BLACK, COLOR_WHITE, 2 * B[b - 1] + 1, -1);
			}
			if (i > b + 1) {
				cct_showstr(x5, i - b + 1, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
	}
	else if (dst == 'C') {
		for (i = c - 1; y2 - i > 0; i++) {
			cct_showstr(x6 - C[c - 1], i - c + 2, " ", C[c - 1], COLOR_WHITE, 2 * C[c - 1] + 1, -1);
			if (i != c - 1) {
				cct_showstr(x6 - C[c - 1], i - c + 1, " ", COLOR_BLACK, COLOR_WHITE, 2 * C[c - 1] + 1, -1);
			}
			if (i > c + 1) {
				cct_showstr(x6, i - c + 1, " ", COLOR_HYELLOW, COLOR_WHITE, 1, -1);
			}
			speedcontrol_ex();
		}
	}
}

/*9ר�õĺ���*/
void freeplay(int choose, int n, char Src, char Dst)
{
	int y = 33;
	char T[2], src, dst;
	int i;
	cct_showstr(0, y, "�������ƶ�������(������ʽ��AC=A���˵������ƶ���C��Q=�˳�) ��", COLOR_BLACK, COLOR_WHITE, 1, -1);
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	for (i = 0; i < 2; i++) {
		T[i] = '0';
	}
	while (1) {
		while (1) {
			cct_showstr(60, y, " ", COLOR_BLACK, COLOR_WHITE, 20, -1);
			cct_gotoxy(60, y);
			for (i = 0; i < 2; i++) {
				cin >> T[i];
				if (T[i] == 32) {
					i--;
				}
				else if (T[0] == 'q' || T[0] == 'Q') {
					cct_showstr(0, y + 1, "��Ϸ��ֹ!!!!!", COLOR_BLACK, COLOR_WHITE, 1, -1);
					break;
				}
			}
			if (T[0] == 'q' || T[0] == 'Q') {
				src = 0;
				dst = 0;
				break;
			}
			if ((T[0] == 'a' || T[0] == 'A')) {
				src = 'A';
				if (T[1] == 'b' || T[1] == 'B') {
					dst = 'B';
					if (a == 0) {
						cct_showstr(0, y + 1, "Դ��Ϊ��!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "         ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
					else if (b == 0 || A[a - 1] < B[b - 1]) {
						break;
					}
					else {
						cct_showstr(0, y + 1, "����ѹС�̣��Ƿ��ƶ�!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "                     ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
				}
				else if (T[1] == 'c' || T[1] == 'C') {
					dst = 'C';
					if (a == 0) {
						cct_showstr(0, y + 1, "Դ��Ϊ��!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "         ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
					else if (c == 0 || A[a - 1] < C[c - 1]) {
						break;
					}
					else {
						cct_showstr(0, y + 1, "����ѹС�̣��Ƿ��ƶ�!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "                     ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
				}
			}
			else if ((T[0] == 'b' || T[0] == 'B')) {
				src = 'B';
				if (T[1] == 'a' || T[1] == 'A') {
					dst = 'A';
					if (b == 0) {
						cct_showstr(0, y + 1, "Դ��Ϊ��!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "         ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
					else if (a == 0 || B[b - 1] < A[a - 1]) {
						break;
					}
					else {
						cct_showstr(0, y + 1, "����ѹС�̣��Ƿ��ƶ�!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "                     ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
				}
				else if (T[1] == 'c' || T[1] == 'C') {
					dst = 'C';
					if (b == 0) {
						cct_showstr(0, y + 1, "Դ��Ϊ��!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "         ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
					else if (c == 0 || B[b - 1] < C[c - 1]) {
						break;
					}
					else {
						cct_showstr(0, y + 1, "����ѹС�̣��Ƿ��ƶ�!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "                     ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
				}
			}
			else if ((T[0] == 'c' || T[0] == 'C')) {
				src = 'C';
				if (T[1] == 'a' || T[1] == 'A') {
					dst = 'A';
					if (c == 0) {
						cct_showstr(0, y + 1, "Դ��Ϊ��!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "         ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
					else if (a == 0 || C[c - 1] < A[a - 1]) {
						break;
					}
					else {
						cct_showstr(0, y + 1, "����ѹС�̣��Ƿ��ƶ�!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "                     ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
				}
				else if (T[1] == 'b' || T[1] == 'B') {
					dst = 'B';
					if (c == 0) {
						cct_showstr(0, y + 1, "Դ��Ϊ��!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "         ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
					else if (b == 0 || C[c - 1] < B[b - 1]) {
						break;
					}
					else {
						cct_showstr(0, y + 1, "����ѹС�̣��Ƿ��ƶ�!", COLOR_BLACK, COLOR_WHITE, 1, -1);
						Sleep(800);
						cct_showstr(0, y + 1, "                     ", COLOR_BLACK, COLOR_WHITE, 1, -1);
						i--;
						continue;
					}
				}
			}
		}
		if (src == 0 && dst == 0) {
			break;
		}
		trans(choose, src, dst);
		cct_gotoxy(0, 32);
		cct_showstr(0, 32, "��", COLOR_BLACK, COLOR_WHITE, 1, -1);
		cout << setw(4) << ++Count << " ��( " << n << "#: " << src << "-->" << dst << ")  ";
		printxABC();
		changexABC(choose, src, dst, 32);
		printyABC(choose, src, dst);
		changeyABC(choose, src, dst, 29);
		cct_setcursor(CURSOR_INVISIBLE);
		movement_up(choose, n, src, dst);
		movement_down(choose, n, src, dst);
		cct_setcursor(CURSOR_INVISIBLE);
		if ((Dst == 'A' && a == n) || (Dst == 'B' && b == n) || (Dst == 'C' && c == n)) {
			cct_showstr(0, y + 1, "��Ϸ����!!!!!", COLOR_BLACK, COLOR_WHITE, 1, -1);
			break;
		}
	}
}

/*����ת�Ĵ�ӡ���躯��*/
void printstep1(int n, char src, char dst)
{
	cout << n << "# " << src << "---->" << dst << endl;
}
void printstep2(int n, char src, char dst)
{
	cout << "��" << setw(4) << ++Count << " ��( " << n << "#: " << src << "-->" << dst << ")" << endl;
}
void printstep3(int choose, int n, char src, char dst)
{
	cout << "��" << setw(4) << ++Count << " ��( " << n << "#: " << src << "-->" << dst << ")  ";
	trans(choose, src, dst);
	printxABC();
}
void printstep4(int choose, int n, char src, char dst)
{
	speedcontrol();
	cct_gotoxy(0, 17);
	cout << "��" << setw(4) << ++Count << " ��( " << n << "#: " << src << "-->" << dst << ")  ";
	trans(choose, src, dst);
	printxABC();
	changexABC(choose, src, dst, 17);
	printyABC(choose, src, dst);
	changeyABC(choose, src, dst, 14);
	cct_setcursor(CURSOR_INVISIBLE);
}
void printstep8(int choose, int n, char src, char dst)
{
	if (speedchoice == 0) {
		while (1) {
			int back = _getch();
			if (back == '\n' || back == '\r') {
				break;
			}
		}
	}
	trans(choose, src, dst);
	cct_gotoxy(0, 32);
	cct_showstr(0, 32, "��", COLOR_BLACK, COLOR_WHITE, 1, -1);
	cout << setw(4) << ++Count << " ��( " << n << "#: " << src << "-->" << dst << ")  ";
	printxABC();
	changexABC(choose, src, dst, 32);
	printyABC(choose, src, dst);
	changeyABC(choose, src, dst, 29);
	movement_up(choose, n, src, dst);
	movement_down(choose, n, src, dst);
	cct_setcursor(CURSOR_INVISIBLE);
}
