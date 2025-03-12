/* 2151140 ��07 ��ǫ */

/* ���������ϵͳ�ĺ궨�塢��Ҫ��ͷ�ļ��� */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>

using namespace std;

#define MAX_STU_NUM			256	//Լ���������Ϊ256�ˣ����ֵ��ܺͣ�������ѡ����ѡ��
#define MAX_NAME_LEN			32	//ѧ����������󳤶Ȳ�����16������
#define MAX_FILENAME_LEN		256	//�ļ�������󳤶�

class stu_list;

/* stu_info ����ÿ��ѧ������Ϣ������ѧ�š�������������Ҫ��˽����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_info {
private:
	int  stu_no;			           //ѧ��
	char stu_name[MAX_NAME_LEN];	   //����
	                                   /* ���������private���ݳ�Ա����Ա�����Լ�������Ҫ������ */
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
	                                   /* ���಻�������κεĹ������ݳ�Ա����Ա���� */
};

/* stu_list ������ѡ����Ϣ���������ݲ�׼�����ɼ����������Ҫ��������� */
class stu_list {
private:
	stu_info stu[MAX_STU_NUM + 1];
                                                            /* ���������private���ݳ�Ա�ͳ�Ա���� */
	
public:
	int read(const char* filename, const int append = 0);	//���ļ��ж���ѡ����Ϣ�����д�����2������ֵΪ0��ʾ���Ƿ�ʽ��1��ʾ׷�ӷ�ʽ
	int print(const char* prompt = NULL);			        //��ӡ��ǰ�����ѡ������
	                                                        /* �������������public��Ա���� */
};

/* --- �˴���������������ĳ�Ա����������ʵ�� --- */
int stu_list::read(const char* filename, const int append)
{
	ifstream in;
	if (append == 0) {
		in.open(filename, ios::in | ios::binary);
		if (!in.is_open()) {
			cout << "�ļ�[" << filename << "]��ʧ��" << endl;
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
			cout << "�ļ�[" << filename << "]��ʧ��" << endl;
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
		<< "��� ѧ��    ����                             ��һ�� �ڶ���" << endl
		<< "===========================================================" << endl;

	for (i = 1;i<n+1; i++) {
		cout << setiosflags(ios::left) << setw(5) << i
			<< setw(8) << stu[i - 1].stu_no3
			<< setw(33) << stu[i - 1].stu_name3;
		if (stu[i - 1].stu_A3 == 1 && stu[i - 1].stu_B3 == 1) {
			cout << setw(7) << 'Y' << 'Y';
		}
		else if (stu[i - 1].stu_A3 != 1 && stu[i - 1].stu_B3 == 1) {
			cout << setw(7) << '/' << "��ѡ";
		}
		else if (stu[i - 1].stu_A3 == 1 && stu[i - 1].stu_B3 != 1) {
			cout << setw(7) << 'Y' << "�˿�";
		}
		cout << endl;
	}
	cout << "===========================================================" << endl;
	return 0;
}


/***************************************************************************
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    ����main������׼��
***************************************************************************/
int main()
{
	char file1[MAX_FILENAME_LEN], file2[MAX_FILENAME_LEN];

	cout << "������ǰһ��ѡ�ε������ļ� : ";
	cin >> file1;
	cout << "�������һ��ѡ�ε������ļ� : ";
	cin >> file2;

	stu_list list;

	/* �����һ�������ļ� */
	if (list.read(file1) < 0)
		return -1;

	/* ����ڶ��������ļ�������2��ֵΪ1��ʾ׷�ӷ�ʽ */
	if (list.read(file2, 1) < 0)
		return -1;

	list.print("����ѡ������");

	return 0;
}