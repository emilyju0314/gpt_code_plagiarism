#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n;
        std::cin >> n;

        std::vector<int> powers(n);
        for (int i = 0; i < n; i++) {
            std::cin >> powers[i];
        }

        int min_moves = std::min(std::min(powers[0]-1, n-powers[n-1]), powers[n-1]-1 + n-powers[0]); // Calculate minimum moves
        std::cout << min_moves << std::endl;
    }

    return 0;
}