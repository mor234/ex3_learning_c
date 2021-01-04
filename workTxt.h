
#pragma once 
    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE 256
#define WORD 30
#define MAX_LINE_NUMBER 250
#define MAX_WORD_NUMBER ((int)(LINE/WORD))* MAX_LINE_NUMBER
/*
Get string char by char from standrat input and keep in string s. a line ends with '\n'
retrun number of char accepted.*/
int getLine(char s[]);
/*
Get string char by char from standrat input and keep in w string.
word ends with '\n','\t',' '
retrun number of char accepted.
*/
int  getword(char w[]);
/*
* the funcion gets 2 strings and check if str2 is substing of str1
* retrun 1 if true, 0 if false
*/
int substring(const char* str1, const char* str2);
/*
* the function get 2 string and integer.
* retrun true if can get from string s to sting t by leaveing 2 characer out.
*/
int similar(char* s, char* t, int n);
/*
* the function get string to look for, get the line of the text, (from standart input)
* and print the line the string appears in.
*/
void print_lines(char* str);
/*
the function get string to look for, get the words of the text (from standart input), and print the words that are similar to the string
(diffrent only by loosing one letter)
*/
void print_similar_words(char* str);
