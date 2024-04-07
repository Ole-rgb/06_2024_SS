// Berechnen  die Summe der letzten 'n' gerade Zahlen der LinkedList.

// make pair_numbers && ./pair_numbers

#include "base.h"

typedef struct List {
	int value;
	struct List* next;
} List;

List* make_list(int value, List* next) {
	List *list = (List *) xmalloc(sizeof(List));
	list->value = value;
	list->next = next;
	return list;
}

int calculate(List* list, int n) {
	// todo: implement
	return 0;
}

void test(void) {
	test_equal_i(calculate(make_list(5, NULL), 0), 0);
	test_equal_i(calculate(make_list(5, NULL), 1), 0);
	test_equal_i(calculate(make_list(5, NULL), 2), 0);
	test_equal_i(calculate(make_list(5, NULL), 3), 0);

	test_equal_i(calculate(make_list(6, NULL), 0), 0);
	test_equal_i(calculate(make_list(6, NULL), 1), 6);
	test_equal_i(calculate(make_list(6, NULL), 2), 6);
	test_equal_i(calculate(make_list(6, NULL), 3), 6);

	test_equal_i(calculate(make_list(5, make_list(6, make_list(7, make_list(8, NULL)))), 0), 0);
	test_equal_i(calculate(make_list(5, make_list(6, make_list(7, make_list(8, NULL)))), 1), 8);
	test_equal_i(calculate(make_list(5, make_list(6, make_list(7, make_list(8, NULL)))), 2), 14);
	test_equal_i(calculate(make_list(5, make_list(6, make_list(7, make_list(8, NULL)))), 3), 14);
}	

int main(void) {
	test();
	return 0;
}