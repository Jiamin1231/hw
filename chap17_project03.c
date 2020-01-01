/*****************************************************************/
/* Class: Computer Programming, Fall 2019                        */
/* Author: 陳珈緡                              */
/* ID: 108820004                          */
/* Date: 2019.12.29    */
/* Purpose: inventory (17-3)                  */
/* Change History: log the change history of the program         */
/*****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define NAME_LEN 25

//declare a structure tag
struct part {
  int number;
  char name[NAME_LEN+1];
  int on_hand;
  struct part *next;
};

struct part *inventory = NULL;

//宣告函式
struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void erase(void);
int read_line(char str[],int n);

int main(void){

    char code;

    for(;;){
    printf("Enter operation code: ");   //輸出
    scanf(" %c", &code);    //輸入
    while ((getchar()) != '\n')   /* skips to end of line */
      ;
    switch (code) {         //呼叫對應的函式
      case 'i': insert();
                break;
      case 's': search();
                break;
      case 'e': erase();
                break;
      case 'u': update();
                break;
      case 'p': print();
                break;
      case 'q': return 0;
      default:  printf("Illegal code\n");   //輸出
    }
    printf("\n");   //輸出
  }
}

/*Look up a part number in the inventory list.*/
struct part *find_part(int number){

    struct part *p;

    for(p = inventory;                      //finding
        p !=NULL && number > p->number;
        p = p->next)
      ;
      if(p !=NULL && number == p->number) //find it
        return p;
      return NULL;
}

/*insert the part into the inventory list*/
void insert(void)
{
  struct part *cur, *prev, *new_node;   //設定變數

  new_node = malloc(sizeof(struct part));   //allocate memory

  if (new_node == NULL) {       //test to see if it's a null pointer
    printf("Database is full; can't add more parts.\n");//輸出
    return;
  }

  printf("Enter part number: "); //輸出
  scanf("%d", &new_node->number); //enter new part number

  for (cur = inventory, prev = NULL;    //find the location to insert the new part
       cur != NULL && new_node->number > cur->number;
       prev = cur, cur = cur->next)
    ;
  if (cur != NULL && new_node->number == cur->number) { //check if it's already existed
    printf("Part already exists.\n");
    free(new_node); //release the memory
    return;
  }

  printf("Enter part name: ");  //輸出
  read_line(new_node->name, NAME_LEN);  //讀入
  printf("Enter quantity on hand: ");   //輸出
  scanf("%d", &new_node->on_hand);  //讀入

  new_node->next = cur;
  if (prev == NULL)         //pre為null代表在最開始的位置
    inventory = new_node;
  else
    prev->next = new_node;
}

void erase(void){

    struct part *cur,*prev;
    int n;

    printf("Enter part number: ");
    scanf("%d",n);

    for (cur = inventory;
         cur != NULL && cur->number != n;
         prev = cur, cur = cur->next)
    ;

    if(cur == NULL){                             /*n was not found.*/
        printf("Part number %d not found in database\n",n);
    }else if(prev == NULL){                   /*n is in the first node.*/
            inventory = inventory->next;
    }else{                               /*n is in some other node.*/
        prev->next = cur->next;
        free(cur);
    }
}



/*look up the part in the database*/
void search(void)
{
  int number;       //設定變數
  struct part *p;

  printf("Enter part number: ");    //輸出
  scanf("%d", &number);     //輸入
  p = find_part(number);    //finding
  if (p != NULL) {                                  //若不是空指標,則印出p指到內的東西
    printf("Part name: %s\n", p->name);
    printf("Quantity on hand: %d\n", p->on_hand);
  } else
    printf("Part not found.\n");
}

/* Enter change in quantity on hand and update the database*/
void update(void)
{
  int number, change;   //設定變數
  struct part *p;

  printf("Enter part number: ");    //輸出
  scanf("%d", &number); //輸入
  p = find_part(number);    //檢查是否有在裡面

  if (p != NULL) {      //若有在裡面
    printf("Enter change in quantity on hand: ");   //輸出
    scanf("%d", &change);   //輸入
    p->on_hand += change;   //改變裡面的數量
  } else
    printf("Part not found.\n");    //輸出
}

/*Print a listing of all parts in the database*/
void print(void)
{
  struct part *p;   //設定變數

  printf("Part Number   Part Name                  "
         "Quantity on Hand\n"); //輸出
  //輸出
  for (p = inventory; p != NULL; p = p->next)
    printf("%7d       %-25s%11d\n", p->number, p->name,
           p->on_hand);
}

int read_line(char str[], int n)
{
  int ch, i = 0;         //設立變數

  while (isspace(ch = getchar()))
    ;
  while (ch != '\n' && ch != EOF) { //若讀入的值不為換行符號就繼續
    if (i < n)                      //若沒有超過可存字元數,就將讀到的值存入str
      str[i++] = ch;
    ch = getchar();
  }
  str[i] = '\0';    /*terminates string */
  return i;     /*number of characters stored */
}
