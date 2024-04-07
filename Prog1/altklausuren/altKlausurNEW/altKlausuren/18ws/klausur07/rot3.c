#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void encode(char *toEncode, int degree)
{
    int stringLength = 0;
    for (int i = 0; i < strlen(toEncode); i++)
    {
        if (toEncode[i] >= 'a' && toEncode[i] <= 'z')
        {
            stringLength++;
        }
    }
    for (int i = 0; i < stringLength; i++)
    {

        if (islower(toEncode[i]))
        {
            toEncode[i] = (toEncode[i] + degree - (int)'a') % 26 + (int)'a';
        }
        else if (isupper(toEncode[i]))
        {
            toEncode[i] = (toEncode[i] + degree - 65) % 26 + 65;
        }
    }
    printf("%d\n", stringLength);
}

int main()
{
    char *toEncode = malloc(sizeof(char));
    strcpy(toEncode, "aaaa");
    encode(toEncode, 3);
    printf("%s\n", toEncode);
    free(toEncode);
}