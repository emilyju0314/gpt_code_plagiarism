#include <iostream>
#include <algorithm>

int main() {
    int r, g, b;
    std::cin >> r >> g >> b;

    int maxBalloons = std::max(r, std::max(g, b));
    int totalBalloons = r + g + b;

    int tables = (totalBalloons - maxBalloons) / 2;
    if (maxBalloons >= tables) {
        std::cout << tables << std::endl;
    } else {
        std::cout << maxBalloons << std::endl;
    }

    return 0;
} 

//Input: 5 4 3
//Output: 4

//Input: 1 1 1
//Output: 1

//Input: 2 3 3
//Output: 2