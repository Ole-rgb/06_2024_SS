// a.)##############################
// Implementieren Sie die Funktion pos neg list. Der Parameter list ist eine Eingabeliste ganzer Zahlen.
// Die Parameter pos und neg sind initial leere Ausgabelisten fur  die positiven bzw. negativen Zahlen aus der Eingabeliste.
// Die Eingabeliste wird also quasi zwei Listen aufgeteilt. Nullen werden ignoriert.
// Die Reihenfolge in den Ausgabelisten muss die gleiche wie in der Eingabeliste sein. Die Eingabeliste darf nicht verandert werden.
// Die Losung darf nur die Funktion new ¨ node und reverse verwenden.

#include "base.h"
typedef struct Node
{
    int value;
    struct Node *next;
} Node;
Node *new_node(int value, Node *next)
{
    Node *node = xcalloc(1, sizeof(Node));
    node->value = value;
    node->next = next;
    return node;
}
Node *reverse_rec(Node *list, Node *result)
{
    if (list == NULL)
    {
        return result;
    }
    else
    {
        return reverse_rec(list->next, new_node(list->value, result));
    }
}
Node *reverse(Node *list)
{
    return reverse_rec(list, NULL);
}
void pos_neg_list(Node *list, Node **pos, Node **neg)
{
    // Node *temp = *pos;
    while (list != NULL)
    {
        if (list->value < 0)
        {
            *neg = new_node(list->value, *neg);
            // printf("%d, ", **neg);
        }
        else if (list->value > 0)
        {
            *pos = new_node(list->value, *pos);
            // printf("%d, ", **pos);
        }
        list = list->next;
    }
}

void test(void)
{
    Node *list, *pos, *neg;
    list = new_node(0, new_node(1, new_node(-1, new_node(34, new_node(-56, NULL)))));
    pos = NULL;
    neg = NULL;
    pos_neg_list(list, &pos, &neg);
    // pos: [34, 1] (Reihenfolge beliebig)
    // neg: [-56, -1] (Reihenfolge beliebig)
    printf("pos: ");
    while (pos != NULL)
    {
        printf("%d, ", pos->value);
        pos = pos->next;
    }
    printf("\n");

    printf("neg: ");
    while (neg != NULL)
    {
        printf("%d, ", neg->value);
        neg = neg->next;
    }
    printf("\n");

    // char *a = NULL;
    // char b = *a;
    // printf("%c\n", b);

    pos = NULL;
    neg = NULL;
    pos_neg_list(list, &pos, &neg);
    // pos: []
    // neg: []
}
int main(void)
{
    test();
    return 0;
}

// b.) #########################
// 1 char* a = NULL; --> Nullpointer
// 2 char b = *a; --> char b = deref. NULL
// 3 printf("%c\n", b); --> nullptr soll gedruckt werden --> Abstürzt