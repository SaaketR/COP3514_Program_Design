/*
Saaket Raman - Project 5

This program compares two strings of equal length. If the first string is less than the second, output is -1. If the two strings 
are equivalent, output is 0. If the first string is greater than the second, output is 1. The cases of the letters are not 
taken into consideration and do not affect the comparison.

*/

#include <stdio.h>
#define MAX_CHAR 1000

void read_line(char *str);              // Reads line

int compare(char *s1, char *s2);        // Comparison function; returns result of the comparison (-1, 0, 1)

int main()
{
    char s1[MAX_CHAR+1], s2[MAX_CHAR+1];

    printf("Enter first string: ");     // Processes the first string
    read_line(s1);
    
    printf("Enter second string: ");        // Processes the second string
    read_line(s2);

    printf("%d\n", compare(s1, s2));        // Calling the compare() function and printing result

    return 0;
}

void read_line(char *str)
{
    int ch;
    while ((ch = getchar()) != '\n'){       // Keep getting the characters until a newline character is used
        *str++ = ch;
    }
    *str = '\0';
}

int compare(char *s1, char *s2)
{
    while (*s1 != '\0'){
        // Variable to store the current variable
        char curr_char_1 = *s1;
        char curr_char_2 = *s2;

        // Making the cases equal
        if ((curr_char_1 >= 65) && (curr_char_1 <= 90)){
            curr_char_1 += 32;
        }
        if ((curr_char_2 >= 65) && (curr_char_2 <= 90)){
            curr_char_2 += 32;
        }

        // Comparing characters and incrementing pointers
        if (curr_char_1 == curr_char_2){
            s1++;
            s2++;
        }
        else if (curr_char_1 < curr_char_2){
            return -1;
        }
        else if (curr_char_1 > curr_char_2){
            return 1;
        }
    }

    return 0;
}

