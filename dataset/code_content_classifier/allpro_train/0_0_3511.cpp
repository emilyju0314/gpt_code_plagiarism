#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> enter(n);
    std::vector<int> exit(n);

    for (int i = 0; i < n; i++) {
        std::cin >> enter[i];
    }

    for (int i = 0; i < n; i++) {
        std::cin >> exit[i];
    }

    std::vector<int> intersect(n, -1);

    for (int i = 0; i < n; i++) {
        if (intersect[exit[i] - 1] == -1) {
            intersect[exit[i] - 1] = i;
        } else {
            intersect[exit[i] - 1] = n;
        }
    }

    std::sort(intersect.begin(), intersect.end());

    int maxGroupSize = 1;

    for (int i = 1; i <= n; i++) {
        if (intersect[i] != intersect[i - 1]) {
            maxGroupSize = std::max(maxGroupSize, i);
        }
    }

    std::cout << maxGroupSize << std::endl;

    return 0;
}