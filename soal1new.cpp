#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct Node{ 
    int num; 
    Node* next; 
}; 
  
// Function to create newNode in a linkedlist 
Node* newNode(int key) 
{ 
    struct Node* temp = (Node*)malloc(sizeof(Node)); 
    temp->num = key; 
    temp->next = NULL; 
    return temp; 
} 
  
// A utility function to print linked list 
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
  
// Driver program 
int main() 
{ 
    Node *head1 = newNode(1); 
    head1->next = newNode(4); 
    head1->next->next = newNode(5); 
  
    // 1->4->5 LinkedList
  
    Node *head2 = newNode(0); 
    head2->next = newNode(2); 
    head2->next->next = newNode(6); 
  
    // 0->2->6 LinkedList 
  
    Node* mergedhead = merge(head1, head2); 
  
    printLinkedList(mergedhead); 
    return 0; 
} 