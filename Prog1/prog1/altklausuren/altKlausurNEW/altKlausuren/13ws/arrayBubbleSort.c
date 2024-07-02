// Array mit bubbleSort sortieren
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

void bubbleSort(int *intArray, int arrayLength)
{
    while (arrayLength--)
    {
        for (int i = 1; i <= arrayLength; i++)
        {
            if (intArray[i - 1] > intArray[i])
            {
                int temp = intArray[i];
                intArray[i] = intArray[i - 1];
                intArray[i - 1] = temp;
            }
        }
    }
}

int main()
{
    int maxAmount = 8;
    int upperLimit = 5;
    int *testData = malloc(sizeof(int));
    srand(time(NULL));
    for (int i = 0; i < maxAmount; i++)
    {
        int randomNumber = rand() % upperLimit;
        testData[i] = randomNumber;
        printf("%d, ", testData[i]);
    }
    bubbleSort(testData, maxAmount);
    printf("\n");
    for (int i = 0; i < maxAmount; i++)
    {
        printf("%d, ", testData[i]);
    }
    free(testData);
}
