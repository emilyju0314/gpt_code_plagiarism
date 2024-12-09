#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, X;
    std::cin >> N >> X;

    std::vector<int> cities(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cities[i];
    }

    std::sort(cities.begin(), cities.end());

    int max_d = 0;
    for (int i = 0; i < N; i++) {
        int dist = std::abs(X - cities[i]);
        max_d = std::__gcd(max_d, dist);
    }

    std::cout << max_d << std::endl;

    return 0;
}