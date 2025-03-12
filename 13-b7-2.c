#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int p[10] = { 1,2,3,4,5,6,7,8,9 };
    
    /*①*/  p[10] = 'a';    //此句越界
    p[14] = 'A';    //此句越界
    p[15] = 'B';    //此句越界
    /*②  p[10] = '\xfd';*/  //此句越界
    printf("addr:%p\n", p);
    for (int i = -4; i < 16; i++) //注意，只有0-9是合理范围，其余都是越界读
        printf("%p:%02x\n", (p + i), p[i]);
    /*③*/  free(p);

    return 0;
}

