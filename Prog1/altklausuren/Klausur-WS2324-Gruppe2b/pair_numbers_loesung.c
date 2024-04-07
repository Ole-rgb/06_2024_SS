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

int list_length(List* list) {
	if (list == NULL) return 0;
	int len = 1;
	while (list->next != NULL) {
		len++;
		list = list->next;
	}

	return len;
}

int count_pair(List* list) {
	if (list == NULL) return 0;
	return count_pair(list->next) + ((list->value % 2) == 0);
}

int calculate(List* list, int n) {
	// todo: implement
	int length = list_length(list);
	int total_pair_count = count_pair(list);
	int pair_counter = 0;
	int sum = 0;
	for (int i = 0; i < length; i++, list = list->next) {
		if ((list->value % 2) == 0) {
			pair_counter++;
			if ((total_pair_count - pair_counter + 1) > n) continue;
			sum += list->value;
		}
	}

	return sum;
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

	test_equal_i(calculate(make_list(5, make_list(6, make_list(7, make_list(8, make_list(9, NULL))))), 0), 0);
	test_equal_i(calculate(make_list(5, make_list(6, make_list(7, make_list(8, make_list(9, NULL))))), 1), 8);
	test_equal_i(calculate(make_list(5, make_list(6, make_list(7, make_list(8, make_list(9, NULL))))), 2), 14);
	test_equal_i(calculate(make_list(5, make_list(6, make_list(7, make_list(8, make_list(9, NULL))))), 3), 14);
}	

int main(void) {
	test();
	return 0;
}