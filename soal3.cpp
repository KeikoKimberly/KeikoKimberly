#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node { 
    int data; 
    struct Node *next; 
}; 
  
/* Function to get the middle of the linked list*/
void printMiddle(Node *head) { 
    int count = 0; 
    Node *mid = head; 
  
    while (head != NULL) { 
        // update mid, when count is odd number
        if (count & 1) 
            mid = mid->next; 
  
        ++count; 
        head = head->next; 
    } 
    /* if empty list is provided */
    if (mid != NULL) 
        printf("The middle element is [%d]\n\n", mid->data); 
} 
  
void push(Node **head_ref, int newData) { 
    Node *newNode = (Node*)malloc(sizeof(struct Node)); 

    newNode->data = newData; 
    newNode->next = (*head_ref);
    (*head_ref) = newNode; 
} 
  
void printLinkedList(Node *ptr) { 
    while (ptr != NULL) { 
        printf("%d->", ptr->data); 
        ptr = ptr->next; 
    } 
    printf("NULL\n"); 
} 
  
int main() {   
    Node *head = NULL; 
    int i; 
  
    for (i = 3; i > 0; i--) { 
        push(&head, i); 
        printLinkedList(head); 
        printMiddle(head); 
    } 
  
    return 0; 
}