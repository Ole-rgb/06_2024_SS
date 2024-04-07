// Schreiben Sie eine Funktion, die überprüft, ob in einem String 4 aufeinanderfolgende aufsteigende Zahlen auftreten.
// Beispielsweise "as53679e".

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool ascendingInString(char *current)
{
    bool result = false;
    if (current == NULL)
    {
        return result;
    }
    else
    {
        int indexAmount = 0;
        for (int i = 0; i < strlen(current); i++)
        {
            if (current[i] + 1 == current[i + 1] && current[i] >= 48 && current[i] + 1 <= 57)
            {
                indexAmount++;
            }
            if (indexAmount == 3)
            {
                result = true;
            }
        }
    }
    return result;
}

int main()
{
    char testString[] = "ab1234cde";
    printf("%d\n", ascendingInString(testString));
    return 0;
}