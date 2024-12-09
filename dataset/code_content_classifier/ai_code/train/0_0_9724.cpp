#include <iostream>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    int a1, a2, a3;
    std::cin >> a1 >> a2 >> a3;

    int b1, b2, b3;
    std::cin >> b1 >> b2 >> b3;

    // Calculate minimum number of rounds Alice can win
    int min_wins = std::min(a1, b2) + std::min(a2, b3) + std::min(a3, b1);
    
    // Calculate maximum number of rounds Alice can win
    int max_wins = std::min(a1, b2) + std::min(a2, b3) + std::min(a3, b1) + std::min(a1 - min(a1, b2), b1) + std::min(a2 - min(a2, b3), b2) + std::min(a3 - min(a3, b1), b3);

    std::cout << min_wins << " " << max_wins << std::endl;

    return 0;
}