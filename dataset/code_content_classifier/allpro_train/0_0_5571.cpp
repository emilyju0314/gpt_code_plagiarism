#include <iostream>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;

    std::unordered_map<int, int> frontCount, backCount;

    for (int i = 0; i < n; i++) {
        int front, back;
        std::cin >> front >> back;
        frontCount[front]++;
        backCount[back]++;
    }

    int maxFront = 0, maxBack = 0;
    for (auto it : frontCount) {
        maxFront = std::max(maxFront, it.second);
    }

    for (auto it : backCount) {
        maxBack = std::max(maxBack, it.second);
    }

    int moves = -1;

    if (maxFront >= n/2) {
        moves = n - maxFront;
    } else if (maxBack >= n/2) {
        moves = n - maxBack;
    }

    std::cout << moves << std::endl;

    return 0;
}