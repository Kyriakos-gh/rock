/*
    rock.c : Rock-Paper-Scissors game
    Based on Python code of the game from https://realpython.com/python-rock-paper-scissors/
    Kyriakos, 14/10/2022
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROCK        0
#define PAPER       1
#define SCISSORS    2

int main(void)
{
    unsigned int games_number = 0, wins_number = 0;

    while(1) {
        unsigned int computer_action;
        int user_action;
        const char *possible_actions[] = {"rock", "paper", "scissors"};
        char play_again;

        // Uses current time as seed to random generator
        srand(time(NULL));

        // Chooses a randon number from 0 to 2. 0 for rock, 1 for paper and 2 for scissors
        computer_action = rand() % 3;

        // Shows available choices, takes input and checks it
        printf("Enter a choice ('1' for rock, '2' for paper, '3' for scissors): ");
        scanf("%1d", &user_action);
        if(user_action < 1 || user_action > 3) {
            printf("Wrong input. Please try again.\n");
            continue;
        }
        user_action--;

        printf("You chose %s, computer chose %s.\n", possible_actions[user_action], possible_actions[computer_action]);

        // Compares input and shows suitable output
        if(user_action == computer_action) {
            printf("Both players selected %s. It's a tie!\n", possible_actions[user_action]);
        }
        else if(user_action == ROCK) {
            if(computer_action == SCISSORS) {
                printf("Rock smashes scissors! You win!\n");
                wins_number++;
            }
            else {
                printf("Paper covers rock! You lose.\n");
            }
        }
        else if(user_action == PAPER) {
            if(computer_action == ROCK) {
                printf("Paper covers rock! You win!\n");
                wins_number++;
            }
            else {
                printf("Scissors cuts paper! You lose.\n");
            }
        }
        else if(user_action == SCISSORS) {
            if(computer_action == PAPER) {
                printf("Scissors cuts paper! You win!\n");
                wins_number++;
            }
            else {
                printf("Rock smashes scissors! You lose.\n");
            }
        }

        games_number++;

        // Controls the while loop
        printf("Play again? (y/n): ");
        scanf(" %c", &play_again);
        if(play_again != 'y') {
            break;
        }
    }

    printf("You played %d times and won %d times!\n", games_number, wins_number);
    return 0;
}
