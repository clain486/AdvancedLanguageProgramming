#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char p[10];
    strcpy(p,"123456789");
    
    /*①*/  p[10] = 'a';    //此句越界
    p[14] = 'A';    //此句越界
    p[15] = 'B';    //此句越界
    /*②*/ p[10] = '\xfd';  //此句越界
    cout << "addr:" << hex << (void*)(p) << endl;
    for (int i = -4; i < 16; i++) //注意，只有0-9是合理范围，其余都是越界读
        cout << hex << (void*)(p + i) << ":" << int(p[i]) << endl;
    /*③*/ delete[]p; 

    return 0;
}
