// String war gegeben.Sollte abwechselnd zu Upper und Lowercase gemacht werden mit bestimmter Anzahl(Also z.B.2 Groß, 2 Klein)

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *countedUpperLower(char *currentChar, int changeAmount)
{
    char *result = malloc(sizeof(char));
    int j = 0;
    int decider = 0;

    for (int i = 0; i < strlen(currentChar); i++)
    {
        if (decider <= changeAmount)
        {
            if (decider % 2 == 0)
            {
                result[j] = toupper(currentChar[i]);
            }
            else if (decider % 2 != 0)
            {
                result[j] = currentChar[i];
            }
        }
        else
        {
            result[j] = currentChar[i];
        }
        j++;
        decider++;
    }
    return result;
}

int main()
{
    char *testData = malloc(sizeof(char));
    strcpy(testData, "hellooooooo");
    printf("%s\n", countedUpperLower(testData, 6));
}