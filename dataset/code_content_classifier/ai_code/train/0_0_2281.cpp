#include <iostream>
#include <cmath>

bool isRightAngled(int x1, int y1, int x2, int y2, int x3, int y3) {
    int side1_sq = pow(x1 - x2, 2) + pow(y1 - y2, 2);
    int side2_sq = pow(x2 - x3, 2) + pow(y2 - y3, 2);
    int side3_sq = pow(x3 - x1, 2) + pow(y3 - y1, 2);

    int sides[3] = {side1_sq, side2_sq, side3_sq};
    std::sort(sides, sides+3);

    if (sides[2] == (sides[0] + sides[1]))
        return true;
    else
        return false;
}

int main() {
    int x1, y1, x2, y2, x3, y3;
    std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    if (isRightAngled(x1, y1, x2, y2, x3, y3))
        std::cout << "RIGHT" << std::endl;
    else if (isRightAngled(x1+1, y1, x2, y2, x3, y3) || isRightAngled(x1-1, y1, x2, y2, x3, y3)
          || isRightAngled(x1, y1+1, x2, y2, x3, y3) || isRightAngled(x1, y1-1, x2, y2, x3, y3)
          || isRightAngled(x1, y1, x2+1, y2, x3, y3) || isRightAngled(x1, y1, x2-1, y2, x3, y3)
          || isRightAngled(x1, y1, x2, y2+1, x3, y3) || isRightAngled(x1, y1, x2, y2-1, x3, y3)
          || isRightAngled(x1, y1, x2, y2, x3+1, y3) || isRightAngled(x1, y1, x2, y2, x3-1, y3))
        std::cout << "ALMOST" << std::endl;
    else
        std::cout << "NEITHER" << std::endl;

    return 0;
}