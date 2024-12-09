#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;

        std::unordered_set<int> card;
        for (int j = 0; j < m; j++) {
            int num;
            std::cin >> num;
            card.insert(num);
        }

        bool can_win = true;
        for (int j = 1; j <= 100; j++) {
            if (card.find(j) == card.end()) {
                can_win = false;
                break;
            }
        }

        if (can_win) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}