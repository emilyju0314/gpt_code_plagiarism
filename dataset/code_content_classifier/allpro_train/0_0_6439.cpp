#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> x[i];
    }

    int a, b;
    std::cin >> a >> b;

    int moves = 0;
    while (a > b) {
        int min_moves = a - 1;
        for (int i = 0; i < n; ++i) {
            if (x[i] <= a) {
                min_moves = std::min(min_moves, a % x[i]);
            }
        }
        a -= min_moves;
        ++moves;
    }

    std::cout << moves << std::endl;

    return 0;
}