// Strings in einer Liste reversen

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct StringNode
{
    char *data;
    struct StringNode *next;
} StringNode;

StringNode *newNode(char *value)
{
    StringNode *node = malloc(sizeof(StringNode));
    node->data = value;
    return node;
}

void printList(StringNode *n)
{
    for (StringNode *node = n; node != NULL; node = node->next)
    {
        printf("%s\n", node->data);
    }
}

void reverseAllString(StringNode *n)
{
    for (StringNode *node = n; node != NULL; node = node->next)
    {
        int stringLength = strlen(node->data);
        char *string = node->data;
        for (int i = stringLength; i >= 0; i--)
        {
            printf("%c", string[i]);
        }
        printf("\n");
    }
}

int main()
{
    StringNode *head = newNode("first");
    StringNode *second = newNode("second");
    StringNode *third = newNode("third");

    head->next = second;
    second->next = third;
    third->next = NULL;

    printList(head);
    printf("\n");
    reverseAllString(head);

    return 0;
}
