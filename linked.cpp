#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
  char name[255];
  int score;
  Node *next; //pointer ke node selanjutnya
} *head, *tail; //head node pertama , tail node terakhir

Node *createNode(const char *name,int score){
  Node *newNode = (Node*)malloc(sizeof(Node));
  strcpy(newNode->name, name);
  newNode->score = score;
  newNode->next = NULL; //awalnya tidak memliki node selanjutnya
  return newNode;
}
//awalnya head = nol,tail = nol
void pushTail(const char *name, int score){
  Node *temp = createNode(name,score); //buat nodenya

  if(!head){ // linked list kosong , temp akan menjadi head dan tail
    head = tail = temp;
  } else { // >= 1 node
  tail->next = temp; //tail lama -> next adalah node baru
  tail = temp; //temp akan menjadi tail (node terakhir)

  }
}

void pushHead(const char *name, int score){
  Node *temp = createNode(name,score); //buat node baru

  if(!head){
    head = tail = temp;
  } else{
    temp->next = head; // node setelah temp adalh head
    head = temp;  //head baru adalah temp
  }
}

void printLinkedList(){
  Node *curr = head; //curr adalah index yg akan berjalan

  while(curr){ //selama curr masih ada while(curr) == selama curr bukan NULL
    printf("%s -> ",curr->name); //print data
    curr=curr->next; //curr akan berjalan ke node selanjutnya
  }
}

void popHead(){
  if(!head){ //jika tidak ada node
    return; //return ga ngapa2in
  } else{
   Node *temp = head;
   head = temp->next;
   temp->next = NULL;
   free(temp);
  }
}

void popTail(){
  if(!head){
    return;
  } else if(head==tail){
    free(head);
  } else{
    Node *temp = head;
    while(temp->next!=tail){
      temp=temp->next;
    }
    temp->next = NULL;
    free(tail);
    tail=temp;
  }
}


int main(){
  //A5 -> B7 -> C9
  pushHead("Darnell",95);
  pushTail("whisper",97);
  pushHead("pai",100);
  pushHead("Roma",98);
  //popHead();
  //popTail();
  //popTail();
  //popHead();
  //pushTail("vincent",94);
  //pushTail("denny",93);
  printLinkedList();


  return 0;
}