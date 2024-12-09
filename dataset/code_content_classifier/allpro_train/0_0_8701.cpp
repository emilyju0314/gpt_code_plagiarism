#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        std::cin >> positions[i];
    }

    std::sort(positions.begin(), positions.end());

    int distance = positions[n/2] - positions[n/2 - 1];
    std::cout << distance << std::endl;

    return 0;
}