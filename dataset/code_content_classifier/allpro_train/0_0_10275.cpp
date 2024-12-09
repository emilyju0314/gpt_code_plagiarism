#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> ratings(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> ratings[i];
    }

    std::sort(ratings.begin(), ratings.end());

    bool possible = true;
    for (int i = 0; i < n; i++) {
        if (ratings[i] >= ratings[i + n]) {
            possible = false;
            break;
        }
    }

    if (possible) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}