/*
Saaket Raman - Project 2

Program that builds on Project 1, allowing multiple rounds of the dice game.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int numRounds, currRound;
    printf("Enter the number of rounds: ");
    scanf("%d", &numRounds);

    if (numRounds > 0){
        int player1, player2;
        int player1_wins=0, player2_wins=0;     // counter for number of wins per player
        int upper=6, lower=1;   // declaring variables for the srand() function

        srand(time(NULL));  // set seed for rand() so it generates different sequences of random numbers

        for (currRound=1; currRound <= numRounds; currRound++){
            player1 = (rand() % (upper-lower+1)) + lower;
            player2 = (rand() % (upper-lower+1)) + lower;

            printf("Round %d: Player 1's number is %d, Player 2's number is %d.\n", currRound, player1, player2);

            /* Dice comparisons and deduction of winners; if a player wins, the win counter of the player increments.
                If both players get the same number, it is a tie and neither gets a point */

            if (player1 < player2){
                player2_wins++;
            }
            else if (player1 > player2){
                player1_wins++;
            }
        }

        // Declaring the outcome of the game
        
        if (player1_wins > player2_wins){
            printf("Player 1 wins!\n");
        }
        else if (player1_wins < player2_wins){
            printf("Player 2 wins!\n");
        }
        else {
            printf("It's a draw!\n");
        }
    }
    else {
        printf("Invalid number of rounds. Program terminated.\n");
    }

    return 0;
}