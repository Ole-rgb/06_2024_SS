// gcc -o checkSumCalc checkSumCalc.c -lm && ./checkSumCalc
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
void checkSumCalc(int current)
{
    int checkSum = 0;
    int numberAmount = log10(current) + 1;
    int *numberArray = calloc(numberAmount, sizeof(int));
    for (int i = 0; i < numberAmount; ++i, current /= 10)
    {
        numberArray[i] = current % 10;
        checkSum += numberArray[i];
    }
    printf("%d\n", checkSum);
}

int main()
{
    int checkSumData = 123;
    checkSumCalc(123);
}