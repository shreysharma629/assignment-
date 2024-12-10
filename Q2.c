#include <stdio.h>
#include <string.h>

char word[7] = "HANGMAN", your_word[7];

void displayWord() {
    printf("_ _ _ _ _ _ _\n");
}

void playGame(int chances) {
    for (int i = 1; i <= 3; i++) {
        printf("\nEnter your guess (word): ");
        scanf("%s", your_word);

        if (strcmp(your_word, word) == 0) {
            printf("Congratulations! Your guess is correct. The word is HANGMAN.\n");
            return;
        } else {
            chances--;
            if (chances > 0) {
                printf("Incorrect! You have %d chances left.\n", chances);
            } else {
                printf("No chances left. You lose! The word was HANGMAN.\n");
                return;
            }
        }
    }
}

int main() {
    int n;
    printf("Welcome to the Hangman Game!\n");
    printf("Press any number between 0-9 to start: ");
    scanf("%d", &n);

    printf("\nInstructions:\n");
    printf("1. A word is given with hidden characters. Guess the word.\n");
    printf("2. Enter the full word (not just a character).\n");
    printf("3. You have 3 chances.\n");
    printf("4. Use UPPERCASE letters only.\n");

    printf("\nThe word you need to guess looks like this:\n");
    displayWord();

    playGame(3);

    return 0;
}
