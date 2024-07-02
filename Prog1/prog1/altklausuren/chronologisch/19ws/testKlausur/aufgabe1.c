// a.)#####################
// Implementieren Sie die Funktion char* remove digits(char* s). Diese soll
// moglicherweise in s vorkommende Ziffern entfernen und das Resultat in einem neu allo- ¨
// kierten String zuruckgeben. Der Eingabestring darf nicht ver ¨ andert werden. Ihre Imple- ¨
// mentierung darf nur die Funktionen strlen, is digit und xmalloc verwenden. Es darf nur
// so viel Speicher allokiert werden, wie zur Aufnahme des Resultats notwendig ist
#include "base.h"
bool is_digit(char c)
{
    return c >= '0' && c <= '9';
}
char *remove_digits(char *s)
{
    int charAmount = 0;
    int stringSize = strlen(s);
    for (int i = 0; i < stringSize; i++)
    {
        if (!is_digit(s[i]))
        {
            charAmount++;
        }
    }
    char *temp = xmalloc(charAmount + 1);
    int j = 0;
    for (int i = 0; i < stringSize; i++)
    {
        if (!is_digit(s[i]))
        {
            temp[j] = s[i];
            j++;
        }
    }
    temp[stringSize] = '\0';
    // printf("%s\n", temp);
    return temp;
}
void test(void)
{
    test_equal_s(remove_digits(""), "");
    test_equal_s(remove_digits("x"), "x");
    test_equal_s(remove_digits("11"), "");
    test_equal_s(remove_digits("11x"), "x");
    test_equal_s(remove_digits("x11"), "x");
    test_equal_s(remove_digits("x11x"), "xx");
    test_equal_s(remove_digits("1a2b3c4"), "abc");
}
int main(void)
{
    test();
    return 0;
}
// b.)#####################
// Wie viele Bytes im Speicher belegt die Zeichenkette "hello" in C?
// Antwort: 1 char hat 1 B also hello ist 5B +  '\0' 1B = 6B
