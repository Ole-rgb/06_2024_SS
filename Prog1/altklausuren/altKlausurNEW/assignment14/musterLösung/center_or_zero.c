/*
Compile: make center_or_zero
Run: ./center_or_zero
Compile & run: make center_or_zero && ./center_or_zero
*/

#include "base.h"

typedef struct DoubleNode {
	double value;
	struct DoubleNode *next;
} DoubleNode;

typedef struct DoubleList {
	DoubleNode *first;
	DoubleNode *last;
} DoubleList;

DoubleList *new_list(void) {
	return xcalloc(1, sizeof(DoubleList));
}

DoubleNode *new_node(double value) {
	DoubleNode *node = xcalloc(1, sizeof(DoubleNode));
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
	// length possibly as a separate function
	int len = 0;
	for (DoubleNode *node = list->first; node != NULL; node = node->next) {
		len++;
	}
	if ((len & 1) == 0) { // even number of elements, no center, return 0
		return 0;
	}

	int mid = len / 2;
	int i = 0;
	for (DoubleNode *node = list->first; node != NULL; node = node->next) {
		if (i == mid) {
			return node->value;
		}
		i++;		
	}
	return 0;
}

void center_or_zero_test(void) {
    DoubleList *list = list_of_string("");
    test_equal_i(center_or_zero(list), 0);
	free_list(list);
    
    list = list_of_string("11");
    test_equal_i(center_or_zero(list), 11);
    free_list(list);
    
    list = list_of_string("-11");
    test_equal_i(center_or_zero(list), -11);
    free_list(list);
    
    list = list_of_string("1, -2");
    test_equal_i(center_or_zero(list), 0);
    free_list(list);
    
    list = list_of_string("-1, 2, -3, 4");
    test_equal_i(center_or_zero(list), 0);
    free_list(list);
    
    list = list_of_string("-1, 2, -3, 4, 5");
    test_equal_i(center_or_zero(list), -3);
    free_list(list);
    
    list = list_of_string("-1, 1, 2, -1, -1, -1, 2");
    test_equal_i(center_or_zero(list), -1);
    free_list(list);
    
}

int main(void) {
	base_init();
    base_set_memory_check(true);
	center_or_zero_test();

	return 0;
}
