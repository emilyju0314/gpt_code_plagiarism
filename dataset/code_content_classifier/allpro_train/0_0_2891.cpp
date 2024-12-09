#include <iostream>
#include <cmath>

int main() {
    char rook1, rook2, whiteKing, blackKing;
    std::cin >> rook1 >> rook2 >> whiteKing >> blackKing;

    int rook1_x = rook1 - 'a';
    int rook1_y = rook2 - '0' - 1;
    int rook2_x = rook2 - 'a';
    int rook2_y = rook2 - '0' - 1;
    int whiteKing_x = whiteKing - 'a';
    int whiteKing_y = whiteKing - '0' - 1;
    int blackKing_x = blackKing - 'a';
    int blackKing_y = blackKing - '0' - 1;

    bool mate = false;

    if (abs(whiteKing_x - blackKing_x) <= 1 && abs(whiteKing_y - blackKing_y) <= 1) {
        mate = true;
    } else if (whiteKing_x == blackKing_x || whiteKing_y == blackKing_y) {
        mate = true;
    } else if (whiteKing_x == rook1_x || whiteKing_y == rook1_y) {
        if (abs(rook1_x - blackKing_x) > 1 && abs(rook1_y - blackKing_y) > 1) {
            mate = true;
        }
    } else if (whiteKing_x == rook2_x || whiteKing_y == rook2_y) {
        if (abs(rook2_x - blackKing_x) > 1 && abs(rook2_y - blackKing_y) > 1) {
            mate = true;
        }
    }

    if (mate) {
        std::cout << "CHECKMATE" << std::endl;
    } else {
        std::cout << "OTHER" << std::endl;
    }

    return 0;
}