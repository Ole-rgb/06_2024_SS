#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
// String: String gegeben mit mehreren Wörter und Leerzeichen
// a. ersten Buchstaben eines Wortes groß den Rest klein autoCorrectCases
//  - Eingabe: HELLO WORLD
//  - Ausgabe: Hello World

char *autoCorrectCases(char inputString[])
{
    for (int i = 0; i < strlen(inputString); i++)
    {
        if (i == 0)
        {
            inputString[i] = toupper(inputString[i]);
        }
        else if (inputString[i] == ' ' && i != 0)
        {
            inputString[i + 1] = toupper(inputString[i + 1]);
        }
        else if (i != 0 && inputString[i - 1] != ' ')
        {
            inputString[i] = tolower(inputString[i]);
        }
    }
    return inputString;
}

int main()
{
    char testString[] = "HELLO WORLD REEE";
    printf("%s --> ", testString);
    printf("%s\n", autoCorrectCases(testString));
    // int long unsigned = sizeof(xmalloc(5)), warum problematisch ?
    // - int und long sind Datentypen, also doppelt gemoppelt
    // - sizeof() gibt die Größe eines Datentypen wieder
    // - malloc(5) liefert Anfangsadresse und Größe vom allokierten Speicher
    unsigned int testb = sizeof(malloc(50));
    printf("%d\n", testb);
}