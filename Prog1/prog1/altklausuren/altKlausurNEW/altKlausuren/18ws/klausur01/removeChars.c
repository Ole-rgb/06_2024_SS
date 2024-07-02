// Chars aus einem String entfernen
#include <stdio.h>
#include <string.h>

int main()
{
    char test[] = "hello";
    char element = 'o';

    for (int i = 0; i < strlen(test); i++)
    {
        if (test[i] == element)
        {
            // if (test[i] == test[i + 1])
            // {
            //     printf("l\n");
            // }
            // else
            // {
            // test[i] = test[i + 1];
            for (int j = i; j < strlen(test); j++)
            {
                test[j] = test[j + 1];
                //     }
                // }
            }
        }
    }
    printf("%s\n", test);
}
