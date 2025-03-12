/* 2151140 信07 王谦 */
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
		cout << "请输入第"<< i+1 <<"行" << endl;
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
	cout << "大写 : " << up_num << endl;
	cout << "小写 : " << low_num << endl;
	cout << "数字 : " << numb_num << endl;
	cout << "空格 : " << space_num << endl;
	cout << "其它 : " << other_num << endl;

	return 0;
}