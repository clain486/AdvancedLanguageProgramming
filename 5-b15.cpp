/* 2151140 ��07 ��ǫ */
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int j, k, i;
	int up_num = 0, low_num = 0, numb_num = 0, space_num = 0, other_num = 0;
	char str[3][128];
	int length[3] = { 0 };

	for (i = 0; i < 3; i++) {
		cout << "�������"<< i+1 <<"��" << endl;
		fgets(str[i], 128, stdin);
		length[i] = strlen(str[i])-1;
		for (k = 0; k < length[i]; k++) {
			if (str[i][k] == 32) {
				space_num++;
			}
			else if (str[i][k] >= 65 && str[i][k] <= 90) {
				up_num++;
			}
			else if (str[i][k] >= 97 && str[i][k] <= 122) {
				low_num++;
			}
			else if (str[i][k] >= 48 && str[i][k] <= 57) {
				numb_num++;
			}
			else {
				other_num++;
			}
		}
	}
	cout << "��д : " << up_num << endl;
	cout << "Сд : " << low_num << endl;
	cout << "���� : " << numb_num << endl;
	cout << "�ո� : " << space_num << endl;
	cout << "���� : " << other_num << endl;

	return 0;
}