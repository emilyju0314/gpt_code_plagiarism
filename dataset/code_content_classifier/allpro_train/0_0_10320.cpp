#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        int n, k1, k2;
        std::cin >> n >> k1 >> k2;

        std::vector<int> player1(k1);
        std::vector<int> player2(k2);

        for (int i = 0; i < k1; i++) {
            std::cin >> player1[i];
        }

        for (int i = 0; i < k2; i++) {
            std::cin >> player2[i];
        }

        sort(player1.begin(), player1.end());
        sort(player2.begin(), player2.end());

        if (player1.back() > player2.back()) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}