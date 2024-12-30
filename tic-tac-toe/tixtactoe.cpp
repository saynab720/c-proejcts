#include <iostream>
#include <vector>
using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>> &board);
bool checkWin(const vector<vector<char>> &board, char player);
bool isDraw(const vector<vector<char>> &board);
void makeMove(vector<vector<char>> &board, char player);

int main() {
    vector<vector<char>> board(3, vector<char>(3, ' ')); // 3x3 board
    char currentPlayer = 'X';

    cout << "Welcome to Tic Tac Toe!\n";
    displayBoard(board);

    while (true) {
        cout << "Player " << currentPlayer << "'s turn.\n";
        makeMove(board, currentPlayer);
        displayBoard(board);

        if (checkWin(board, currentPlayer)) {
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw(board)) {
            cout << "It's a draw!\n";
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Display the board
void displayBoard(const vector<vector<char>> &board) {
    cout << "  0 1 2\n";
    for (int i = 0; i < 3; ++i) {
        cout << i << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << "|";
        }
        cout << "\n";
        if (i < 2) cout << "  -+-+-\n";
    }
}

// Check if a player has won
bool checkWin(const vector<vector<char>> &board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) || 
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Check if the game is a draw
bool isDraw(const vector<vector<char>> &board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

// Handle player's move
void makeMove(vector<vector<char>> &board, char player) {
    int row, col;
    while (true) {
        cout << "Enter row and column (0-2): ";
        cin >> row >> col;
        if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            cout << "Invalid move. Try again.\n";
        }
    }
}
