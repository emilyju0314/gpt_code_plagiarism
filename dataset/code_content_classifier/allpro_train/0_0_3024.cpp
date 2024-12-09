#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

bool checkMovePossible(int row, int col, int M, const std::vector<std::vector<char>>& board) {
    return row >= 1 && row <= 3 && col >= 1 && col <= 3 * M + 1 && board[row][col] != 'a' && board[row][col] != 'A';
}

void moveToken(int& row, int& col, std::vector<std::unordered_map<char, bool>>& switches, const std::unordered_map<char, bool>& pushableSwitches) {
    if (switches[row][tolower(board[row][col])]) {
        return;
    }
    if (switches[row][toupper(board[row][col])]) {
        return;
    }

    switches[row][tolower(board[row][col])] = true;

    if (pushableSwitches.find(board[row][col]) != pushableSwitches.end()) {
        switches[row][toupper(board[row][col])] = true;
    }

    col++;
    while (col <= 3 * M + 1) {
        if (board[row][col] != '.') {
            return;
        }
        col++;
    }
}

bool canReachEnd(int M, std::vector<std::vector<char>>& board) {
    std::unordered_map<char, bool> pushableSwitches;
    pushableSwitches['.'] = true;

    int startRow = 2;
    int startCol = 1;
    int endCol = 3 * M + 1;

    std::vector<std::unordered_map<char, bool>> switches(4, std::unordered_map<char, bool>());

    while (true) {
        if (startCol == endCol) {
            std::cout << "0\n";
            return true;
        }

        if (!checkMovePossible(startRow, startCol, M, board)) {
            break;
        }

        moveToken(startRow, startCol, switches, pushableSwitches);
    }

    std::cout << "-1\n";

    return false;
}

int main() {
    int M;
    while (true) {
        std::cin >> M;
        if (M == 0) {
            break;
        }

        std::vector<std::vector<char>> board(4, std::vector<char>(3 * M + 2, '.'));

        for (int i = 1; i <= 3; i++) {
            std::string line;
            std::cin >> line;
            for (int j = 0; j < 3 * M + 1; j++) {
                board[i][j+1] = line[j];
            }
        }

        canReachEnd(M, board);
    }

    return 0;
}