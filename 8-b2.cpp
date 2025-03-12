/*2151140 ��07 ��ǫ*/
/*2150482 �ƽ��� 2151276 ����̩ 2151289 ������ 2151789 ���� 2151295 ������*/
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

using namespace std;

int main()
{
    clog << "�ļ���������ʽ������:" << endl
        << "    a.txt                    : ����·����ʽ" << endl
        << "    ..\\data\\b.dat          : ���·����ʽ" << endl
        << "    C : \\Windows\\System32\\c.dat : �������·����ʽ" << endl
        << "�������ļ��� : ";
    char output[4096];
    cin >> output;

    ifstream in(output, ios::in | ios::binary);

    int open;
    if (in.is_open() == 0) {
        cout << "�����ļ�" << output << "��ʧ��!" << endl;
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