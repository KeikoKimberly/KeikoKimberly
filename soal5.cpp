#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node { 
    int data; 
    Node* next; 
}; 
  
void printNthFromLast(struct Node* head, int n) { 
    static int i = 0; 
    if (head == NULL) 
        return; 
    printNthFromLast(head->next, n); 
    if (++i == n) 
        printf("\n%d", head->data); 
} 
  
void push(struct Node** head_ref, int new_data) { 
    /* allocate node */
    struct Node* new_node = new Node(); 

    new_node->data = new_data; 
    new_node->next = (*head_ref); 
    (*head_ref) = new_node; 
} 
  
int main() { 
    Node* head = NULL; 

    // create linked 35->15->4->20 
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 35); 
  
    printNthFromLast(head, 4); 
    return 0; 
}