#include <iostream>
#include <vector>

using namespace std;

// Function prototypes
void displayBoard(const vector<vector<char>>& board);
bool isWinner(const vector<vector<char>>& board, char player);
bool isBoardFull(const vector<vector<char>>& board);
bool makeMove(vector<vector<char>>& board, int row, int col, char player);

int main() {
    // Initialize the board
    vector<vector<char>> board(3, vector<char>(3, ' '));
    char currentPlayer = 'X';
    int row, col;
    bool validMove;

    cout << "Tic-Tac-Toe Game" << endl;
    cout << "Player 1 (X) - Player 2 (O)" << endl;

    while (true) {
        displayBoard(board);

        // Get the current player's move
        validMove = false;
        while (!validMove) {
            cout << "Player " << (currentPlayer == 'X' ? "1" : "2") << "'s turn. Enter row and column (0, 1, 2): ";
            cin >> row >> col;

            // Check if the move is valid
            validMove = makeMove(board, row, col, currentPlayer);
            if (!validMove) {
                cout << "Invalid move. Try again." << endl;
            }
        }

        // Check for a winner
        if (isWinner(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << (currentPlayer == 'X' ? "1" : "2") << " wins!" << endl;
            break;
        }

        // Check for a draw
        if (isBoardFull(board)) {
            displayBoard(board);
            cout << "It's a draw!" << endl;
            break;
        }

        // Switch player
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

void displayBoard(const vector<vector<char>>& board) {
    cout << endl;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << " " << board[i][j] << " ";
            if (j < 2) cout << "|";
        }
        cout << endl;
        if (i < 2) cout << "---|---|---" << endl;
    }
    cout << endl;
}

bool isWinner(const vector<vector<char>>& board, char player) {
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

bool isBoardFull(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool makeMove(vector<vector<char>>& board, int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}
