// Prüfen ob ein string t in einem string s vorkommt. string t kann zudem '?' als wildchar (beliebiger character) erhalten
// Bei den Testfällen gab es zudem den Fall dass der String '' geprüft werden musste - mit dem erwarteten Ergebnis true.
// '' Ist die binäre Null, der String ist damit nicht leer... Dazu die Abfrage t[0] == '\0'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool strstrWildcard(const char *searchText, const char *subString)
{
    bool result = false;
    if (subString == NULL || searchText == NULL)
    {
        printf("invalid input\n");
        return result;
    }
    else
    {
        char *p1 = (char *)searchText;
        while (*p1)
        {
            char *p1Begin = p1, *p2 = (char *)subString;
            while (*p1 && *p2 && (*p1 == *p2 || *p2 == '?'))
            {
                p1++;
                p2++;
            }
            if (!*p2)
            {
                printf("string was found\n");
                result = true;
            }
            p1 = p1Begin + 1;
        }
    }
    if (!result)
    {
        printf("string was not found\n");
    }
    return result;
}

int main()
{
    char searchText[] = "GHalloO";
    char subString[] = "G";

    strstrWildcard(searchText, subString);
    return 0;
}