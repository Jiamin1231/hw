/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 陳珈緡                              */
/* ID: 108820004                          */
/* Date: 2019.11.15    */
/* Purpose:classify a poker hand (10-2)                  */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/*global variables*/
bool straight,flush,four,three;
int pairs; /*can be 0,1 or 2*/

//宣告函式
void read_cards(int num_in_rank[],int num_in_suit[]);
void analyze_hand(int num_in_rank[],int num_in_suit[]);
void print_result(void);

int main(void){

    int num_in_rank[NUM_RANKS]; //用來儲存撲克牌數字的陣列
    int num_in_suit[NUM_SUITS]; //用來儲存撲克牌花色的陣列

    for(;;){
        read_cards(num_in_rank,num_in_suit);    //呼叫函式
        analyze_hand(num_in_rank,num_in_suit);  //呼叫函式
        print_result();                         //呼叫函式
    }
    return 0;
}

/*read_cards : read the cards into the parameters
                num_in_rank and num_in_suit;
                check for bad cards and duplicate cards.*/

void read_cards(int num_in_rank[],int num_in_suit[]){

    bool card_exists[NUM_RANKS][NUM_SUITS];  //設定變數
    char ch,rank_ch,suit_ch;        //設定變數
    int rank,suit;                  //設定變數
    bool bad_card;                  //設定變數
    int cards_read=0;               //設定變數

    //將num_in_rank 和 num_in_suit初始化
    for(rank = 0; rank<NUM_RANKS;rank++){
        num_in_rank[rank]=0;
        for(suit = 0;suit<NUM_SUITS;suit++){
            card_exists[rank][suit]=false;
        }
    }
    for(suit =0;suit<NUM_SUITS ;suit++){
        num_in_suit[suit]=0;
    }

    //讀5張牌
    while(cards_read<NUM_CARDS){
        bad_card=false;
        printf("Enter a card : ");

        rank_ch=getchar();      //讀輸入的數字轉成數值
        switch(rank_ch){
            case '0':           exit(EXIT_SUCCESS);
            case '2':           rank =0; break;
            case '3':           rank =1; break;
            case '4':           rank =2; break;
            case '5':           rank =3; break;
            case '6':           rank =4; break;
            case '7':           rank =5; break;
            case '8':           rank =6; break;
            case '9':           rank =7; break;
            case 't': case 'T': rank =8; break;
            case 'j': case 'J': rank =9; break;
            case 'q': case 'Q': rank =10; break;
            case 'k': case 'K': rank =11; break;
            case 'a': case 'A': rank =12; break;
            default:            bad_card=true;  //若輸入的字元不在上面的範圍,bad_card=true
        }

        //讀輸入的花色轉成數值
        suit_ch = getchar();
        switch(suit_ch){
            case 'c': case 'C': suit =0;break;
            case 'd': case 'D': suit =1;break;
            case 'h': case 'H': suit =2;break;
            case 's': case 'S': suit =3;break;
            default: bad_card=true; //若輸入的字元不在上面的範圍,bad_card=true
        }

        //如果讀到的字元不是空格或換行符號,bad_card=true
        while((ch=getchar())!='\n'){
            if(ch!=' ')bad_card=true;
        }

        if(bad_card){
            printf("Bad card; ignored.\n"); //如果bad_card為true,則輸出
        }else if(card_exists[rank][suit]){
            printf("Duplicate card; ignores.\n");//如果card_exists[rank][suit]為true,則輸出
        }else{
            num_in_rank[rank]++;
            num_in_suit[suit]++;
            card_exists[rank][suit]=true;
            cards_read++;
        }
    }
}


 /*analyze_hand : Determine whether the hand contains a
 straight,a flush,four-of-a-kind,and/or three-of-a-kind;
 determines the number of pairs;stores the result into the
 global variables straight,flush,four,three,and pairs.*/

 void analyze_hand(int num_in_rank[], int num_in_suit[]){

    int num_consec=0;   //設定變數
    int rank, suit;     //設定變數
    straight = false;   //設定變數
    flush = false;      //設定變數
    four = false;       //設定變數
    three = false;      //設定變數
    pairs =0;           //設定變數

    /*check for flush*/
    for(suit = 0; suit < NUM_SUITS ; suit++){
        if(num_in_suit[suit] == NUM_CARDS){
            flush =true;
        }
    }

    /*check for straight*/
    rank = 0;
    while(num_in_rank[rank]== 0) rank++ ;
    for(; rank < NUM_RANKS && num_in_rank[rank] > 0 ; rank++){
        num_consec++;
    }
    if(num_consec == NUM_CARDS){
        straight = true;
        return;
    }
    /* check for 4-of-a-kind, 3-of-a-kind and pairs*/
    for(rank = 0; rank < NUM_RANKS ; rank++){
        if(num_in_rank[rank] == 4) four = true;
        if(num_in_rank[rank] == 3) three = true;
        if(num_in_rank[rank] == 2) pairs++;
    }
}


/*print_result : Prints the classification of the hand,
based on the values of the global
variables straight, flush, four, three,
and pairs.*/
void print_result(void){

    if(straight && flush) printf("Straight flush");
    else if (four)              printf("Four of a kind");
    else if (three&&pairs==1)   printf("Full house");
    else if (flush)             printf("Flush");
    else if (straight)          printf("Straight");
    else if (three)             printf("Three of a kind");
    else if(pairs == 2)         printf("Two pairs");
    else if(pairs == 1)         printf("Pair");
    else    printf("High card");

printf("\n\n");
}
