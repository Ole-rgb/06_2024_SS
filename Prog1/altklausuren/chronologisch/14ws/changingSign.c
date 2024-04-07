// Schreiben Sie eine Methode, die zurückgibt, wie häufig es Child - und Parent - Nodes gibt,
// bei denen sich das Vorzeichen unterscheidet.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode *newNode(int data)
{
    TreeNode *temp = malloc(sizeof(TreeNode));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void inOrderPrint(TreeNode *node)
{
    if (node != NULL)
    {
        inOrderPrint(node->left);
        printf("%d ", node->data);
        inOrderPrint(node->right);
    }
}

void printAsTree(TreeNode *root, int space)
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

TreeNode *createRandomTree(int treeEntries[], TreeNode *node, int index, int arrayLength)
{
    TreeNode *temp = NULL;
    if (index < arrayLength)
    {
        temp = newNode(treeEntries[index]);
        node = temp;
        node->left = createRandomTree(treeEntries, node->left, 2 * index + 1, arrayLength);
        node->right = createRandomTree(treeEntries, node->right, 2 * index + 2, arrayLength);
    }
    return temp;
}
int result = 0;
int alternatingSigns(TreeNode *node)
{
    if (node != NULL && node->left != NULL && node->right != NULL)
    {
        alternatingSigns(node->left);
        if (node->data < node->left->data || node->data < node->right->data)
        {
            result++;
        }
        alternatingSigns(node->right);
    }
    return result;
}
int main()
{
    int upperLimit = 10;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));
    srand(time(NULL));
    int decider = 0;
    for (int i = 0; i < upperLimit; i++)
    {
        if (decider % 2 == 0)
        {
            int randomEntry = rand() % 30;
            entries[i] = randomEntry;
        }
        else
        {
            int randomEntry = 0 - (rand() % 30);
            entries[i] = randomEntry;
        }
        decider++;
    }
    TreeNode *root = newNode(0);

    root = createRandomTree(entries, root, 0, upperLimit);
    printAsTree(root, 10);
    printf("%d\n", alternatingSigns(root));
}
