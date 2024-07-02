// Stack Funktionen implementieren mit Liste:
// empty
// size
// push
// pop

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct IntList
{
    int data;
    int price;
    struct IntList *next;
} IntList;

IntList *newNode(int data, int price)
{
    IntList *node = malloc(sizeof(IntList));
    node->data = data;
    node->price = price;
    node->next = malloc(sizeof(IntList));
    return node;
}

void push(IntList **head, int data, int price)
{
    IntList *new = newNode(data, price);
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
        printf("%d.weight %d, price: %d\n", i, current->data, current->price);
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

int empty(IntList *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

int size(IntList *head)
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        return getListSize(head);
    }
}
int main()
{
    IntList *head = NULL;
    int maxAmount = 10;
    int upperWeightLimit = 50;
    int upperPriceLimit = 200;
    srand(time(NULL));
    for (int i = 0; i < maxAmount; i++)
    {
        push(&head, rand() % upperWeightLimit, rand() % upperPriceLimit);
    }
    printList(head);
    pop(&head);
    printf("\n%d \n", empty(head));
    printf("\n");
    printList(head);
}
