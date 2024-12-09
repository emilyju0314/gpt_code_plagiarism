#include <iostream>
#include <cmath>

long long find_shortest_path(int n, long long a, long long b) {
    // Check if a and b are in the same connected component
    if ((a - 1) / n == (b - 1) / n) {
        return std::abs((a - 1) % n - (b - 1) % n);
    } else {
        return std::min((a - 1) % n + (b - 1) % n + 1, n - (a - 1) % n + (b - 1) % n + 2);
    }
}

int main() {
    int t, n;
    std::cin >> t >> n;

    for (int i = 0; i < t; i++) {
        long long a, b;
        std::cin >> a >> b;
        std::cout << find_shortest_path(n, a, b) << std::endl;
    }

    return 0;
}