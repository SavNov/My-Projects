#include <iostream>
#include <iomanip>

const int ROWS = 8;
const int COLS = 8;

void printPiece(char piece) {
    switch (piece) {
        case ' ': std::cout << "  "; break;
        default: std::cout << piece;
    }
}

int main() {
    // Create the chess board array
    char board[ROWS][COLS] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    // Print the chess board
    std::cout << "Chess Board:\n";
    for (int row = 0; row < ROWS; ++row) {
        for (int col = 0; col < COLS; ++col) {
            printPiece(board[row][col]);
        }
        std::cout << "\n";
    }

    return 0;
}
