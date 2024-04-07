// Remove String. 2 Strings gegeben.
// Alle chars die in String 1 vorkommen, aber nicht in String 2 in einen neuen allokierten String übergeben
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
int main()
{
    char string1[] = "Guten Tag";
    char string2[] = "Tag";
    char *result = (char *)malloc(sizeof(char));
    if (strcmp(string1, string2) == 0)
    {
        printf("strings are identical\n");
    }
    else
    {
        for (int i = 0; i < strlen(string1); i++)
        {
            if (strchr(string2, string1[i]))
            {
                // printf("found char: %c\n", *strchr(string2, string1[i]));
            }
            else
            {
                result[i] = string1[i];
            }
        }
    }
    printf("%s\n", result);
}