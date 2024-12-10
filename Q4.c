#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int user, computer, userScore = 0, computerScore = 0;

    printf("Instructions:\n");
    printf("0-33: Stone, 34-66: Paper, 67-100: Scissors\n");
    printf("Game is 5 rounds.\n");

    srand(time(0));

    for (int i = 1; i <= 5; i++) {
        printf("\nRound %d - Enter your number (0-100): ", i);
        scanf("%d", &user);

        if (user < 0 || user > 100) {
            printf("Invalid input! Try again.\n");
            i--;
            continue;
        }

        computer = rand() % 101;
        printf("Computer chose: %d\n", computer);

        if ((user <= 33 && computer <= 33) || 
            (user >= 34 && user <= 66 && computer >= 34 && computer <= 66) || 
            (user >= 67 && computer >= 67)) {
            printf("It's a Draw!\n");
        } else if ((user <= 33 && computer >= 34 && computer <= 66) || 
                   (user >= 34 && user <= 66 && computer >= 67) || 
                   (user >= 67 && computer <= 33)) {
            printf("Computer wins this round!\n");
            computerScore++;
        } else {
            printf("You win this round!\n");
            userScore++;
        }
    }

    printf("\nFinal Score - You: %d, Computer: %d\n", userScore, computerScore);
    if (userScore > computerScore)
        printf("You are the Winner!\n");
    else if (userScore < computerScore)
        printf("Computer is the Winner!\n");
    else
        printf("It's a Tie!\n");

    return 0;
}
