// Baum in zwei Listen sortieren per Pointer. Alles kleiner als Grenze=Klein. Rest=Groß

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

void printList(LNode *head)
{
    if (head == NULL)
    {
        printf("nothing to print, since list is empty\n");
        return;
    }
    else
    {
        LNode *current = head;
        int i = 1;
        while (current != NULL)
        {
            printf("%d, ", current->data);
            current = current->next;
            i++;
        }
        printf("\n");
    }
}

void push(LNode **head, int data)
{
    LNode *new = newListNode(data);
    new->next = (*head);
    (*head) = new;
}

void sortTree(TNode *root, int threshold, LNode **lesserEqualThanThres, LNode **greaterThanTres)
{

    if (root != NULL)
    {
        sortTree(root->left, threshold, lesserEqualThanThres, greaterThanTres);
        if (root->data <= threshold)
        {
            push(lesserEqualThanThres, root->data);
        }
        else
        {
            push(greaterThanTres, root->data);
        }
        sortTree(root->right, threshold, lesserEqualThanThres, greaterThanTres);
    }
}

int main()
{
    int maxEntities = 20;
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
        printf("%d|", randomLeafContent);
    }
    printf("\n");

    TNode *root = newNode(0);
    root = createRandomTree(treeEntries, root, 0, maxEntities);

    sortTree(root, thresholdForSort, &lesserEqualThanThres, &greaterThanTres);

    printf("lesserEqualThanThresholdList: ");
    printList(lesserEqualThanThres);

    printf("greaterThanThresholdList: ");
    printList(greaterThanTres);
    return 0;
}