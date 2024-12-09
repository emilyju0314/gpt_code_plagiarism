#include <iostream>
#include <cmath>

int main() {
    int r1, c1, r2, c2;
    std::cin >> r1 >> c1 >> r2 >> c2;

    int rook_moves = (r1 == r2 || c1 == c2) ? 1 : 2;
    int bishop_moves = (std::abs(r1 - r2) == std::abs(c1 - c2)) ? 1 : 0;
    int king_moves = std::max(std::abs(r1 - r2), std::abs(c1 - c2));

    std::cout << rook_moves << " " << bishop_moves << " " << king_moves << std::endl;

    return 0;
}