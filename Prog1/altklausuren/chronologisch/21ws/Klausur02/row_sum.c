/*
make row_sum && ./row_sum
*/

#include "base.h"

// <purpose statement>
int* row_sum(int* a, int rows, int cols) {
    // implement
    return NULL;
}

void test(void) {
    int a[3][3] = {
        { 1, 2, 3 }, 
        { -1, -2, -3 }, 
        { 3, 4, 5 }, 
    };
    int* margin = row_sum((int*)a, 3, 3);
    int expected[] = { 6, -6, 12 };
    ia_test_equal(a_of_buffer(margin, 3, sizeof(int)), 
                  a_of_buffer(expected, 3, sizeof(int)));
}

int main(void) {
    test();
    return 0;
}