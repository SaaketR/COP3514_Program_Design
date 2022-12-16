/*
Saaket Raman - Project 2

Program to calculate the result of the an arithmetic operation of two single digit positive integers.

*/

#include <stdio.h>

int main(){
    int num1, opp=0, num2;      // Declaring variables for the input (1st integer, operator, and 2nd integer)
    int numCount = 1;       // Counter for the integers (helps maintain the order of integers when reading the input)
    char ch;

    printf("Enter input: ");
    ch = getchar();    
    
    while (ch != '\n'){
        if (ch >= 48 && ch <= 57){      // if the current character is an integer (0 <= ch <= 9)
            if (numCount == 1){
                num1 = ch - '0';
                numCount++;
            }
            else if (numCount == 2){
                num2 = ch - '0';
                numCount++;
            }
        }
        else if (ch==42 || ch==43 || ch==45) {      // if the current character is either addition, subtraction, or multiplication
            opp = ch;
        }
        ch = getchar();
    }

    // Accessing the the different possibilities for type of operator    
    switch (opp){
        case 42:    printf("%d\n", num1*num2);
                    break;
        case 43:    printf("%d\n", num1+num2);
                    break;
        case 45:    printf("%d\n", num1-num2);
                    break;
        default:    printf("Invalid operator. Program terminated.\n");
                    break;
    }

    return 0;
}