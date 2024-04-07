// Aufgabe: implementieren Sie eine Funktion
// "IntList* intersperse(IntList *list, int x)", die zwischen die Listenelemente
// den übergebenen Wert x einfügt. Die Funktion soll dabei die Ursprungsliste nicht
// verändern, sondern einen Zeiger auf die veränderte Kopie zurückgeben. Diese muss
// dynamisch allokiert werden - dies konnte man mit einer node()-Funktion bspw.
// erledigen, die bereits in der .c-Datei vorhanden war.

// Beispiele (Testfälle waren wieder vorgegeben):

// intersperse([1, 2, 3], -3) = [1, -3, 2, -3, 3]
// intersperse([1, 2], -3) = [1, -3, 2]

// Wichtigster Testfall war noch:
// intersperse([ ], -3) = [ ]

// Je nach Implementation konnte vorkommen, dass ihr im letzten Testfall statt "[ ]"
// "[0]" erhaltet. Lösung: man musste für den Fall, dass die übergebene IntList
// NULL ist, NULL zurückgeben.

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

void append(IntList **head, int data)
{
    // IntList *copy = head;
    // IntList *temp = copy;
    while ((*head)->next != NULL)
    {
        printf("\nree: %d, ", (*head)->data);
        (*head) = (*head)->next;
    }
    printf("\n");
    IntList *new = newNode(data);
    (*head)->next = new;
    // return temp;
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
        printf("%d.element %d\n", i, current->data);
        current = current->next;
        i++;
    }
}

IntList *randomInsert(IntList *list, int x)
{
    if (list == NULL)
    {
        printf("list empty\n");
        return NULL;
    }
    IntList *copy = list;
    int listSize = 0;
    while (copy != NULL)
    {
        listSize++;
        copy = copy->next;
    }
    copy = list;
    IntList *returnCopy = copy;
    // printf("%d\n", listSize);
    int randomIndex = rand() % (listSize - 1);
    for (int i = 0; i < listSize; i++)
    {
        if (i == randomIndex)
        {
            printf("replacedIndex: %d\n", randomIndex + 1);
            copy->data = x;
        }
        // printf("%d.element %d\n", i, copy->data);
        copy = copy->next;
    }
    return returnCopy;
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

IntList *intersperse(IntList *list, int x)
{
    if (list == NULL)
    {
        printf("list empty\n");
        return NULL;
    }
    int listSize = getListSize(list);
    printf("\ninterNumber = %d\n", x);

    IntList *copy = list;
    IntList *temp = copy;

    // for (int i = 0; i < listSize; i++)
    int i = 0;
    while (list != NULL)
    {
        printf("step %d\n", i);
        if (i % 2 == 0)
        {
            push(&copy, list->data);
        }
        if (i % 2 == 1)
        {
            push(&copy, x);
        }
        i++;
        list = list->next;
    }
    printf("\n");
    return copy;
}

int main()
{
    IntList *head = NULL;
    int maxAmount = 3;
    srand(time(NULL));
    for (int i = 0; i < maxAmount; i++)
    {
        push(&head, rand() % maxAmount);
    }
    printList(head);
    // printList(randomInsert(head, 9));
    printList(intersperse(head, 9));
}