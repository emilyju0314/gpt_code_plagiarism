#include <iostream>
#include <unordered_set>

int main() {
    int n;
    std::unordered_set<std::string> cards;

    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::string card;
        std::cin >> card;
        cards.insert(card);
    }

    int min_hints = 0;
    for (char color = 'R'; color <= 'W'; color++) {
        std::unordered_set<char> values;
        for (int i = 1; i <= 5; i++) {
            bool contains = false;
            for (const std::string& card : cards) {
                if (card[0] == color && card[1] == '0' + i) {
                    contains = true;
                    break;
                }
            }
            if (contains) {
                values.insert('0' + i);
            }
        }
        min_hints += values.size() > 0 ? 1 : 0;
    }

    std::cout << min_hints << std::endl;

    return 0;
}