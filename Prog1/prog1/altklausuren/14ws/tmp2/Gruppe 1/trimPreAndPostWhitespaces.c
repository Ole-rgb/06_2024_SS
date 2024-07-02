#include <stdio.h>
#include <string.h>

//Funktion implementieren, die Leerzeichen am Anfang und am Ende entfernen
char * trimWhitespaces (char * input)
{
	return NULL;
}

int test(char * unsolved, char * solved)
{
	return strcmp(trimWhitespaces(unsolved), solved );
}

int main (void)
{
	//Test 1
	if (test(NULL, "Hallo") == 0)
		printf("Test passed!");
	else
		printf("Test failed!");
	
	//Test 2
	if (test(" Hallo ", "Hallo") == 0)
		printf("Test passed!");
	else
		printf("Test failed!");
	
	//Test 3
	if (test(" Hal lo ", "Hal lo") == 0)
		printf("Test passed!");
	else
		printf("Test failed!");
}