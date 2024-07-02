// Leerzeichen am Anfang / Ende eines Strings entfernen.
// Es darf nur s_length / xmalloc / strlen verwendet werden aus der prog1lib
// (Also kein s_trim)
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char *stringTrim(char *currentChar)
{
    char *result = malloc(sizeof(char));
    int j = 0;

    for (int i = 0; i < strlen(currentChar); i++)
    {
        if (currentChar[i] != ' ')
        {
            result[j] = currentChar[i];
            j++;
        }
    }
    return result;
}

int main()
{
    char *testData = malloc(sizeof(char));
    strcpy(testData, " hello ");
    printf("%s\n", stringTrim(testData));
}