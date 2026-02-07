#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

void insertAfter(struct Node *prevNode, int newData) {
    if (prevNode == NULL) {
        printf("Previous node cannot be NULL\n");
        return;
    }

    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = newData; 
    newNode->next = prevNode->next; 
    newNode->prev = prevNode; 

    if (prevNode->next != NULL)

        prevNode->next->prev = newNode;
        prevNode->next = newNode;
}

void deleteNode(struct Node **head, struct Node *delNode) 
{
    if (*head == NULL || delNode == NULL)
        return;

    if (*head == delNode)
        *head = delNode->next;

    if (delNode->next != NULL) 
        delNode->next->prev = delNode->prev; 

    if (delNode->prev != NULL) 
        delNode->prev->next = delNode->next;

    free(delNode);
}

void display(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    struct Node *first = NULL;
    struct Node *second = NULL;

    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = 10;
    first->prev = NULL;
    first->next = NULL;

    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = 20;
    second->prev = first;
    second->next = NULL;

    first->next = second;
    head = first;

    printf("Original Doubly Linked List:\n");
    display(head);

    insertAfter(first, 15);
    printf("\nAfter inserting 15 after 10:\n");
    display(head);

    deleteNode(&head, second);
    printf("\nAfter deleting 20:\n");
    display(head);

    return 0;
}
