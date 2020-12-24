#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    int data;
    Node* next;
};
 
void push(Node **head, int new_data){
    Node *newNode=(Node*)malloc(sizeof(struct Node));
    newNode->data = new_data;
    newNode->next = (*head);
    (*head) = newNode;
}
 
int detectLoop(struct Node* list)
{
    struct Node *slow = list, *fast = list;
 
    while (slow && fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return 1;
        }
    }
    return 0;
}
 
/* Driver program to test above function*/
int main() {
    struct Node* head = NULL;
 
    push(&head, 20);
    push(&head, 4);
    push(&head, 15);
    push(&head, 10);
    // push(&head, 20);
 
    /* Create a loop for testing */
    head->next->next->next->next = head;
 
    if (detectLoop(head))
        printf("Loop found\n");
    else
        printf("No Loop\n");
    return 0;
}