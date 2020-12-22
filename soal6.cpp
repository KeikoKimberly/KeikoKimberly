#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
  int data;
  Node *next; //pointer ke node selanjutnya
}*head; //node pertama ,variabel global

Node *createNode(int data){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->data = data;
  newNode->next = NULL;
  return newNode;
}

void pushHead(int data){
  Node *temp = createNode(data);
  if(!head){
    head = temp;
  } else {
    temp->next = head;
    head = temp;
  }
}

void printLinkedList(){
  Node *curr = head;
  while(curr){
    printf("%d ",curr->data);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  //ascending linked list
  pushHead(1);
  pushHead(2);
  pushHead(3);
  pushHead(4);
  pushHead(5);

  //descending linked list
  printLinkedList();

return 0;
}