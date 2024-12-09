#include <iostream>

// Function to check if player Karlsson wins
bool karlssonWins(const std::string& state) {
    for (int i = 0; i < state.size(); i++) {
        if (state[i] == 'O') {
            std::string newState = state;
            newState[i] = '.';

            // Try eating the chocolates in neighboring cells
            for (int j = i - 2; j <= i + 2; j++) {
                if (j >= 0 && j < state.size() && state[j] == 'O') {
                    newState[j] = '.';
                }
            }

            // Recursively check if Lillebror loses
            if (!karlssonWins(newState)) {
                return true;
            }
        }
    }
    
    return false;
}

int main() {
    std::string state;
    for (int i = 0; i < 5; i++) {
        std::string line;
        std::cin >> line;
        state += line;
    }

    if (karlssonWins(state)) {
        std::cout << "Karlsson" << std::endl;
    } else {
        std::cout << "Lillebror" << std::endl;
    }

    return 0;
}