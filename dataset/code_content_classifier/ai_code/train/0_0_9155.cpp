#include <iostream>
#include <vector>

int main() {
    int N, K, Q;
    std::cin >> N >> K >> Q;

    std::vector<int> players(N, K); // Initialize all players with K points

    for (int i = 0; i < Q; i++) {
        int answer;
        std::cin >> answer;
        players[answer - 1]++; // Player who answered correctly gains a point
        for (int j = 0; j < N; j++) {
            if (j != (answer - 1)) {
                players[j]--; // Other players lose one point
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (players[i] > 0) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}