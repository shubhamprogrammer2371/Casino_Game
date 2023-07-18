#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int casinoRules()
{
    printf("****************** Welcome to the Shubham's Casino Game *******************\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    printf("RULES\n1. Choose any number between 1 to 10.\n2. If you choose the same number as the machine chooses then you win and will be awarded with the betting amount.\n3. If you choosed the different number then the betting amount will be deducted from your total deposited amount.\n4. If your deposited ammount becomes 0 while playing the casino then you are not allowed to play the game anymore.\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n\n");
}

int casinoGame()
{
    char name[50];
    int computer, guess, choice, total = 0, deposit, bet_amount;
    printf("Enter your name : ");
    scanf("%s", &name);

    printf("\nEnter the amount of money to deposit for the game : ");
    scanf("%d", &deposit);

    while (deposit != 0)
    {
        printf("**********************************************************\nYour Current Balance is :- $%d\n\n", deposit);
        printf("> Press 1 to start the game.\n> Press 0 to end the game.\n\nEnter your choice : ");
        scanf("%d", &choice);
        if (choice == 1)
        {
            printf("\nEnter the money to bet : ");
            scanf("%d", &bet_amount);
            if (bet_amount > deposit)
            {
                printf("\nYou don't have enough money.\nEnter again : ");
                scanf("%d", &bet_amount);
            }
            srand(time(0));
            computer = rand() % 10 + 1;
            printf("\nGuess a number from 1 to 10 : ");
            scanf("%d", &guess);
            if (guess > 10)
            {
                printf("The number is greater than 10.\nEnter again : ");
                scanf("%d", &guess);
            }
            if (guess < 0)
            {
                printf("The number is smaller than 0.\nEnter again : ");
                scanf("%d", &guess);
            }
            if (guess == computer)
            {
                deposit += bet_amount;
                total += bet_amount;
                printf("Congraluations %s !! You have won $%d\n", name, bet_amount);
            }
            else
            {
                deposit -= bet_amount;
                printf("\nBetter luck Next Time %s :) !! You have loss $%d.\nThe Actual Number is %d.\n", name, bet_amount, computer);
            }
        }
        else if (choice == 0)
        {
            printf("\nWe hope you liked the game %s :)\nYou have won a total of $%d from this game.\nYour current deposited money is :- $%d.", name, total, deposit);
            exit(0);
        }
        else
        {
            printf("\nInvalid Choice %s!! Please enter 1 or 0.\n", name);
        }
    }
    printf("\nSir %s, you have $0 as a balance.\nYou have no more money to play.\nHave a nice day :)", name);
}

int main()
{
    casinoRules();
    casinoGame();
    return 0;
}