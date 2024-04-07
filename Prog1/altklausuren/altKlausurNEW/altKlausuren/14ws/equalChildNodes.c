// Schreiben Sie eine Methode, die überprüft, ob ein Child-Node in einem Binärbaum den gleichen Wert hat wie sein Parent-Node.
// Sie dürfen dazu eine Hilfsmethode schreiben.(Restliche Funktionalität des Binärbaums und Tests gegeben)

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
// Schreiben Sie eine Methode, die überprüft, ob ein Child-Node in einem Binärbaum den gleichen Wert hat wie sein Parent-Node.
void checkChildEqualsParent(TreeNode *node)
{
    if (node != NULL && node->left != NULL && node->right != NULL)
    {
        checkChildEqualsParent(node->left);
        if (node->data == node->left->data || node->right->data == node->data)
        {
            printf("Parent: %d, leftChild: %d, rightChild: %d\n", node->data, node->left->data, node->right->data);
        }
        else
        {
            printf("nothing found\n");
        }
        checkChildEqualsParent(node->right);
    }
}
int main()
{
    int upperLimit = 10;
    int entries[upperLimit];
    int *results = malloc(sizeof(int));

    TreeNode *monoRight = newNode(0);
    TreeNode *temp = monoRight;
    srand(time(NULL));
    for (int i = 0; i < upperLimit; i++)
    {
        int randomEntry = rand() % 30;
        entries[i] = randomEntry;
        monoRight->right = newNode(entries[i]);
        monoRight = monoRight->right;
    }
    monoRight->left = newNode(100);
    monoRight = temp;
    TreeNode *root = newNode(0);

    root = createRandomTree(entries, root, 0, upperLimit);
    printAsTree(root, 10);
    checkChildEqualsParent(root);
}
