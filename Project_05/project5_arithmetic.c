/*
Saaket Raman - Project 5

This program evaluates the sum, difference, and product of two single digit integers using the command line arguments. The 
arithmetic expression will be written directly in the command line and will thus be used to perform the operation.

*/


#include <stdio.h>

int main(int argc, char *argv[])
{
    int num1, num2;     // The required numbers

    char ch, opp;       // ch is the current character in the command line; opp is the operator
    int numCount = 1, num_opp = 0;

    int i;
    for (i = 1; i < argc; i++){         // looping through the command line arguments
        ch = *argv[i];       // current character
        if (ch == 32) {        // skip spaces
            continue;
        }
        else {
            // printf("%d\n", ch);      // helper statement to check the current value of ch
            if ((ch >= 48) && (ch <= 57)){      // if the current character is an integer (0 <= ch <= 9)
                if (numCount == 1){
                    num1 = ch - '0';        // storing the first number in num1
                    numCount++;
                }
                else {
                    num2 = ch - '0';        // storing the second number in num2
                    numCount++;
                }
            }
            else if (ch==42 || ch==43 || ch==45){       // updating the operator (+ = 42, - = 43, * = 45)
                opp = ch;
                num_opp++;
            }
        }
    }
        
    if ((numCount != 3) && (num_opp = 1)){      // condition for incorrent cmd line argmt formating
        printf("ERROR: Please enter the command line arguments in the correct format.\n");
    }
    else {
        // printf("%d\n", opp);         // helper statement to check current operation value
        switch (opp){
            case 42:    printf("%d\n", num1*num2);      // Product
                        break;
            case 43:    printf("%d\n", num1+num2);      // Sum
                        break;
            case 45:    printf("%d\n", num1-num2);      // Difference
                        break;
            default:    printf("Invalid operator. Program terminated.\n");
                        break;
        }
    }
    
    return 0;
        
}