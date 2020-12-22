#include <stdio.h>
#include <stdlib.h>
 
// Data Structure to store a linked list node
struct Node {
    int data;
    Node* next;
};
 
void createNode(Node **head, int data) {
    // create a new linked list node from heap
    struct Node* newNode = (Node*)malloc(sizeof(struct Node));
 
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
Node *getNFromtheEnd(Node *head, int k) {
    int n = 0;
    Node *curr = head;
 
    while (curr){
        curr = curr->next;
        n++;
    }
 
    if (n >= k){
        // return (n-k+1)th node from the beginning
        curr = head;
        for (int i = 0; i < n - k; i++)
            curr = curr->next;
    }
    return curr;
}
 
// main method
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 7, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    Node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
        createNode(&head, keys[i]);
 
    int k = 2;
    Node *node = getNFromtheEnd(head, k);
 
    if(node)
        printf("N node from the end is %d\n", node->data);
 
    return 0;
}




