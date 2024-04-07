# progI

### Strukturen

* wichtige string.h Funktionen 
  * ![](https://i.imgur.com/FPvpyRS.png)

### Algorithmen

#### list

* Trick17 
  * ![](https://i.imgur.com/9UUIXr3.png)
* append 
  * ![](https://i.imgur.com/bZGMGVy.png)
* pushPop 
  * ![](https://i.imgur.com/QrL8TLK.png)
* mergeLists 
  * ![](https://i.imgur.com/waM6ynk.png)
* intToTree 
  * ![](https://i.imgur.com/78D6Pv3.png)
* minMax 
  * ![](https://i.imgur.com/Uf13119.png)

```
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct IntList
{
    int data;
    int price;
    struct IntList *next;
} IntList;

IntList *newNode(int data, int price)
{
    IntList *node = malloc(sizeof(IntList));
    node->data = data;
    node->price = price;
    node->next = malloc(sizeof(IntList));
    return node;
}

void push(IntList **head, int data, int price)
{
    IntList *new = newNode(data, price);
    new->next = (*head);
    (*head) = new;
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
        printf("%d.weight %d, price: %d\n", i, current->data, current->price);
        current = current->next;
        i++;
    }
}

int sumListPrice(IntList *head)
{
    int listSum = 0;
    IntList *copy = head;
    while (copy != NULL)
    {
        listSum += copy->price;
        copy = copy->next;
    }
    return listSum;
}

int minMaxWeight(IntList *head)
{
    int threshold = 0;
    int elementAmount = 0;
    IntList *copy = head;
    while (threshold < ((sumListPrice(head) / 2) + 1) && copy != NULL)
    {
        threshold += copy->price;
        elementAmount = elementAmount + 1;
    }
    printf("elementCount = %d: ", elementAmount);
    return threshold;
}

/* function to swap data of two nodes a and b*/
void swap(IntList *a, IntList *b)
{
    int temp = a->price;
    a->price = b->price;
    b->price = temp;
}

/* Bubble sort the given linked list */
void bubbleSort(IntList *start)
{
    int swapped, i;
    IntList *ptr1;
    IntList *lptr = NULL;

    /* Checking for empty list */
    if (start == NULL)
        return;

    do
    {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != lptr)
        {
            if (ptr1->price < ptr1->next->price)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
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
int main()
{
    IntList *head = NULL;
    int maxAmount = 10;
    int upperWeightLimit = 50;
    int upperPriceLimit = 200;
    srand(time(NULL));
    for (int i = 0; i < maxAmount; i++)
    {
        push(&head, rand() % upperWeightLimit, rand() % upperPriceLimit);
    }
    printList(head);
    // printf("\n");
    printf("list sum: %d€\n", sumListPrice(head));
    bubbleSort(head);
    printList(head);
    printf("sum: %d\n", minMaxWeight(head));
}
```

#### Tree

* trick17 
  * ![](https://i.imgur.com/yY59JFj.png)
* Baumhöhe 
  * ![](https://i.imgur.com/McyYOwg.png)
* treeToList 
  * ![](https://i.imgur.com/Q5087Jo.png)
* Summe von Blätter ohne Nachfolger 
  * solange root existiert 
    * sum =+ links
    * falls rechts und left == NULL 
      * sum += root->data
    * root = root->right
* Zufälligen Baum erzeugen 
  * solange index < arrayLänge 
    * temp = newNode(randArray[index])
    * root = temp
    * rekursive Aufrufe 
      * links = random(randArray, root->left, 2 \* index + 1, arrayLength)
      * rechts = random(randArray, root->left, 2 \* index + 2, arrayLength)
  * return root
* baumartig drucken von links aus 
  * count = 10
  * falls liste leer (root == Null) 
    * return
  * spaceBetween += count
  * printAsTree(recht, spaceBetween)
  * \\n
  * solange count < space 
    * Leerzeichen drucken
  * data drucken
  * printAsTree(links, spaceBetween)
* orderDruck 
  * inOrder 
    * solange root != 0 
      * inOrder(links)
      * data drucken
      * inOrder(rechts)
  * preOrder 
    * ![](https://i.imgur.com/mmYjb8q.png)
  * postOrder 
    * ![](https://i.imgur.com/4XdiF4u.png)
* newNode 
  * TNode 
    * ![](https://i.imgur.com/PUgpx7S.png)
    * StringNode \*head = newNode("first")
  * Node 
    * ![](https://i.imgur.com/bvjy0cC.png)
    * TNode \*head = newNode("first")
* mittlerer Index 
  * ![](https://i.imgur.com/3o3RGvl.png)
* alternierende Vorzeichen 
  * ![](https://i.imgur.com/pKsfYrw.png)

#### Strings

* malloc 
  * ![](https://i.imgur.com/Wm6E1x7.png)
  * An '\\0' denken
* rot3 encode 
  * ![](https://i.imgur.com/DtBTtxb.png)
* char in String1 aber nicht String2 
  * ![](https://i.imgur.com/fkTBeUk.png)
* strStr mit Wildcard 
  * ![](https://i.imgur.com/aAyIf27.png)
* Wiederholung char in string 
  * ![](https://i.imgur.com/wzyZs4y.png)
* bei upperCase camelcase mit \_ 
  * ![](https://i.imgur.com/Hp2MRyO.png)
* String in Suchtext suchen 
  * erstell result
  * for über Suchtext 
    * wenn irgendeine Stelle des Suchtextes der ersten Stelle des Strings entspricht 
      * erstell counter
      * solange - counter < Stringlänge - i + counter < Suchtextlänge - Suchtext[i + counter] == String[counter]
      * erhöhe counter
      * wenn counter >= Stringlänge 
        * erhöhe resultCounter
  * return result
* String in einer Liste reversen 
  1. entsprechende Datenstruktur für Liste erstellen 
     * ![](https://i.imgur.com/gLfX9Tx.png)
  2. reversen 
     * loop über alle Listenelemente
     * loop über data 
       * von Stringende runterzählen und die jeweiligen chars anzeigen lassen
       * oder resultString += currentChar
     * ![](https://i.imgur.com/gkqtYSg.png)
* char aus String entfernen 
  * loop über string 
    * wenn stringChar = gesuchtes char 
      * string[j] = string[j++]
* 2 Strings gegeben. Alle chars die in String 1 vorkommen, aber nicht in String 2 in einen neuen allokierten String übergeben 
  * hello; 2.ello --> h
* aufsteigende Zahlen in String 
  * ![](https://i.imgur.com/1YVwKOw.png)

### Arrays

* 2d 
  * ![](https://i.imgur.com/iLe5k5N.png)

### Sotierung

* bubbleSort 
  * ![](https://i.imgur.com/BOwBISG.png)

### stuff

* calloc: Speicher reservieren
* malloc: Allokieren
* realloc: neuallokieren