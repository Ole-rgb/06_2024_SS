# include "base.h"
#include <limits.h>

typedef struct IntList {
     int value;
     struct IntList* next;
}IntList;

//ergänze Konstrukurfunktion und so (was in der KLausur alles gegeben)
IntList* createNode(int value, IntList* next){
    IntList* node = xmalloc(sizeof(IntList));
    node->value = value;
    node->next = next;
    return node;
}

//Aufgabe war eine Funktion zu schreiben, die die Differenz zwischen dem Maximum und dem Minium einer Liste berechnet.
int diff_max_min(IntList* list) {
    int min = INT_MAX;
    int max = INT_MIN;
    IntList* current = list;

    while(current != NULL){
        if(current->value < min){
            min = current->value;
        }
        if(current->value > max){
            max = current->value;
        }
        current = current->next;
    }
    return max-min;
}
void freeIntList(IntList* list){
    IntList* current = list;
    while (current != NULL)
    {
        IntList* tmp = current;
        current = current->next;
        free(tmp);
    }
    
}

void test_diff_max_min(void) {
    // denk dir Testfälle aus (war in der Klausur gegeben)
    IntList l1 = {0,NULL};
    test_equal_i(diff_max_min(&l1),0);
    
    IntList l2 = {-3,&l1};
    test_equal_i(diff_max_min(&l2),3);
    
    IntList l3 = {2,&l2};
    test_equal_i(diff_max_min(&l3),5);

    IntList* l4 = createNode(3, createNode(5, NULL));
    test_equal_i(diff_max_min(l4),2);
    freeIntList(l4);
}

int main(void) {
    test_diff_max_min();
    report_memory_leaks(true);
    return 0;
}
