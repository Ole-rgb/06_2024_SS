

#include "base.h"
#include "string.h"

/**
(a) Todo: Implement.
Return whether String a contains String b
*/
bool contains(String a, String b) {
    return false;
}

/**
(b) Todo: Implement. Nicht so wichtig.
Return the result of the evaluation (AND) of the bool expressions included in the string
*/
bool bool_expr_and(String a) {
    return false;
}

/**
(c) Todo: Implement.
Gebe die länge der längsten Sequenz des Zeichens c aus.
MÖGLICHE KLAUSURAUFGABE  
*/
int longest_sequence(String s, char c){

}

/** (d) MÖGLICHE KLAUSURAUFGABE
 *  Gebe aus ob ein String mit einer Zahl endet.
 */

bool ends_with_digit(String s){
        
    
}

/** (e) Mögliche Klausuraufgabe
 * Gebe die Anzahl von doppelt vorkommender Zeichen im String aus. Siehe Testfälle.
*/
 int count_double_chars(String s){
    
}





void test(void) {
    // (a)
    /* nicht so wichtig:
    check_expect_i(contains("abc", "b"), true);
    check_expect_i(contains("abc", "ac"), false);
    check_expect_i(contains("Das ist ein t?st.", "test"), true);
    check_expect_i(contains("Das ist ein test.", "Dass"), false);

    
    // (b)
    check_expect_i(bool_expr_and("abc1"), true);
    check_expect_i(bool_expr_and("0abc1"), false);
    check_expect_i(bool_expr_and("Das 1st ein Test 0der?"), false);
    */
    
    // (c)
    check_expect_i(longest_sequence("Hello World!", 'l'), 2);
    check_expect_i(longest_sequence("Roffffflcopterf!", 'f'), 5);
    check_expect_i(longest_sequence("Hello World!", 'q'), 0);
    
    // (d)
    check_expect_i(ends_with_digit("Das ist ein Test"), false);
    check_expect_i(ends_with_digit("Das ist ein Test 12345"), true);
    check_expect_i(ends_with_digit("5"), true);
    check_expect_i(ends_with_digit("a"), false);
    
    // (e)
    check_expect_i(count_double_chars("Hello World!"), 1);
    check_expect_i(count_double_chars("Helllo World!"), 0);
    check_expect_i(count_double_chars("aaaa"), 0);
    check_expect_i(count_double_chars("aabbcc"), 3);
    check_expect_i(count_double_chars("abccc"), 0);
    check_expect_i(count_double_chars("aabcc"), 2);
    check_expect_i(count_double_chars("a"), 0);
    check_expect_i(count_double_chars(""), 0);
    
}

int main(void) {
    test();
    return 0;
}
