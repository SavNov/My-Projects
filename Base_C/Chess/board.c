#include <iostream>
#include <vector>
#include <cstdlib>

const int CELL_SIZE = 5;

void printBoard(const std::vector<std::string>& board)
{
    for (int y = 0; y < 8; ++y) {
        if (y % 2 == 0) // Black rows
            std::cout << "+---+---+---+---+---+---+---+---+\n";
        else // White rows
            std::cout << "|   |   |   |   |   |   |   |   |\n";

        for (int x = 0; x < 8; ++x) {
            if (x % 2 == 0)
                std::cout << "| " << board[y][x] << " "; // Print ASCII character representing the square.
            else
                std::cout << "|" << board[y][x] << " ";   // Print ASCII character and add a newline for white spaces.
        }
        std::cout << "|\n";
    }
}

void createBoard(std::vector<std::string>& board)
{
    // Initialize the board with empty squares.
    for (int y = 0; y < 8; ++y) {
        std::string row;
        for (int x = 0; x < 8; ++x)
            row += ' ';
        board.push_back(row);
    }

    // Add black pieces to the top of the board.
    int pieceSize = CELL_SIZE * 2 - 1;
    board[0][3] = 'R'; // Rook
    board[0][4] = 'N'; // Knight
    board[0][5] = 'B'; // Bishop
    board[0][6] = 'Q'; // Queen
    board[0][7] = 'K'; // King

    // Add white pieces to the bottom of the board.
    for (int i = 7; i >= 4 && i > 0; --i) {
        int piecePositions[][2] = {{1, i}, {6, i}, {3, i + 1}, {5, i + 1}};
        for (auto position : piecePositions)
            board[7 - i][position[0]] = toupper(position[1]); // Add pawns, rooks, knights, and a king.
    }
}

int main()
{
    std::vector<std::string> board;
    createBoard(board);
    printBoard(board);

    return 0;
}