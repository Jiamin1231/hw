/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 陳珈緡                              */
/* ID: 108820004                          */
/* Date: 2019.11.15    */
/* Purpose:determine whether the parentheses or braces are properly nested(10-1)                  */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 100

/*global variables*/
char contents[STACK_SIZE];
int top =0;

/*prototypes*/
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push (char ch);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void){
    bool properly_nested = true; //設定變數
    char ch;                    //設定變數

    printf("Enter parentheses and/or braces : "); //輸出

    //determine whether they are properly nested
    while(properly_nested &&(ch=getchar())!='\n'){
        if(ch=='(' || ch=='{'){
            push(ch);
           }else if(ch ==')'){
               properly_nested = !is_empty() && pop()=='(';
           }else if(ch =='}'){
               properly_nested = !is_empty() && pop()=='{';
           }
    }

    //輸出
    if (properly_nested && is_empty()){
        printf("Parentheses/braces are nested properly\n");
    }else{
        printf("Parentheses/braces are NOT nested properly\n");
    }

    return 0;
}

//清空,top=0代表使之沒有東西堆疊
void make_empty(void){
    top=0;
}

//top值為0時,代表是空的
bool is_empty(void){
    return top==0;
}

//top值為STACK_SIZE時,代表是滿的
bool is_full(void){
    return top==STACK_SIZE;
}

//若是滿的則呼叫stack_overflow(),不然則在contents[top]的地方存入ch,並將top的值加1
void push(char ch){
    if(is_full()){
        stack_overflow();
    }else{
        contents[top++]=ch;
    }
}

//若是滿的則呼叫stack_underflow(),不然先將top的值減1,再回傳contents[top]
char pop(void){
    if(is_empty()){
        stack_underflow();
    }else{
        return contents[--top];
    }

    return '\0';
}


void stack_overflow(void){
    printf("Stack overflow\n"); //輸出
    exit(EXIT_FAILURE);
}

void stack_underflow(void){
    printf("Stack underflow\n");    //輸出
    exit(EXIT_FAILURE);
}


