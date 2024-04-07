// removeletters
//   - nur mit hilfsfunktionen strings in exakt größen allokierten copy string übertragen, alles was letters sind ignorieren.
//   - Zahlen aus String rausschreiben
//   - Originalstring nicht verändern
//   - Rückgabestring dynmanisch allokieren
//   - nur Hilfsfunktionen verwenden und xmalloc
//     - is_letter
//     - s_length
//   - Beispiele
//     -  " " --> " "
//     -  "abc " --> " "
//     -  "1abc" --> "1"
//     -  "x11" --> "11"
//     -  "1a2b3c4d" --> "1234"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr)[0]))

char *removeLetters(char currentString[])
{
    char *result = malloc(sizeof(char));
    for (int i = 0; i < strlen(currentString); i++)
    {
        if (currentString[i] >= 48 && currentString[i] <= 57)
        {
            result[i] = currentString[i];
            printf("%c", result[i]);
        }
    }
    return result;
}

int main()
{
    char testData[][20] = {
        " ",
        "abc ",
        "1abc",
        "1",
        "x11",
        "1a2b3c4d"};
    for (int i = 0; i < LEN(testData); i++)
    {
        printf("test#%d: ", i);
        for (int j = 0; j < LEN(testData[0]); j++)
        {
            printf("%c", testData[i][j]);
        }
        printf(" --> ");
        removeLetters(testData[i]);
        printf("\n");
    }
}