//
//  main.c
//  reverse_words-C Program to reverse the words in a sentence
//  "cat is an animal" -> "animal an is cat"

//  Step 1: Reverse each word - tac si ns lamina
//  Step 2: Reverse the whole string

//  Created by Anoja Rajalakshmi on 9/13/17.
//  Copyright © 2017 Anoja Rajalakshmi. All rights reserved.

#include<stdio.h>

//Function to reverse any sequence starting with pointer begin and ending with pointer end
void reverse(char *begin, char *end){
    char temp;
    while (begin < end){
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}

//Function to reverse words
void reverseWords(char *s){
    char *word_begin = s;
    char *temp = s; // temp is for word boundry
    
    //STEP 1
    while( *temp ){
        temp++;
        if (*temp == '\0')
            reverse(word_begin, temp-1);
        else if(*temp == ' '){
            reverse(word_begin, temp-1);
            word_begin = temp+1;
        }
    }
    reverse(s, temp-1); //STEP 2
}

int main(){
    char s[] = "cat is an animal";
    char *temp = s;
    reverseWords(s);
    printf("%s\n", s);
    return 0;
}
