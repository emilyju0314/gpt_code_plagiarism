#include <iostream>

int main() {
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;
    int x5, y5, x6, y6;

    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> x5 >> y5 >> x6 >> y6;

    bool overlap = true;
    // check if the black sheets cover the white sheet
    if (x3 <= x1 && x4 >= x2 && y3 <= y1 && y4 >= y2) {
        overlap = false;
    } else if (x5 <= x1 && x6 >= x2 && y5 <= y1 && y6 >= y2) {
        overlap = false;
    }

    if (overlap) {
        std::cout << "NO";
    } else {
        std::cout << "YES";
    }

    return 0;
}