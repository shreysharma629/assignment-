#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TRIES 3 // Maximum number of incorrect guesses

void displayWord(char word[], int guessed[], int length) {
    for (int i = 0; i < length; i++) {
        if (guessed[i]) {
            printf("%c ", word[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

int main() {
    char word[] = "PROGRAMMING"; // The word to guess
    int length = strlen(word);
    int guessed[length];
    memset(guessed, 0, sizeof(guessed)); // Initialize guessed array to 0

    int incorrectTries = 0;
    char guess;

    printf("Welcome to Hangman Game!\n");
    printf("Guess the word. You have %d chances.\n", MAX_TRIES);

    while (incorrectTries < MAX_TRIES) {
        printf("\nCurrent word: ");
        displayWord(word, guessed, length);

        printf("Enter your guess (a single letter): ");
        scanf(" %c", &guess);
        guess = toupper(guess); // Convert to uppercase for case-insensitivity

        int correctGuess = 0;
        for (int i = 0; i < length; i++) {
            if (word[i] == guess && !guessed[i]) {
                guessed[i] = 1; // Mark the letter as guessed
                correctGuess = 1;
            }
        }

        if (!correctGuess) {
            incorrectTries++;
            printf("Wrong guess! You have %d chances left.\n", MAX_TRIES - incorrectTries);
        }

        // Check if the entire word is guessed
        int allGuessed = 1;
        for (int i = 0; i < length; i++) {
            if (!guessed[i]) {
                allGuessed = 0;
                break;
            }
        }
        if (allGuessed) {
            printf("\nCongratulations! You guessed the word: %s\n", word);
            return 0;
        }
    }

    printf("\nGame Over! The correct word was: %s\n", word);
    return 0;
}
