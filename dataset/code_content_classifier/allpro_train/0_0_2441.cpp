#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    // Initialize the chess board
    std::vector<std::vector<char>> chessBoard(n, std::vector<char>(n, ' '));

    // Fill the chess board with knights
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Place knights in alternating colors based on the sum of row and column indices
            chessBoard[i][j] = (i + j) % 2 == 0 ? 'W' : 'B';
        }
    }

    // Print the chess board
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << chessBoard[i][j];
        }
        std::cout << std::endl;
    }

    return 0;
}