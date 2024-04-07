// Für _buchstabe neuen String allokieren und "_" entfernen und den ersten Buchstaben nach "_" groß Schreiben.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char *slashRemover(char *currentString)
{
    printf("%s\n", currentString);
    char *copy = malloc(sizeof(char));
    int j = 0;
    for (int i = 0; i < strlen(currentString); i++)
    {
        if (currentString[i] != '_')
        {
            if (i == 1)
            {
                copy[j] = toupper(currentString[i]);
                j++;
            }
            else
            {
                copy[j] = currentString[i];
                j++;
            }
        }
    }
    printf("%s\n", copy);
    return copy;
}

int main()
{
    char *testString = "_test";
    slashRemover(testString);
}