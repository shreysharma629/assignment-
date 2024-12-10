#include <stdio.h>

char board[3][3]; // 3x3 game board
char players[2] = {'O', 'X'}; // Player symbols

void initBoard() {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            board[i][j] = ' ';
}

void displayBoard() {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
}

int checkWin(char player) {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; i++) 
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player))
            return 1;
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player))
        return 1;
    return 0;
}

int main() {
    int row, col, turn = 0;
    printf("Welcome to Tic Tac Toe!\n");
    printf("Player 1: O | Player 2: X\n");
    initBoard();
    displayBoard();

    for (int i = 0; i < 9; i++) {
        int currentPlayer = turn % 2;
        printf("\nPlayer %d's turn (%c):\n", currentPlayer + 1, players[currentPlayer]);
        printf("Enter row (1-3) and column (1-3): ");
        scanf("%d %d", &row, &col);
        row--, col--;

        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = players[currentPlayer];
            displayBoard();

            if (checkWin(players[currentPlayer])) {
                printf("\nPlayer %d (%c) wins!\n", currentPlayer + 1, players[currentPlayer]);
                return 0;
            }
            turn++;
        } else {
            printf("Invalid move! Try again.\n");
            i--;
        }
    }
    printf("\nIt's a draw!\n");
    return 0;
}
