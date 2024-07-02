/*
Compile: make center_or_zero
Run: ./center_or_zero
Compile & run: make center_or_zero && ./center_or_zero
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct DoubleNode {
    double value;
    struct DoubleNode *next;
} DoubleNode;

typedef struct DoubleList {
    DoubleNode *first;
    DoubleNode *last;
} DoubleList;

DoubleList *new_list(void) {
    return calloc(1, sizeof(DoubleList));
}

DoubleNode *new_node(double value) {
    DoubleNode *node = calloc(1, sizeof(DoubleNode));
    node->value = value;
    return node;
}

void print(DoubleList *list) {
    printf("[");
    for (DoubleNode *node = list->first; node != NULL; node = node->next) {
        printf("%f ", node->value);
    }
    printf("]\n");
}

void append(DoubleList *list, double value) {
    DoubleNode *p = new_node(value);
    if (list->last != NULL) list->last->next = p;
    list->last = p;
    if (list->first == NULL) list->first = p;
}

void free_list(DoubleList *list) {
    DoubleNode *next = NULL;
    for (DoubleNode *node = list->first; node != NULL; node = next) {
        next = node->next;
        free(node);
    }
    list->first = NULL;
    list->last = NULL;
    free(list);
}

DoubleList *list_of_string(char *s) {
    DoubleList *list = new_list();
    char *t = s;
    char *endp;
    while (*t != '\0') {
        if (isdigit(*t)) {
            if (t > s && *(t - 1) == '.') t--; // check for '.'
            if (t > s && *(t - 1) == '-') t--; // check for '-'
            append(list, strtod(t, &endp)); // convert digit string to int
            t = endp;
        } else {
            // assert: *t is not a digit, *t is not '\0'
            t++; // not a digit, skip
        }
    }
    return list;
}

/* Diese Funktion gibt die Zahl in der Mitte der Liste zurueck. Wenn die Liste eine 
 * gerade Anzahl an Elementen enthaelt, gibt die Funktion 0 zurueck. */
double center_or_zero(DoubleList *list) {
    return 0; // todo: implement
}

int center_or_zero_test(void) {
    DoubleList *list = list_of_string("");
    double x = center_or_zero(list);
    free_list(list);
    if (x != 0) return 1;
    
    list = list_of_string("11");
    x = center_or_zero(list);
    free_list(list);
    if (x != 11) return 2;
    
    list = list_of_string("-11");
    x = center_or_zero(list);
    free_list(list);
    if (x != -11) return 3;
    
    list = list_of_string("1, -2");
    x = center_or_zero(list);
    free_list(list);
    if (x != 0) return 4;
    
    list = list_of_string("-1, 2, -3, 4");
    x = center_or_zero(list);
    free_list(list);
    if (x != 0) return 5;
    
    list = list_of_string("-1, 2, -3, 4, 5");
    x = center_or_zero(list);
    free_list(list);
    if (x != -3) return 6;
    
    list = list_of_string("-1, 1, 2, -1, -1, -1, 2");
    x = center_or_zero(list);
    free_list(list);
    if (x != -1) return 7;
    
    return 0;
}

int main(void) {
    int i = center_or_zero_test();
    if (i == 0) {
        printf("tests passed\n"); 
    } else {
        printf("test %d failed\n", i);
    }
    return 0;
}
