// Schreiben Sie eine Funktion, die das mittlere Element einer verketteten Listen zurückgibt.
// Wenn die Liste eine gerade Anzahl an Elementen hat soll eine Null zurückgegeben werden.
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

int middleIndex(IntList *node)
{
    IntList *copy = node;
    int result = 10;
    int listSize = getListSize(copy);

    if (listSize % 2 == 0)
    {
        result = 0;
    }
    else
    {
        int index = 0;
        while (index != listSize / 2)
        {
            copy = copy->next;
            index++;
        }
        result = copy->data;
    }
    return result;
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
    printf("%d\n", middleIndex(head));
}