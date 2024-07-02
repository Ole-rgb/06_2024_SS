// Bsp : 65->[1, 0, 0, 0, 0, 0, 1] 0 -> [0] 10 -> [1, 0, 1, 0]

#include <stdlib.h>
#include <stdio.h>

typedef struct IntNode
{
    int data;
    struct IntNode *next;
} IntNode;

IntNode *newNode(int data)
{
    IntNode *new = malloc(sizeof(IntNode));
    new->data = data;
    new->next = NULL;
}

void push(IntNode **head, int data)
{
    IntNode *new = newNode(data);
    new->next = (*head);
    (*head) = new;
}

void printList(IntNode *head)
{
    while (head != NULL)
    {
        printf("%d,", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    int testNumber = 65;
    IntNode *head = NULL;
    while (testNumber != 0)
    {
        push(&head, testNumber % 2);
        testNumber /= 2;
    }
    printList(head);
}