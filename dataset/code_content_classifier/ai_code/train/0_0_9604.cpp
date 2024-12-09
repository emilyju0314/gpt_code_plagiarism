#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> cards(N);
    for (int i = 0; i < N; i++) {
        std::cin >> cards[i];
    }

    std::sort(cards.begin(), cards.end()); // Sort the cards in ascending order

    for (int i = 0; i < Q; i++) {
        int question;
        std::cin >> question;

        auto it = std::upper_bound(cards.begin(), cards.end(), question); // Find the upper bound of the question in the sorted cards
        int max_remainder = *std::prev(it) % question; // Get the largest remainder

        std::cout << max_remainder << std::endl;
    }

    return 0;
}