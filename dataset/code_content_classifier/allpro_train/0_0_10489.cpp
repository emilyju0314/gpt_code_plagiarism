#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> piles(n);
    for (int i = 0; i < n; i++) {
        std::cin >> piles[i];
    }

    std::sort(piles.begin(), piles.end());

    long long total = 0;
    int same_count = 0;
    for (int i = 0; i < n; i++) {
        total += piles[i];
        if (i > 0 && piles[i] == piles[i-1]) {
            same_count++;
        }
    }

    if (total % 2 == 1 || same_count > 1) {
        std::cout << "cslnb" << std::endl;
    } else {
        std::cout << "sjfnb" << std::endl;
    }

    return 0;
}