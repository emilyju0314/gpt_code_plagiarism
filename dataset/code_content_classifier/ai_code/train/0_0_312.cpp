#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> positions(n/2);
    for (int i = 0; i < n/2; i++) {
        std::cin >> positions[i];
    }

    int moves = 0;
    std::sort(positions.begin(), positions.end());
    for (int i = 0; i < n/2; i++) {
        moves += abs(positions[i] - 2*i - 1);
    }

    std::cout << moves << std::endl;

    return 0;
}