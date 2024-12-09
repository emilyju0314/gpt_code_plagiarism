#include <iostream>
#include <vector>
#include <cmath>

struct Piece {
    char type;
    int x, y;
};

bool isDiagonal(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

bool isHorizontal(int x1, int x2) {
    return x1 == x2;
}

bool isVertical(int y1, int y2) {
    return y1 == y2;
}

bool isAttackingOpponentKing(int x, int y, std::vector<Piece>& pieces) {
    for (const Piece& piece : pieces) {
        if (piece.type == 'B') {
            if (isDiagonal(piece.x, piece.y, x, y)) {
                return true;
            }
        } else if (piece.type == 'R') {
            if (isHorizontal(piece.x, x) || isVertical(piece.y, y)) {
                return true;
            }
        } else if (piece.type == 'Q') {
            if (isHorizontal(piece.x, x) || isVertical(piece.y, y) || isDiagonal(piece.x, piece.y, x, y)) {
                return true;
            }
        }
            
    }
    
    return false;
}

int main() {
    int n;
    std::cin >> n;

    int x0, y0;
    std::cin >> x0 >> y0;

    std::vector<Piece> pieces(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pieces[i].type >> pieces[i].x >> pieces[i].y;
    }

    if (isAttackingOpponentKing(x0, y0, pieces)) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}