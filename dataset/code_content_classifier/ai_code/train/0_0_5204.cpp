#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> pillars(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pillars[i];
    }

    int maxPillar = pillars[0];
    int minPillar = pillars[0];

    for (int i = 1; i < n; i++) {
        if (pillars[i] > maxPillar) {
            maxPillar = pillars[i];
        }
        if (pillars[i] < minPillar) {
            minPillar = pillars[i];
        }
    }

    if (maxPillar == pillars[0] || minPillar == pillars[n-1]) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}