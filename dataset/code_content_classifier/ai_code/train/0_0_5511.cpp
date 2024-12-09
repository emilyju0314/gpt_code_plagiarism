#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n, k, x;
    std::cin >> n >> k >> x;

    std::vector<int> chores(n);
    for (int i = 0; i < n; i++) {
        std::cin >> chores[i];
    }

    int totalTime = 0;
    for (int i = 0; i < n - k; i++) {
        totalTime += chores[i];
    }

    totalTime += k * x;

    std::cout << totalTime << std::endl;

    return 0;
}