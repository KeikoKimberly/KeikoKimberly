#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

struct Node{
  int value;
  Node *next;
};

void moveNode(struct Node **destRef, struct Node **sourceRef){
  struct Node *newNode = *sourceRef;
  if(!newNode){
    return;
  }
  *sourceRef = newNode->next;
  newNode->next = *destRef;
  *destRef = newNode;
}

Node *sortedMerge(Node *a,Node *b){
  struct Node dummy;
  Node *tail = &dummy;
  dummy.next=NULL;

  while(1){
    if(a==NULL){
      tail->next=b;
      break;
    } else if(b==NULL){
      tail->next=a;
      break;
    }
    if (a->value <= b->value)
      moveNode(&(tail->next),&a);
      else
        moveNode(&(tail->next),&b);
        
      tail = tail->next;
  }
  return(dummy.next);
}

void push(struct Node **head_ref,int value){
  Node *newNode = (Node*)malloc(sizeof(Node));
  newNode->value = value;
  newNode->next = (*head_ref);
  (*head_ref)=newNode;
}

void printLinkedList(Node *curr){
  //Node *curr = head;
  while(curr!=NULL){ 
    printf("%d -> ",curr->value); //print data
    curr=curr->next; //curr akan berjalan ke node selanjutnya
  }
}

int main(){
  Node *res=NULL;
  Node *a = NULL;
  Node *b = NULL;
  push(&a,1);
  push(&a,3);
  push(&a,8);

  push(&b,2);
  push(&b,4);
  push(&b,5);

  res = sortedMerge(a,b);

  printLinkedList(res);

  return 0;
}
