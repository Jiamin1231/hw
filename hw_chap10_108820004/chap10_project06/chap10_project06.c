/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 陳珈緡                              */
/* ID: 108820004                          */
/* Date: 2019.11.16    */
/* Purpose:rpn(10-6)                  */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define STACK_SIZE 100

/*global variables */
int contents[STACK_SIZE];
int top = 0;

/*prototypes */
void make_empty(void);
bool is_empty(void);
bool is_full(void);
void push(int i);
char pop(void);
void stack_overflow(void);
void stack_underflow(void);

int main(void){

    char ch;        //設定變數
    int opl, op2;   //設定變數
    printf("Enter an RPN expression : ");//輸出
    for(;;){
        scanf("%c",&ch);    //輸入

        switch(ch){
            case '0': case '1' : case '2' : case '3':  case'4':  //使運算的值界在0~9間
            case '5': case '6' : case '7' : case '8':  case'9':
                push(ch - '0');
                break;
            case '+':                   //遇到加號時,將先pop出來的值相加
                push(pop() + pop());
                break;
            case '-':                   //遇到減號時,將先pop出來的值相減
                op2 = pop();
                opl = pop();
                push(op1 - op2);
                break;
            case '*':                   //遇到乘號時,將先pop出來的值相乘
                push(pop() * pop());
                break;
            case '/':                   //遇到除號時,將先pop出來的值相除
                op2 = pop();
                opl = pop();
                push(op1/op2);
                break;
            case '=':                   //遇到等號時,將先pop出來的值印出
                printf("Value of expression : %d\n ", pop());
                make_empty();           //清空
                printf("Enter an RPN expression : ");//輸出
                break;
                default:                //遇到不是operator或operand就結束
                    exit(EXIT_SUCCESS);
        }
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

//若是滿的則呼叫stack_overflow(),不然則在contents[top]的地方存入i,並將top的值加1
void push(int i){
    if(is_full()){
        stack_overflow();
    }else{
        contents[top++]=i;
    }
}

//若是滿的則呼叫stack_underflow(),不然先將top的值減1,再回傳contents[top]
char pop(void){
    if(is_empty()){
        stack_underflow();
    }else{
        return contents[--top];
    }
    /*prevent compiler warning*/
    return '\0';
}

void stack_overflow(void){
    printf("Expression is too complex\n"); //輸出
    exit(EXIT_FAILURE);
}

void stack_underflow(void){
    printf("Not enough operands in expression\n"); //輸出
    exit(EXIT_FAILURE);
}
