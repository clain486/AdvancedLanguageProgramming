/*2151140 信07 王谦*/
/*2150482 黄建鑫 2151276 吕泓泰 2151289 陈名杰 2151789 张泽楷 2151295 王健宇*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

int charhex_to_int(char a, char b)
{
    int c = 0, d = 0;
    if (a >= 48 && a <= 57) {
        c = a - 48;
    }
    else if (a >= 97 && a <= 102) {
        c = a - 87;
    }
    if (b >= 48 && b <= 57) {
        d = b - 48;
    }
    else if (b >= 97 && b <= 102) {
        d = b - 87;
    }
    return (16 * c + d);
}
int charhex_to_int2(char a8, char a7, char a6, char a5, char a4, char a3, char a2, char a1)
{
    int b[9] = { 0 };
    if (a1 >= 48 && a1 <= 57) {
        b[0] = a1 - 48;
    }
    else if (a1 >= 97 && a1 <= 102) {
        b[0] = a1 - 87;
    }
    if (a2 >= 48 && a2 <= 57) {
        b[1] = a2 - 48;
    }
    else if (a2 >= 97 && a2 <= 102) {
        b[1] = a2 - 87;
    }
    if (a3 >= 48 && a3 <= 57) {
        b[2] = a3 - 48;
    }
    else if (a3 >= 97 && a3 <= 102) {
        b[2] = a3 - 87;
    }
    if (a4 >= 48 && a4 <= 57) {
        b[3] = a4 - 48;
    }
    else if (a4 >= 97 && a4 <= 102) {
        b[3] = a4 - 87;
    }
    if (a5 >= 48 && a5 <= 57) {
        b[4] = a5 - 48;
    }
    else if (a5 >= 97 && a5 <= 102) {
        b[4] = a5 - 87;
    }
    if (a6 >= 48 && a6 <= 57) {
        b[5] = a6 - 48;
    }
    else if (a6 >= 97 && a6 <= 102) {
        b[5] = a6 - 87;
    }
    if (a7 >= 48 && a7 <= 57) {
        b[6] = a7 - 48;
    }
    else if (a7 >= 97 && a7 <= 102) {
        b[6] = a7 - 87;
    }
    if (a8 >= 48 && a8 <= 57) {
        b[7] = a8 - 48;
    }
    else if (a8 >= 97 && a8 <= 102) {
        b[7] = a8 - 87;
    }
    int n = b[0] + b[1] * 16 + b[2] * 16 * 16 + b[3] * 16 * 16 * 16 + b[4] * 16 * 16 * 16 * 16 + b[5] * 16 * 16 * 16 * 16 * 16
        + b[6] * 16 * 16 * 16 * 16 * 16 * 16 + b[7] * 16 * 16 * 16 * 16 * 16 * 16 * 16;
    return n;
}


int main()
{
    clog << "文件名以下形式均可以:" << endl
        << "    a.txt                    : 不带路径形式" << endl
        << "    ..\\data\\b.dat          : 相对路径形式" << endl
        << "    C : \\Windows\\System32\\c.dat : 绝对相对路径形式" << endl;

    char input_from[4096];
    char input_to[4096];

    cout << "请输入要转换的hex格式文件名 : ";
    cin >> input_from;
    cout << "请输入转换后的文件名        : ";
    cin >> input_to;

    ifstream in(input_from, ios::in | ios::binary);
    ofstream out(input_to, ios::out | ios::binary);

    int open;
    if (!in.is_open()) {
        cout << "输入文件" << input_from << "打开失败!" << endl;
        open = 0;
    }
    else {
        open = 1;
    }

    int i, j = 16;
    char ch1[16];
    char array[128];
    int num = 0;

    while ((!in.eof()) && open) {     
        in.read(array, 82);
        int n = charhex_to_int2(array[0], array[1], array[2], array[3], array[4], array[5], array[6], array[7]);
        if (num != n) {
            cout << "最左侧的偏移量" << setfill('0') << setw(8) << hex << n << "不是期望值" << setfill('0') << setw(8) << hex << num << endl;
            break;
        }
        num += 16;
        for (i = 10; i < 56; i += 3) {
            if (i < 32) {
                if (array[i] == ' ' && array[i + 1] == ' ') {
                    j = (i - 10) / 3;
                    break;
                }
                ch1[(i - 10) / 3] = charhex_to_int(array[i], array[i + 1]);
            }
            else {
                if (array[i + 2] == ' ' && array[i + 3] == ' ') {
                    j = (i - 10) / 3;
                    break;
                }
                ch1[(i - 10) / 3] = charhex_to_int(array[i + 2], array[i + 3]);
            }
        }
        for (i = 0; i < j; i++) {
            out << ch1[i];
        }
    }
    out.close();
    in.close();
    return 0;
}