#include <iostream>
#include <vector>
#include <unordered_map>

bool canWin(const std::vector<int>& field, const std::vector<int>& cards) {
    std::unordered_map<int, int> remainingCards;
    for (int cardNum : cards) {
        remainingCards[cardNum]++;
    }

    int nextCard = field.back() + 1;
    while (remainingCards.find(nextCard) != remainingCards.end()) {
        if (remainingCards[nextCard] > 0) {
            remainingCards[nextCard]--;
            field.push_back(nextCard);
            nextCard++;
        } else {
            break;
        }
    }

    if (field.size() == 7) {
        return true;
    }
    return false;
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        std::vector<int> field(1);
        std::cin >> field[0];
        std::vector<int> cards(6);
        for (int j = 0; j < 6; j++) {
            std::cin >> cards[j];
        }

        if (canWin(field, cards)) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    }

    return 0;
}