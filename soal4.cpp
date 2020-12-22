#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct Node { 
    int data; 
    Node *next; 
}; 
 
void removeDuplicates(Node *head) { 
    Node *current = head; 
  
    Node* next_next;  
    
    if (current == NULL)  
       return;  
  
    while (current->next != NULL) {
       if (current->data == current->next->data) { 
           // The sequence of steps is important              
           next_next = current->next->next; 
           free(current->next); 
           current->next = next_next;   
       } 
       else 
       { 
          current = current->next;  
       } 
    } 
} 

void pushHead(struct Node **head, int new_data) { 
    //alllocate node
    Node *newNode = (Node*) malloc(sizeof(Node)); 
    newNode->data  = new_data; 
    newNode->next = (*head);      
    (*head)    = newNode; 
} 
  
/* Function to print nodes in a given linked list */
void printLinkedList(Node *node) 
{ 
    while (node!=NULL) 
    { 
       printf("%d ", node->data); 
       node = node->next; 
    } 
}  
  
/* Driver program to test above functions*/
int main() { 
    Node *head = NULL; 

     //link list 11->11->11->13->13->20
    pushHead(&head, 20); 
    pushHead(&head, 13); 
    pushHead(&head, 13);   
    pushHead(&head, 11); 
    pushHead(&head, 11); 
    pushHead(&head, 11);                                     
  
    printf("\n Linked list before duplicate removal : "); 
    printLinkedList(head);  
 
    removeDuplicates(head);  
  
    printf("\n Linked list after duplicate removal : ");          
    printLinkedList(head);             
    
    return 0; 
} 