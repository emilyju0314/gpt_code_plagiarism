#include <iostream>

int main() {
    int sx, sy, tx, ty;
    std::cin >> sx >> sy >> tx >> ty;

    std::string path = "";

    // Visit point (tx, ty) from (sx, sy)
    for (int i = sy; i < ty; i++) {
        path += "U";
    }
    for (int i = sx; i < tx; i++) {
        path += "R";
    }

    // Return back to (sx, sy) from (tx, ty)
    for (int i = ty; i > sy; i--) {
        path += "D";
    }
    for (int i = tx; i > sx; i--) {
        path += "L";
    }

    // Visit (tx, ty) again
    for (int i = sy; i < ty+1; i++) {
        path += "U";
    }
    for (int i = sx; i < tx+1; i++) {
        path += "R";
    }

    // Return back to (sx, sy) from (tx, ty) for the last time
    for (int i = ty; i > sy; i--) {
        path += "D";
    }
    for (int i = tx; i > sx; i--) {
        path += "L";
    }

    std::cout << path << std::endl;
    
    return 0;
}