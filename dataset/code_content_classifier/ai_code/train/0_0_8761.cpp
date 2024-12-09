#include <iostream>
#include <string>
#include <set>

void simulateGame(std::string cards, std::set<std::string>& outcomes) {
    // Simulate the game until only two cards are left
    while (cards.size() > 2) {
        // Remove a card based on Masha's strategy (always remove the leftmost card)
        for (int i = 0; i < cards.size(); i++) {
            if (cards[i] == '1' || (cards[i] == '?' && (i == 0 || cards[i-1] == '0'))) {
                cards.erase(cards.begin() + i);
                break;
            }
        }

        // Shift cards to close the gap
        for (char& c : cards) {
            if (c == '?') c = '0';
        }
    }

    // Add the outcome to the set
    outcomes.insert(cards);
}

int main() {
    std::string initial;
    std::cin >> initial;

    std::set<std::string> outcomes;

    // Replace "?" with both "0" and "1" to consider all possible initial arrangements
    for (int i = 0; i < initial.size(); i++) {
        if (initial[i] == '?') {
            std::string variant = initial;
            variant[i] = '0';
            simulateGame(variant, outcomes);
            
            variant = initial;
            variant[i] = '1';
            simulateGame(variant, outcomes);
        }
    }

    // Print the outcomes in sorted order
    for (const std::string& outcome : outcomes) {
        std::cout << outcome << "\n";
    }

    return 0;
}