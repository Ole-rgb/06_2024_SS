// Finde den kürzesten Weg durch den Baum, d.h. die minimale Summe.

// make min_pfad && ./min_pfad

#include "base.h"

typedef struct Tree {
	int value;
	struct Tree* left;
	struct Tree* right;
} Tree;

Tree* node(Tree* left, int value, Tree* right) {
	Tree* tree = (Tree*) xmalloc(sizeof(Tree));
	tree->value = value;
	tree->left = left;
	tree->right = right;
	return tree;
}

Tree* leaf(int value) {
	return node(NULL, value, NULL);
}

int min_pfad(Tree* tree) {
	require_not_null(tree);
	//todo: implement
	if (tree->left == NULL && tree->right == NULL) return tree->value;
	int sum_leaf;
	if (tree->left == NULL) {
		sum_leaf = min_pfad((tree->right));
	} else if (tree->right == NULL) {
		sum_leaf = min_pfad((tree->left));
	} else {
		sum_leaf = min_pfad((tree->left)) < min_pfad((tree->right)) ? min_pfad((tree->left)) : min_pfad((tree->right));
	}
	return tree->value + sum_leaf;
}

void test(void) {
	test_equal_i(min_pfad(leaf(5)), 5);

	test_equal_i(min_pfad(node(leaf(1), 5, leaf(2))), 6);
	test_equal_i(min_pfad(node(leaf(-1), 5, leaf(2))), 4);

	test_equal_i(min_pfad(node(node(leaf(-1), 2, leaf(0)), 5, node(leaf(3), 1, leaf(-2)))), 4);
}

int main(void) {
	test();
	return 0;
}