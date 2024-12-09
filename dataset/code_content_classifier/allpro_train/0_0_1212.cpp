#include <iostream>
#include <vector>

int getCardValue(char card) {
    if (card == 'A') {
        return 11; // Ace can be 11 or 1, but we'll start with 11
    } else if (card == 'T' || card == 'J' || card == 'Q' || card == 'K') {
        return 10;
    } else {
        return card - '0'; // Converts char to int
    }
}

int main() {
    int N;
    std::cin >> N;

    for (int i = 0; i < N; i++) {
        char dealerCard1, dealerCard2;
        std::cin >> dealerCard1 >> dealerCard2;

        int dealerScore = getCardValue(dealerCard1) + getCardValue(dealerCard2);

        if (dealerScore == 21) {
            std::cout << "blackjack" << std::endl;
            continue;
        }

        std::vector<char> pile(8);
        for (int j = 0; j < 8; j++) {
            std::cin >> pile[j];
        }

        for (int j = 0; j < 8; j++) {
            int value = getCardValue(pile[j]);
            dealerScore += value;

            if (dealerScore == 21) {
                std::cout << "blackjack" << std::endl;
                break;
            } else if (dealerScore > 21) {
                std::cout << "bust" << std::endl;
                break;
            } else if (j == 7) {
                std::cout << dealerScore << std::endl;
            }

            if (dealerScore >= 17) {
                break;
            } else if (dealerScore > 16 && dealerCard1 == 'A') {
                dealerCard1 = ' '; // to indicate that the Ace was counted as 1
                dealerScore -= 10; // change Ace from 11 to 1
            }
        }
    }

    return 0;
}