// Differenz zwischen dem minimalen und dem maximalem Element in einer Liste von INT berechnen

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

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

int findMax(IntList *head)
{
    int max = INT_MIN;
    IntList *copy = head;
    while (copy != NULL)
    {
        if (max < copy->data)
        {
            max = copy->data;
        }
        copy = copy->next;
    }
    return max;
}

int findMin(IntList *head)
{
    int min = INT_MAX;
    IntList *copy = head;
    while (copy != NULL)
    {
        if (min > copy->data)
        {
            min = copy->data;
        }
        copy = copy->next;
    }
    return min;
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
    int testData = 12349;

    while (testData > 0)
    {
        push(&head, testData % 10);
        testData /= 10;
    }

    printList(head);
    printf("difference: %d\n", abs(findMax(head) - findMin(head)));
    return 0;
}
