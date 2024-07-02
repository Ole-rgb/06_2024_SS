// Binary List machen aus gegebenem integervalue

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct IntList
{
    int data;
    struct IntList *next;
} IntList;

IntList *newNode(int data)
{
    IntList *node = malloc(sizeof(IntList));
    node->data = data;
    node->next = malloc(sizeof(IntList));
    return node;
}

void push(IntList **head, int data)
{
    IntList *new = newNode(data);
    new->next = (*head);
    (*head) = new;
}

void pop(IntList **head)
{
    (*head) = (*head)->next;
}

void printList(IntList *head)
{
    if (head == NULL)
    {
        printf("nothing to print, since list is empty\n");
    }
    IntList *current = head;
    int i = 1;
    while (current != NULL)
    {
        printf("%d.data %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

int getListSize(IntList *head)
{
    int listSize = 0;
    IntList *copy = head;
    while (copy != NULL)
    {
        listSize++;
        copy = copy->next;
    }
    return listSize;
}

int main()
{
    IntList *head = NULL;
    int testData = 12345;

    while (testData > 0)
    {
        push(&head, testData % 10);
        testData /= 10;
    }

    printList(head);
}
