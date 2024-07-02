// a.) ######################
// Tree reprasentiert einen Baum mit ganzzahligen Werten.
// Implementieren Sie die Funktion internal node sum.
// Diese soll die Summe der Werte aller inneren Knoten des Baums berechnen.
// Innere Knoten haben (ein oder mehr) Kinder

#include "base.h"
typedef struct Tree
{
    int value;
    struct Tree *left;
    struct Tree *right;
} Tree;
Tree *new_tree(Tree *left, int value, Tree *right)
{
    Tree *t = xcalloc(1, sizeof(Tree));
    t->left = left;
    t->value = value;
    t->right = right;
    return t;
}
Tree *leaf(int value)
{
    return new_tree(NULL, value, NULL);
}
Tree *node(Tree *left, int value, Tree *right)
{
    return new_tree(left, value, right);
}
// int result = 0;
int internal_node_sum(Tree *t)
{
    if (t == NULL)
        return 0;
    if (t->left == NULL && t->right == NULL)
        return 0;
    int l = internal_node_sum(t->left);
    int r = internal_node_sum(t->right);
    return t->value + l + r;

    // if (t != NULL)
    // {
    //     internal_node_sum(t->left);
    //     if (t->left != NULL || t->right != NULL)
    //     {
    //         result += t->value;
    //     }
    //     internal_node_sum(t->right);
    // }
    // return result;
}
void test(void)
{
    Tree *t = node(leaf(1), 2, leaf(3));
    int x = internal_node_sum(t); // 2
    printf("%d\n", x);

    // 100
    t = leaf(100);
    x = internal_node_sum(t); // 0
    printf("%d\n", x);

    // -101
    // 2 5
    // 1 3 4 NULL
    t = node(node(leaf(1), 2, leaf(3)), -101, node(leaf(4), 5, NULL));
    x = internal_node_sum(t); // -101 + 2 + 5 --> -94
    printf("%d\n", x);

    // 1
    // 2 3
    // 15 NULL
    // NULL 85
    t = node(node(node(NULL, 15, leaf(85)), 2, NULL), 1, leaf(3));
    x = internal_node_sum(t); // 1 + 2 + 15 --> 18
    printf("%d\n", x);
}
int main(void)
{
    test();
    return 0;
}
// b.) #################################
// Geben Sie ein Anwendungsbeispiel fur Funktionszeiger in C.
// Ermöglicht generische Suchfunktionen, welche nur die per Pointer übergebene Funktion aufrufen muss zum Sortieren.