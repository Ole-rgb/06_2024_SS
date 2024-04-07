#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// a.)
// Liste mit Zahlen gegeben, die ersten n Elemente in neuer Liste speichern und zurückgeben,
// falls n > Listengröße komplette Liste zurückgeben, falls n = 0 nichts zurückgeben
// - Eingabe: Liste (1,2,3), n = 2
// - Rückgabe (1,2)

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *newNode(int data)
{
    Node *temp = malloc(sizeof(Node));
    temp->data = data;
    temp->next = malloc(sizeof(Node));
    return temp;
}

void push(Node **head, int data)
{
    Node *temp = newNode(data);
    temp->next = *head;
    *head = temp;
}

void append(Node **head, int data)
{
    // printf("%d, ", head->data);
    // todo
    Node *temp = newNode(data);
    (*head)->next = temp;

    // *head = temp;
}

void printList(Node *head)
{
    if (head == NULL)
    {
        printf("nothing to print\n");
        return;
    }
    else
    {
        while (head != NULL)
        {
            printf("%d, ", head->data);
            head = head->next;
        }
    }
    printf("\n");
}

int getListSize(Node *head)
{
    int result = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        result++;
        temp = temp->next;
    }
    return result;
}

Node *getFirstNElements(Node *head, int copyLimit)
{
    Node *result = NULL;
    Node *temp = head;
    if (copyLimit == 0)
    {
        return NULL;
    }
    else if (getListSize(temp) < copyLimit)
    {
        return temp;
    }
    else
    {
        int i = 0;
        while (temp != NULL)
        {
            if (i == copyLimit)
            {
                return result;
            }
            push(&result, temp->data);
            // append(&result, temp->data);
            temp = temp->next;
            i++;
        }
    }
}

int main()
{
    Node *head = NULL;
    int maxAmount = 20;
    int lowerLimit = 0;
    int upperLimit = 20;
    int copyLimit = 7;
    srand(time(0));
    for (int i = 0; i < maxAmount; i++)
    {
        push(&head, rand() % (upperLimit + 1 - lowerLimit) + lowerLimit);
    }
    printList(head);
    printList(getFirstNElements(head, copyLimit));
}

// b.)
// Warum Node Deklaration problematisch?
// typedef struct Node
// {
//  int value;
//  struct Node next;
// } Node;
// todo, eigentlich weil der Pointer fehlt, aber was die genau technisch gesehen der Fehler war dunno.