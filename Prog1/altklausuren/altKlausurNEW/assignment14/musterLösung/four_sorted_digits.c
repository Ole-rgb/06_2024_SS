/*
Compile: make four_sorted_digits
Run: ./four_sorted_digits
Compile and run:
make four_sorted_digits && ./four_sorted_digits
*/

#include "base.h"

// Gibt true zurück, wenn s mindestens 4 hintereinander stehende und aufsteigend
// sortierte Dezimalziffern enthält. Sonst gibt die Funktion false zurück.
bool four_sorted_digits(String inputString)
{
    if (inputString == NULL)
        return false; // not required
    int validIndex = s_length(inputString) - 3;
    int sum;
    for (int i = 0; i < validIndex; i++)
    {
        //              ;             && chars zwischen 0 - 9                               && charVorganger <= charNachfolger im inputString
        for (sum = i + 1; sum < i + 4 && inputString[sum] >= '0' && inputString[sum] <= '9' && inputString[sum - 1] <= inputString[sum]; sum++)
        {
            // creates sum of the index
            // printf("%d\n", sum);
        };
        if (sum == i + 4) // win condition
        {
            return true;
        }
    }
    return false;
}

void four_sorted_digits_test(void)
{
    test_equal_b(four_sorted_digits(""), false);
    test_equal_b(four_sorted_digits("123"), false);
    test_equal_b(four_sorted_digits("abcd"), false);
    test_equal_b(four_sorted_digits("1234"), true);
    test_equal_b(four_sorted_digits("2479"), true);
    test_equal_b(four_sorted_digits("1111"), true);
    test_equal_b(four_sorted_digits("a123"), false);
    test_equal_b(four_sorted_digits("123a"), false);
    test_equal_b(four_sorted_digits("1234a"), true);
    test_equal_b(four_sorted_digits("xx1234y"), true);
    test_equal_b(four_sorted_digits("abc12345"), true);
    test_equal_b(four_sorted_digits("a 1 2 3 4 c"), false);
    test_equal_b(four_sorted_digits("a 3333 c"), true);
}

int main(void)
{
    base_init();
    base_set_memory_check(true);
    four_sorted_digits_test();
    return 0;
}
