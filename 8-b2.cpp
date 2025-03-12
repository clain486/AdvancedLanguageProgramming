/*2151140 信07 王谦*/
/*2150482 黄建鑫 2151276 吕泓泰 2151289 陈名杰 2151789 张泽楷 2151295 王健宇*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
    clog << "文件名以下形式均可以:" << endl
        << "    a.txt                    : 不带路径形式" << endl
        << "    ..\\data\\b.dat          : 相对路径形式" << endl
        << "    C : \\Windows\\System32\\c.dat : 绝对相对路径形式" << endl
        << "请输入文件名 : ";
    char output[4096];
    cin >> output;

    ifstream in(output, ios::in | ios::binary);

    int open;
    if (in.is_open() == 0) {
        cout << "输入文件" << output << "打开失败!" << endl;
        open = 0;
    }
    else {
        open = 1;
    }

    char array[1024];
    int len = 0;
    int n = 0;

    while (open) {
        int i = 0;
        int judge = 0;
        for (len = 0; !in.eof() && len < 16;) {
            array[len] = in.get();
            if (!in.eof()) {
                len++;
            }           
        }
        if (len == 0) {
            break;
        }
        if (array[len] == EOF && len < 16) {
            cout << setfill('0') << setw(8) << hex << n << "  ";
            n += 16;
            for (int j = i; j < len; j++) {
                if (j == i + 8) {
                    cout << "- ";
                    judge = 1;
                }
                cout << hex << setw(2) << setfill('0') << (int)(unsigned char)array[j] << " ";
            }
            for (int j = (len % 16); j < 16; j++) {
                cout << "   ";
            }
            if (judge == 1) {
                cout << "    ";
            }
            else {
                cout << "      ";
            }
            for (i; i < len; i++) {
                if (array[i] >= 33 && array[i] <= 126) {
                    cout << (unsigned char)array[i];
                }
                else {
                    cout << '.';
                }
            }
            cout << endl;
        }
        else if (len - i < 16) {
            cout << setfill('0') << setw(8) << hex << n << "  ";
            n += 16;
            for (int j = i; j < len; j++) {
                if (j == i + 8) {
                    cout << "- ";
                    judge = 1;
                }
                cout << hex << setw(2) << setfill('0') << (int)(unsigned char)array[j] << " ";
            }
            for (int j = (len % 16); j < 16; j++) {
                cout << "   ";
            }
            if (judge == 1) {
                cout << "    ";
            }
            else {
                cout << "      ";
            }
            for (i; i < len; i++) {
                if (array[i] >= 33 && array[i] <= 126) {
                    cout << (unsigned char)array[i];
                }
                else {
                    cout << '.';
                }
            }
            cout << endl;
            break;
        }
        else {
            cout << setfill('0') << setw(8) << hex << n << "  ";
            n += 16;
            for (int j = i; j < i + 16; j++) {
                if (j == i + 8) {
                    cout << "- ";
                }
                cout << hex << setw(2) << setfill('0') << (int)(unsigned char)array[j] << " ";
            }
            cout << "    ";
            for (int j = i; j < i + 16; j++) {
                if (array[j] >= 33 && array[j] <= 126) {
                    cout << (unsigned char)array[j];
                }
                else {
                    cout << '.';
                }
            }
            cout << endl;
            i += 16;
        }
    }

    in.close();
    return 0;
}