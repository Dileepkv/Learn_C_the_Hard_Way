//
//  main.c
//  understanding_memory

#include <stdio.h>
#pragma pack(1)
struct testElement{
    char a;
    int b;
} ;
struct testElement test[10];
int main(int argc, const char * argv[]) {
    test[0].a='a';
    test[0].b= 3;
    printf("%lu\n",sizeof(test[0].a));
    printf("%lu\n",sizeof(test[0].b));
    printf("%lu\n",sizeof(test[0]));
    printf("%lu\n",sizeof(test));
    return 0;
}
