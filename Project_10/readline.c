/*
Saaket Raman - Project 10

This program is used to read a user-inputted line using the getchar() function until a newline charater is inputted.

*/

#include <stdio.h>
#include <ctype.h>
#include "readline.h"

// Function to read the user-inputted line.
int read_line(char str[], int n)
{
  int ch, i = 0;

  while (isspace(ch = getchar()))
    ;
  str[i++] = ch;
  while ((ch = getchar()) != '\n') {
    if (i < n)
      str[i++] = ch;
    
   }
   str[i] = '\0';
   return i;
}