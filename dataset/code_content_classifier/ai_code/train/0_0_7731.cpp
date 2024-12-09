#include <iostream>
#include <vector>
#include <algorithm>

bool is_possible(int n, int d, std::vector<int>& cards) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (cards[i] % 10 == d) {
            return true;
        }
        if (cards[i] % 10 == 0) {
            count++;
        }
    }
    if (d == 0 && count > 0) {
        return true;
    }
    return false;
}

int main() {
    int n, d;
    std::cin >> n >> d;

    std::vector<int> cards(n);
    for (int i = 0; i < n; i++) {
        std::cin >> cards[i];
    }

    if (!is_possible(n, d, cards)) {
        std::cout << -1 << std::endl;
        return 0;
    }

    std::vector<int> selected_cards;
    for (int i = 0; i < n; i++) {
        if (cards[i] % 10 == d) {
            selected_cards.push_back(cards[i]);
            std::cout << 1 << std::endl << cards[i] << std::endl;
            return 0;
        }
    }

    int product = 1;
    for (int i = 0; i < n; i++) {
        product *= cards[i];
        product %= 10;
    }

    for (int i = 0; i < n; i++) {
        if (cards[i] % 10 == 0) {
            selected_cards.push_back(cards[i]);
            std::cout << 1 << std::endl << cards[i] << std::endl;
            return 0;
        }
    }

    std::sort(selected_cards.begin(), selected_cards.end(), std::greater<>());
    std::cout << selected_cards.size() << std::endl;
    for (int card : selected_cards) {
        std::cout << card << " ";
    }
    std::cout << std::endl;

    return 0;
}