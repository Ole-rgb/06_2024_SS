//  Zwei listen Mergen

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

void swap(IntList *a, IntList *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void bubbleSort(IntList *start)
{
    int swapped, i;
    IntList *temp;
    IntList *lptr = NULL;

    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        temp = start;

        while (temp->next != lptr)
        {
            if (temp->data > temp->next->data)
            {
                swap(temp, temp->next);
                swapped = 1;
            }
            temp = temp->next;
        }
        lptr = temp;
    } while (swapped);
}

IntList *merge(IntList *firstList, IntList *secondList)
{
    if (!firstList)
        return secondList;
    if (!secondList)
        return firstList;

    if (firstList->data < secondList->data)
    {
        firstList->next = merge(firstList->next, secondList);
        bubbleSort(firstList);
        return firstList;
    }
    else
    {
        secondList->next = merge(firstList, secondList->next);
        bubbleSort(secondList);
        return secondList;
    }
}

int main()
{
    IntList *firstList = NULL;
    IntList *secondList = NULL;
    int upperLimit = 20;
    int maxAmount = 10;

    srand(time(NULL));

    for (int i = 0; i < maxAmount; i++)
    {
        push(&firstList, rand() % upperLimit);
        push(&secondList, rand() % upperLimit);
    }

    printList(firstList);
    printf("\n");
    printList(secondList);
    printf("\n");
    printList(merge(firstList, secondList));
}
