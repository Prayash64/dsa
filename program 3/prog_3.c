#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void reverseTraversal(struct Node *head) {
    if (head == NULL)
        return;

    reverseTraversal(head->next);
    printf("%d ", head->data);
}


int main() {
    struct Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);

    printf("Reverse Traversal of Linked List: ");
    reverseTraversal(head);
    printf("\n");

    return 0;
}
