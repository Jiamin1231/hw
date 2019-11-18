/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 陳珈緡                              */
/* ID: 108820004                          */
/* Date: 2019.11.16    */
/* Purpose:classify a poker hand (10-3)                  */
/* Change History: log the change history of the program         */
/*****************************************************************/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_RANKS 13
#define NUM_SUITS 4
#define NUM_CARDS 5

/*global variables*/
int hand[NUM_CARDS][2];
bool straight, flush, four, three;
int pairs;

/*宣告函式*/
void read_cards(void);
bool duplicate_card(int rank, int suit, int hand[NUM_CARDS][2], int cards_read);
void analyze_hand(void);
void print_result(void);


int main(void) {
    for (;;){
        read_cards();       //呼叫函式
        analyze_hand();     //呼叫函式
        print_result();     //呼叫函式
    }
}

void read_cards(void){

    char c, rank_ch, suit_ch;   //設定變數
    int rank, suit;             //設定變數
    bool bad_card;              //設定變數
    int cards_read = 0;         //設定變數

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
        while((c=getchar())!='\n'){
            if(c!=' ')bad_card=true;
        }

        if(bad_card){
            printf("Bad card; ignored.\n"); //如果bad_card為true,則輸出
        }else if(duplicate_card(rank,suit,hand,cards_read)){
            printf("Duplicate card; ignores.\n");//如果duplicate_card為true,則輸出
        }else{
            hand[cards_read][0] = rank;
            hand[cards_read][1] = suit;
            cards_read++;
        }
    }
}

//判斷是否有重複輸入的牌
bool duplicate_card(int rank, int suit, int hand[NUM_CARDS][2], int cards_read){
    int i;
    for (i= 0; i < cards_read; i++)
        if(suit==hand[i][1]&&rank==hand[i][0])
            return true;
    return false;
}


 /*analyze_hand : Determine whether the hand contains a
 straight,a flush,four-of-a-kind,and/or three-of-a-kind*/
void analyze_hand(void) {
    int num_consec =0;          //設定變數
    int card, rank, matches;    //設定變數

    straight = false;           //設定變數
    flush = false;              //設定變數
    four = false;               //設定變數
    three = false;              //設定變數
    pairs =0;                   //設定變數

    int i, j, smallest, temp_suit, temp_rank;
    for (i = 0; i < NUM_CARDS; i++) {
        smallest =i;

        for (j = i + 1; j <NUM_CARDS; j++) {
            if (hand[j][0] < hand[smallest][0])
                smallest =j;
        }

        temp_rank=hand[i][0];
        temp_suit=hand[i][1];
        hand[i][0]= hand[smallest][0];
        hand[i][1]= hand[smallest][1];
        hand[smallest][0] = temp_rank;
        hand[smallest][1] = temp_suit;
    }

    /*check for flush*/
    for (card = 1; card < NUM_CARDS; card++) {
        if (hand[card][1] != hand[0][1])
            break;
        if (card == NUM_CARDS - 1)
            flush = true;
    }

    /*check for straight*/
    for (card = 1; card < NUM_CARDS; card++) {
        if (hand[card][0] - hand[card-1] [0] != 1)
            break;
        if (card == NUM_CARDS - 1)
            straight = true;
    }

    /* check for 4-of-a-kind, 3-of-a-kind and pairs*/
    for (i = 0; i < NUM_CARDS; i++) {
        matches = 0;
        for (j= i+ 1; j< NUM_CARDS; j++) {
            if (hand[j][0] == hand[i][0])
                matches++;
        }
        if (matches == 1) pairs++;
        if (matches == 2) three = true;
        if (matches == 3) four = true;
    }
}


/*print_result : Prints the classification of the hand*/
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
