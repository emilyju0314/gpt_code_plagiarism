#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N;

    while (std::cin >> N && N != 0) {
        std::string cards;
        std::cin >> cards;

        std::vector<int> participantCards(N);
        std::vector<int> fieldCards;

        for (int i = 0; i < 100; i++) {
            int participantIndex = i % N;

            if (cards[i] == 'M') {
                participantCards[participantIndex]++;
            } else if (cards[i] == 'S') {
                fieldCards.insert(fieldCards.end(), participantCards[participantIndex] + 1, participantCards[participantIndex]);
                participantCards[participantIndex] = 0;
            } else if (cards[i] == 'L') {
                participantCards[participantIndex] += fieldCards.size() + 1;
                fieldCards.clear();
            }
        }

        std::sort(participantCards.begin(), participantCards.end());

        for (int i = 0; i < N; i++) {
            std::cout << participantCards[i] << " ";
        }
        std::cout << fieldCards.size() << std::endl;
    }

    return 0;
}