// wie oft der gleiche Buchstabe im String vorkommt

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN(arr) ((int)(sizeof(arr) / sizeof(arr)[0]))

int countRepeatingChar(char currentString[])
{
    for (int i = 0; i < strlen(currentString); i++)
    {
        int result = 0;
        char currentChar = currentString[i];
        for (int j = 0; j < strlen(currentString); j++)
        {
            if (currentChar == currentString[j])
            {
                result++;
            }
        }
        if (result > 1)
        {
            printf("%d", result);
            // return result;
        }
    }
}

int main()
{
    char testData[][20] = {
        " ",
        "abc",
        "aabc",
        "AabBcC",
        "cccEEee",
        "111222"};
    for (int i = 0; i < LEN(testData); i++)
    {
        printf("test#%d: ", i);
        for (int j = 0; j < LEN(testData[0]); j++)
        {
            printf("%c", testData[i][j]);
        }
        printf(" --> ");
        countRepeatingChar(testData[i]);
        printf("\n");
    }
    return 0;
}