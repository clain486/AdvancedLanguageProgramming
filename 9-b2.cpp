/* 2151140 信07 王谦 */

/* 允许按需加入系统的宏定义、需要的头文件等 */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#define MAX_STU_NUM			256	//约定最大人数为256人（两轮的总和，包括退选、补选）
#define MAX_NAME_LEN			32	//学生姓名的最大长度不超过16个汉字
#define MAX_FILENAME_LEN		256	//文件名的最大长度

class stu_list;

/* stu_info 类存放每个学生的信息，包括学号、姓名、其它需要的私有信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_info {
private:
	int  stu_no;			           //学号
	char stu_name[MAX_NAME_LEN];	   //姓名
	                                   /* 允许按需加入private数据成员、成员函数以及其它需要的内容 */
	int  stu_no2;	
	char stu_name2[MAX_NAME_LEN];
	int  stu_no3;
	char stu_name3[MAX_NAME_LEN];
	int stu_A;
	int stu_B;
	int stu_A2;
	int stu_B2;
	int stu_A3;
	int stu_B3;

	friend stu_list;

public:
	                                   /* 本类不允许定义任何的公有数据成员、成员函数 */
};

/* stu_list 类整个选课信息，已有内容不准动，可加入符合限制要求的新内容 */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
                                                            /* 允许按需加入private数据成员和成员函数 */
	
public:
	int read(const char* filename, const int append = 0);	//从文件中读入选课信息并进行处理，第2个参数值为0表示覆盖方式，1表示追加方式
	int print(const char* prompt = NULL);			        //打印当前读入的选课名单
	                                                        /* 允许按需加入其它public成员函数 */
};

/* --- 此处给出上面两个类的成员函数的体外实现 --- */
int stu_list::read(const char* filename, const int append)
{
	ifstream in;
	if (append == 0) {
		in.open(filename, ios::in | ios::binary);
		if (!in.is_open()) {
			cout << "文件[" << filename << "]打开失败" << endl;
			return -1;
		}
		int i = 0;
		while (!in.eof()) {
			in >> stu[i].stu_no >> stu[i].stu_name;		
			stu[i].stu_A = 0;
			stu[i].stu_B = 0;		
			i++;
		}
	 }
	else if(append == 1){	
		in.open(filename, ios::in | ios::binary);
		if (!in.is_open()) {
			cout << "文件[" << filename << "]打开失败" << endl;
			return -1;
		}
		int i = 0;
		while (!in.eof()) {
			in >> stu[i].stu_no2 >> stu[i].stu_name2;
            stu[i].stu_A2 = 0;
			stu[i].stu_B2 = 0;			
			i++;
		}
	}
	in.close();
	return 0;
}

int stu_list::print(const char* prompt)
{
	int i, j, k, n = 0;
	for (i = 1; stu[i - 1].stu_no > 0; i++) {
		for (k = 1; stu[k - 1].stu_no2 > 0; k++) {
			if (stu[i - 1].stu_no == stu[k - 1].stu_no2) {
				stu[n].stu_no3 = stu[i - 1].stu_no;
				strcpy(stu[n].stu_name3, stu[i - 1].stu_name);
				stu[n].stu_A3 = 1;
				stu[n].stu_B3 = 1;
				stu[i - 1].stu_A = -1;
				stu[i - 1].stu_B = -1;
				stu[k - 1].stu_A2 = -1;
				stu[k - 1].stu_B2 = -1;
				n++;
				break;
			}
			else if(stu[i - 1].stu_A != -1) {
				stu[i - 1].stu_A = 0;
				stu[i - 1].stu_B = 0;
			}
		}
	}
	for (j = 1; stu[j - 1].stu_no > 0; j++) {
		if (stu[j - 1].stu_A != -1) {
			stu[n].stu_no3 = stu[j - 1].stu_no;
			strcpy(stu[n].stu_name3, stu[j - 1].stu_name);
			stu[n].stu_A3 = 1;
			stu[n].stu_B3 = 0;
			stu[j - 1].stu_A = -1;
			stu[j - 1].stu_B = -1;
			n++;
		}
	}
	for (j = 1; stu[j - 1].stu_no2 > 0; j++) {
		if (stu[j - 1].stu_A2 != -1) {
			stu[n].stu_no3 = stu[j - 1].stu_no2;
			strcpy(stu[n].stu_name3, stu[j - 1].stu_name2);
			stu[n].stu_A3 = 0;
			stu[n].stu_B3 = 1;
			stu[j - 1].stu_A2 = -1;
			stu[j - 1].stu_B2 = -1;
			n++;
		}
	}
	for (k = 1;k<n+1; k++) {
		for (j = 1;j<n+1; j++) {
			for (i = 1;i<n; i++) {
				if (stu[i - 1].stu_no3 > stu[i].stu_no3) {

					char ch[MAX_NAME_LEN];
					int t;

					t = stu[i - 1].stu_no3;
					stu[i - 1].stu_no3 = stu[i].stu_no3;
					stu[i].stu_no3 = t;

					strcpy(ch, stu[i - 1].stu_name3);
					strcpy(stu[i - 1].stu_name3, stu[i].stu_name3);
					strcpy(stu[i].stu_name3, ch);

					t = stu[i - 1].stu_A3;
					stu[i - 1].stu_A3 = stu[i].stu_A3;
					stu[i].stu_A3 = t;

					t = stu[i - 1].stu_B3;
					stu[i - 1].stu_B3 = stu[i].stu_B3;
					stu[i].stu_B3 = t;
				}
			}
		}
	}

	cout << prompt << endl
		<< "===========================================================" << endl
		<< "序号 学号    姓名                             第一轮 第二轮" << endl
		<< "===========================================================" << endl;

	for (i = 1;i<n+1; i++) {
		cout << setiosflags(ios::left) << setw(5) << i
			<< setw(8) << stu[i - 1].stu_no3
			<< setw(33) << stu[i - 1].stu_name3;
		if (stu[i - 1].stu_A3 == 1 && stu[i - 1].stu_B3 == 1) {
			cout << setw(7) << 'Y' << 'Y';
		}
		else if (stu[i - 1].stu_A3 != 1 && stu[i - 1].stu_B3 == 1) {
			cout << setw(7) << '/' << "补选";
		}
		else if (stu[i - 1].stu_A3 == 1 && stu[i - 1].stu_B3 != 1) {
			cout << setw(7) << 'Y' << "退课";
		}
		cout << endl;
	}
	cout << "===========================================================" << endl;
	return 0;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "请输入前一轮选课的数据文件 : ";
	cin >> file1;
	cout << "请输入后一轮选课的数据文件 : ";
	cin >> file2;

	stu_list list;

	/* 读入第一个数据文件 */
	if (list.read(file1) < 0)
		return -1;

	/* 读入第二个数据文件，参数2的值为1表示追加方式 */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("最终选课名单");

	return 0;
}