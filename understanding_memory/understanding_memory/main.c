//
//  main.c
//  understanding_memory

#include <stdio.h>
//#pragma pack(1)
struct testElement{
    int c;
    int b;
    char a;
} ;
union unionElement{
    char c;
    int d;
} ;

union student
{
    char name[20];
    char subject[20];
    float percentage;
};
struct testElement test[10];
union unionElement elem[10];

int main(int argc, const char * argv[]) {
    test[0].a='a';
    test[0].b= 3;
    printf("%lu\n",sizeof(test[0].a));
    printf("%lu\n",sizeof(test[0].b));
    printf("%lu\n",sizeof(test[0]));
    printf("%lu\n",sizeof(test));
    printf("%c\n",test[0].a);
    elem[0].c='r';
    elem[0].d= 3;
    printf("%lu\n",sizeof(elem[0].c));
    printf("%lu\n",sizeof(elem[0].d));
    printf("%lu\n",sizeof(elem[0]));
    printf("%lu\n",sizeof(elem));
    printf("%c\n",elem[0].c);
    printf("%lu\n",elem[0].d);
    
    union student record1;
    union student record2;
    union student * ptr1 = &record1;
    union student * ptr2 = &record2;

    printf("Address location of record1: %d\n",ptr1);
    printf("Address location of record2: %d\n",ptr2);//24 bytes each
    
    // assigning values to record1 union variable
    strcpy(record1.name, "Raju");
    strcpy(record1.subject, "Maths");
    record1.percentage = 86.50;
    //we can always access only one union member for which value is assigned at last. We can’t access other member values.

    printf("\nUnion record1 values example\n");
    printf(" Name       : %s \n", record1.name);
    printf(" Subject    : %s \n", record1.subject);
    printf(" Percentage : %f \n\n",record1.percentage);
    
    // assigning values to record2 union variable
    printf("Union record2 values example\n");
    //If we don’t access them before assigning values to other member, member name and value will be over written by other member as all members are using same memory.
    record2.percentage = 99.50;
    printf(" Percentage : %f \n", record2.percentage);

    strcpy(record2.name, "Mani");
    printf(" Name       : %s \n", record2.name);
    
    strcpy(record2.subject, "Physics");
    printf(" Subject    : %s \n", record2.subject);
    return 0;
}

