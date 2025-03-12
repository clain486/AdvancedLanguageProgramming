/* 2151140 信07 王谦 */
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string num[10], name[10];
	int grades[10] = { 0 }, order[10] = { 0 };
	int i, j, k, l, n = 0, mid;
	string med;
	for (i = 0; i < 10; i++) {
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> num[i] >> name[i] >> grades[i];
		if (grades[i] < 60) {
			n++;
		}
	}
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 9; j++) {
			
			if (grades[j] < grades[j + 1]) {
				continue;
			}
			else if (grades[j] > grades[j + 1]) {
				med = num[j];
				num[j]=num[j + 1];
				num[j + 1] = med;

				med= name[j];
			    name[j]= name[j + 1];
				name[j + 1]= med;

				mid = grades[j];
				grades[j] = grades[j + 1];
				grades[j + 1] = mid;
			}		
		}
	}
	cout << endl << "不及格名单(成绩升序):" << endl;
	for (l = 0; l < n; l++) {
		if (grades[l] < 60) {
			cout << name[l] << " " << num[l] << " " << grades[l] << endl;
		}
		else {
			n += 1;
		}
	}

	return 0;
}
