#include <iostream>
#include <vector>
#include <unordered_map>

bool canArrangeInOneRow(std::vector<std::pair<int, int>>& dominoes) {
    std::unordered_map<int, int> freq;
    for (auto [a, b] : dominoes) {
        freq[a]++;
        if (a != b) {
            freq[b]++;
        }
    }

    for (auto [key, value] : freq) {
        if (value % 2 != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int numPairs;
    std::cin >> numPairs;

    for (int i = 0; i < numPairs; i++) {
        int N;
        std::cin >> N;
        std::vector<std::pair<int, int>> dominoes(N);
        for (int j = 0; j < N; j++) {
            std::string domino;
            std::cin >> domino;
            dominoes[j] = {domino[0] - '0', domino[1] - '0'};
        }

        if (canArrangeInOneRow(dominoes)) {
            std::cout << "Yes" << std::endl;
        } else {
            std::cout << "No" << std::endl;
        }
    }

    return 0;
}