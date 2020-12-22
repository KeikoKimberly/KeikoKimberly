#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node{ 
    int num; 
    Node* next; 
}; 
  
// Function to create newNode in a linkedlist 
Node *createNode(int key){ 
    Node *newNode = (Node*)malloc(sizeof(Node)); 
    newNode->num = key; 
    newNode->next = NULL; 
    return newNode; 
} 

void printLinkedList(Node *curr) 
{ 
    while (curr!=NULL){ 
        printf("%d  ",curr->num); 
        curr=curr->next; 
    } 
} 
  
Node *merge(Node *h1,Node *h2){ 
    if(!h1) 
        return h2; 
    if(!h2) 
        return h1; 
   
    if (h1->num < h2->num){ 
        h1->next = merge(h1->next, h2); 
        return h1; 
    } else{ 
        h2->next = merge(h1, h2->next); 
        return h2; 
    } 
} 
  
int main() { 
    Node *head1 = createNode(1); 
    head1->next = createNode(4); 
    head1->next->next = createNode(5); 
  
    // 1->4->5 LinkedList
  
    Node *head2 = createNode(0); 
    head2->next = createNode(2); 
    head2->next->next = createNode(6); 
  
    // 0->2->6 LinkedList 
  
    Node *mergedhead = merge(head1, head2); 
  
    printLinkedList(mergedhead); 
    return 0; 
} 