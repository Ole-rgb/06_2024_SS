// Berechnen der Summe von inneren Tree Nodes

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

int treeSum(TNode *root)
{
    int sum = 0;
    while (root)
    {
        sum += treeSum(root->left);
        if (root->right == NULL && root->left == NULL)
        {
            printf("%d\n", root->data);
            return sum += root->data;
        }
        root = root->right;
    }
    return 0;
}

int main()
{
    int maxEntities = 12;
    int max = 10;
    int min = 0;
    int treeEntries[maxEntities];
    srand(time(0));

    for (int i = 0; i < maxEntities; i++)
    {
        int randomLeafContent = rand() % (max + 1 - min) + min;
        treeEntries[i] = randomLeafContent;
        printf("%d|", randomLeafContent);
    }
    printf("\n");

    TNode *root = newNode(0);
    root = createRandomTree(treeEntries, root, 0, maxEntities);
    printAsTree(root, 0);
    printf("sum of leafless nodes: %d\n", treeSum(root));
    return 0;
}