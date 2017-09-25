//
//  main.c
//  bit_manipulation


//  Created by Anoja Rajalakshmi on 9/22/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define set_bit(num,bit) (num |= (1<<bit))
#define clear_bit(num,bit) (num &= ~(1<<bit))
#define check_bit(num,bit) ((num & (1<<bit))!=0)

/*Given a (decimal - e.g. 3.72) number that is passed in as a string, print the binary representation. If the number can not be represented accurately in binary, print “ERROR”
 */

void string_to_binary(){
    char *str = "1024.67";
    char *check =str;
    int size = strlen(str);
    while(size--){
        if(!(*check > '0' || *check < '9'|| *check =='.')){
            printf("Error\n");
            return;
        }
        *check++;
    }
    double num = atof(str);
    printf("Converted Num %f\n",num);
    int left = num;
    double right = num - left;
    printf("Right %f\n",right);
    
    int result[sizeof(double)];
    int *temp_left=-1;
    while (left > 0) {
        int r = left % 2;
        left >>= 1;
        *temp_left = r + *temp_left;
        }
    printf("%s",temp_left);
}
/*  You are given two 32-bit numbers, N and M, and two bit positions, i and j. Write a method to set all bits between i and j in N equal to M (e.g., M becomes a substring of N located at i and starting at j).
 EXAMPLE:
 Input: N = 10000000000, M = 10101, i = 2, j = 6
 Output: N = 10001010100
 */
void make_substring(){
    int N = 1024; //10000000000
    int M = 21; //10101
    int i=2,j=6;
    for (int m=0;m<(j-i+1);m++){
        if(check_bit(M,m))
            set_bit(N,(i+m));
        else
            clear_bit(N,(i+m));
    }
    printf("%d\n",N); //1108 in dec

}
int main(int argc, const char * argv[]) {
    make_substring();
    string_to_binary();
    return 0;
}
