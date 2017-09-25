//
//  main.c
//  func_pointers
//
//  Created by Anoja Rajalakshmi on 9/24/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
void add(int a, int b){
    printf("Addition is %d\n", a+b);
}
void subtract(int a, int b){
    printf("Subtraction is %d\n", a-b);
}
void multiply(int a, int b){
    printf("Multiplication is %d\n", a*b);
}
void fun(int a){
    printf("Value of a is %d\n", a);
}


int main(){
    unsigned int ch;
    
    void (*fun_ptr1)(int) = &fun;
    (*fun_ptr1)(10);
    
    //func’s name can also be used to get func’ address
    void (*fun_ptr2)(int) = fun;
    fun_ptr2(50);
    
    printf("Enter Choice: 0-add, 1-subtract and 2-multiply\n");
    scanf("%d", &ch);
    
    // fun_ptr_arr is an array of function pointers
    void (*fun_ptr_arr1[])(int, int) = {add, subtract, multiply};
    (fun_ptr_arr1[ch])(15, 10); // (*fun_ptr_arr1[ch])(15, 10);
    
    
    return 0;
}
