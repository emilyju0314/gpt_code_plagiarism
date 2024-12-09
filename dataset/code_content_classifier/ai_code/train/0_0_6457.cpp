#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> piles(n);
    for(int i = 0; i < n; i++) {
        std::cin >> piles[i];
    }

    std::sort(piles.begin(), piles.end());

    // Determine if Jon can win the game by checking if the number of odd piles is even
    int odd_piles = 0;
    for(int i = 0; i < n; i++) {
        if(piles[i] % 2 != 0) {
            odd_piles++;
        }
    }

    if(odd_piles % 2 == 0) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
    }

    return 0;
}