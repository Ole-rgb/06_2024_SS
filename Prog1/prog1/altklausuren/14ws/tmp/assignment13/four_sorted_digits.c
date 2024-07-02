/*
Compile: make four_sorted_digits
Run: ./four_sorted_digits
Compile and run:
make four_sorted_digits && ./four_sorted_digits
*/

#include "base.h"
#include "string.h"

// Gibt true zurück, wenn s mindestens 4 hintereinander stehende und aufsteigend 
// sortierte Dezimalziffern enthält. Sonst gibt die Funktion 0 zurück.
bool four_sorted_digits(String s) {
    return false; // todo: implement
}

void four_sorted_digits_test(void) {
    check_expect_b(four_sorted_digits(""), false);
    check_expect_b(four_sorted_digits("123"), false);
    check_expect_b(four_sorted_digits("abcd"), false);
    check_expect_b(four_sorted_digits("1234"), true);
    check_expect_b(four_sorted_digits("2479"), true);
    check_expect_b(four_sorted_digits("1111"), true);
    check_expect_b(four_sorted_digits("a123"), false);
    check_expect_b(four_sorted_digits("123a"), false);
    check_expect_b(four_sorted_digits("1234a"), true);
    check_expect_b(four_sorted_digits("xx1234y"), true);
    check_expect_b(four_sorted_digits("abc12345"), true);
    check_expect_b(four_sorted_digits("a 1 2 3 4 c"), false);
    check_expect_b(four_sorted_digits("a 3333 c"), true);
}

int main(void) {
    base_init();
    base_set_memory_check(true);
    four_sorted_digits_test();
    return 0;
}
