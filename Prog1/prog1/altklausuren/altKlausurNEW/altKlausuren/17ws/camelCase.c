// strings mit xmalloc kopieren über string laufen
// und alle lowercases in string direkt übergeben, leerzeichen auch, uppercases je nach position übergeben oder zu "_x" transformieren.
// die zusätzliche größenveränderung beim allocieren natürlich vorher beachten
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

bool is_letter(char current)
{
  bool result = false;
  if ((current >= 'a' && current <= 'z') || (current >= 'A' && current <= 'Z'))
  {
    result = true;
  }
  return result;
}
bool is_upper(char current)
{
  bool result = false;
  if (current >= 'A' && current <= 'Z')
  {
    result = true;
  }
  return result;
}
bool is_lower(char current)
{
  bool result = false;
  if (current >= 'a' && current <= 'z')
  {
    result = true;
  }
  return result;
}
char to_upper(char current)
{
  if (is_lower(current))
  {
    return toupper(current);
  }
  else
  {
    printf("char is not lower case\n");
    return -1;
  }
}
char to_lower(char current)
{
  if (is_upper(current))
  {
    return tolower(current);
  }
  else
  {
    printf("char is not upper case\n");
    return -1;
  }
}

void camelCase(char currentString[], char *result)
{
  bool entireStringUpperCase = true;
  for (int i = 0; i < strlen(currentString); i++)
  {
    if (is_lower(currentString[i]))
    {
      entireStringUpperCase = false;
    }
  }

  int j = 0;
  for (int i = 0; i < strlen(currentString); i++)
  {
    printf("%d\n", j);
    if (entireStringUpperCase)
    {
      if (i == 0)
      {
        result[i] = currentString[i];
      }
      if (i != 0)
      {
        result[j] = '_';
        j++;
        result[j] = to_lower(currentString[i]);
      }
    }
    else
    {
      result[i] = currentString[i];
    }
    j++;
  }
}

int main()
{
  char testString0[] = "abcd";    // abcd *
  char testString1[] = "Abcd";    // Abcd *
  char testString2[] = "ABCD";    // A_b_c_d
  char testString3[] = "ABCDEF";  // A_b_c_d_e_f
  char testString4[] = "ABCD EF"; //A_b_c_d E_f
  char *result = malloc(sizeof(char));
  camelCase(testString4, result);

  for (int i = 0; i < strlen(result); i++)
  {
    printf("%c", result[i]);
  }
  printf("\n");
}