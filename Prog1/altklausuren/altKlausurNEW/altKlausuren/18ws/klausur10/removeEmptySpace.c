// Entferne von einem String alle Leerzeichen am Anfang

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    char *testData = malloc(sizeof(char));
    testData = "  hello";
    char *result = malloc(sizeof(char));
    int stringLength = 0;
    int j = 0;
    for (int i = 0; i < strlen(testData); i++)
    {
        // if (testData[i] >= 'a' && testData[i] <= 'z')
        // {
        //     stringLength++;
        // }
        if (testData[i] != ' ')
        {
            result[j] = testData[i];
            j++;
        }
    }
    printf("%s\n", result);

    return 0;
}
