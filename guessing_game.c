#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void printWelcomeMessage() {
    printf("\n");
    printf("***************************************\n");
    printf("*                                     *\n");
    printf("*      Welcome to the Number Guessing Game!      *\n");
    printf("*                                     *\n");
    printf("***************************************\n");
    printf("\n");
    printf("Instructions:\n");
    printf("1. I will select a random number between 1 and your chosen maximum.\n");
    printf("2. You have to guess the number.\n");
    printf("3. I will tell you if your guess is too high, too low, or correct.\n");
    printf("4. Try to guess the number in as few attempts as possible!\n");
    printf("\n");
}

int main() {
    int number, guess, attempts, maxNumber;
    char playAgain;
    srand(time(0));

    do {
        printWelcomeMessage();

        // Choose difficulty level
        printf("Choose a difficulty level:\n");
        printf("1. Easy (1-10)\n");
        printf("2. Medium (1-50)\n");
        printf("3. Hard (1-100)\n");
        printf("Enter your choice (1-3): ");
        int difficulty;
        scanf("%d", &difficulty);

        switch (difficulty) {
            case 1: maxNumber = 10; break;
            case 2: maxNumber = 50; break;
            case 3: maxNumber = 100; break;
            default:
                printf("Invalid choice! Defaulting to Easy (1-10).\n");
                maxNumber = 10;
        }

        number = rand() % maxNumber + 1;
        attempts = 0;

        printf("I have selected a number between 1 and %d. Try to guess it!\n", maxNumber);

        do {
            printf("Enter your guess: ");
            scanf("%d", &guess);
            attempts++;

            if (guess < 1 || guess > maxNumber) {
                printf("Please guess a number between 1 and %d.\n", maxNumber);
            } else if (guess < number) {
                printf("Too low! Try again.\n");
            } else if (guess > number) {
                printf("Too high! Try again.\n");
            } else {
                printf("Congratulations! You've guessed the number %d in %d attempts.\n", number, attempts);
            }

            // Provide hints after 3 incorrect guesses
            if (attempts > 3) {
                if (guess < number) {
                    printf("Hint: The number is greater than %d.\n", guess);
                } else {
                    printf("Hint: The number is less than %d.\n", guess);
                }
            }

        } while (guess != number);

        printf("Do you want to play again? (y/n): ");
        scanf(" %c", &playAgain);
    } while (playAgain == 'y' || playAgain == 'Y');

    printf("Thank you for playing! Goodbye!\n");
    return 0;
}