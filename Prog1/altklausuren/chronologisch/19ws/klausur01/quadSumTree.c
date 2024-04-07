//    a.) Linkes Kinder mit Rechtem tauschen und den Value quadrieren und in einen neuen Baum speichern <br>
//    b.) Summe eines Baumes iterativ berechnen, groben Algorithmus aufschreiben

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TNode
{
    int data;
    struct TNode *left;
    struct TNode *right;
} TNode;

TNode *newNode(int data)
{
    TNode *node = malloc(sizeof(TNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode;

LNode *newListNode(int data)
{
    LNode *node = malloc(sizeof(LNode));
    node->data = data;
    node->next = NULL;
    return node;
}

void printAsTree(TNode *root, int space)
{
    int count = 10;

    if (root == NULL)
    {
        return;
    }

    space += count;
    printAsTree(root->right, space);

    printf("\n");

    for (int i = count; i < space; i++)
    {
        printf(" ");
    }
    printf("%d\n", root->data);
    printAsTree(root->left, space);
}

TNode *createRandomTree(int treeEntries[], TNode *root, int index, int arrayLength)
{
    if (index < arrayLength)
    {
        TNode *temp = newNode(treeEntries[index]);
        root = temp;
        root->left = createRandomTree(treeEntries, root->left, 2 * index + 1, arrayLength);
        root->right = createRandomTree(treeEntries, root->right, 2 * index + 2, arrayLength);
    }
    return root;
}

void inOrderPrint(TNode *root)
{
    if (root != NULL)
    {
        inOrderPrint(root->left);
        printf("%d ", root->data);
        inOrderPrint(root->right);
    }
}

void push(LNode **head, int data)
{
    LNode *new = newListNode(data);
    new->next = (*head);
    (*head) = new;
}

//a.) Linkes Kind mit Rechtem tauschen und den Value quadrieren und in einen neuen Baum speichern
TNode *quadSumTree(TNode *root)
{
    if (root == NULL)
    {
        return NULL;
    }
    TNode *result = newNode(root->data * root->data);
    result->left = quadSumTree(root->right);
    result->right = quadSumTree(root->left);
    return result;
}

// b.) Summe eines Baumes iterativ berechnen, groben Algorithmus aufschreiben
int iterativeTreeSum(TNode *root)
{
    TNode *current;
    TNode *previous;
    int result = 0;
    if (root == NULL)
    {
        return 0;
    }
    current = root;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            result++;
            current = current->right;
        }
        else
        {
            previous = current->left;
            while (previous->right != NULL && previous->right != current)
            {
                previous = previous->right;
            }
            if (previous->right == NULL)
            {
                previous->right = current;
                current = current->left;
            }
            else
            {
                previous->right = NULL;
                result++;
                current = current->right;
            }
        }
    }
    return result;
}

int main()
{
    int maxEntities = 5;
    int max = 10;
    int min = 0;
    int treeEntries[maxEntities];
    srand(time(0));

    LNode *lesserEqualThanThres = NULL;
    LNode *greaterThanTres = NULL;
    LNode *temp = lesserEqualThanThres;

    int thresholdForSort = 5;

    printf("tree: ");
    for (int i = 0; i < maxEntities; i++)
    {
        int randomLeafContent = rand() % (max + 1 - min) + min;
        treeEntries[i] = randomLeafContent;
        // printf("%d|", randomLeafContent);
    }
    printf("\n");

    TNode *root = newNode(0);
    root = createRandomTree(treeEntries, root, 0, maxEntities);
    inOrderPrint(root);
    printf("\n");
    inOrderPrint(quadSumTree(root));
    printf("\n");
    printf("%d\n", iterativeTreeSum(root));

    return 0;
}