#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Funktion implementieren, die Leerzeichen am Anfang und am Ende entfernen
char * trimWhitespaces (char * input)
{
	char * new = NULL;
	
	if (input != NULL)
	{
		int start = 0, end = 0, n = strlen(input) -1;
		
		//Anfang ohne Leerzeichen suchen
		for (int i=0; i<n; i++)
		{
			if (input[i] != ' ')
			{
				start = i;
				break;
			}
		}
		
		//Ende ohne Leerzeichen suchen
		for (int i=n; i>=0; i--)
		{
			if (input[i] != ' ')
			{
				end = i;
				break;
			}
		}
		
		//Neuer String
		new = calloc(end-start, sizeof(char));
		
		//Zwischen Start und Ende die Zeichen aus dem alten in den neuen String kopieren
		for (int i=start; i<=end; i++)
		{
			new[i-start] = input[i];
		}
		
		// '\0' anfügen
		new[end-start+1] = '\0';
	}
	
	return new;
}

int test(char * unsolved, char * solved)
{
	if (unsolved != NULL)
		return strcmp(trimWhitespaces(unsolved), solved );
	else
	{
		strcmp(trimWhitespaces(unsolved), solved );
		return 0;
	}
}

int main (void)
{
	//Test 1
	if (test(NULL, "Hallo") == 0)
		printf("Test passed!\n\n");
	else
		printf("Test failed!\n\n");
	
	//Test 2
	if (test(" Hallo ", "Hallo") == 0)
		printf("Test passed!\n\n");
	else
		printf("Test failed!\n\n");
	
	//Test 3
	if (test(" Hal lo ", "Hal lo") == 0)
		printf("Test passed!\n\n");
	else
		printf("Test failed!\n\n");
	
	//Test 4
	if (test("", "") == 0)
		printf("Test passed!\n\n");
	else
		printf("Test failed!\n\n");
}