#include <iostream>
using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

void printBoard() {
    cout << "Current Board:\n";
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) cout << "---------\n";
    }
    cout << endl;
}

bool checkWin(char player) {
    for (int i = 0; i < SIZE; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][0] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][2] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool checkDraw() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false;
            }
        }
    }
    return true;
}

void makeMove(char player) {
    int move;
    bool validMove = false;
    while (!validMove) {
        cout << "Player " << player << ", enter your move (1-9): ";
        cin >> move;
        if (move < 1 || move > 9) {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        int row = (move - 1) / SIZE;
        int col = (move - 1) % SIZE;
        if (board[row][col] == 'X' || board[row][col] == 'O') {
            cout << "Square already taken. Try again.\n";
        } else {
            board[row][col] = player;
            validMove = true;
        }
    }
}

int main() {
    char currentPlayer = 'X';
    bool gameWon = false;
    bool gameDraw = false;

    while (!gameWon && !gameDraw) {
        printBoard();
        makeMove(currentPlayer);
        gameWon = checkWin(currentPlayer);
        if (gameWon) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        gameDraw = checkDraw();
        if (gameDraw) {
            printBoard();
            cout << "The game is a draw!\n";
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}