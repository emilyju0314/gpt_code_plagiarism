#include <iostream>
#include <vector>
#include <unordered_map>

std::pair<char, int> findWinner(std::vector<char>& votes) {
    std::unordered_map<char, int> count;
    int maxCount = 0;
    char winner = ' ';
    
    for (char vote : votes) {
        count[vote]++;
        if (count[vote] > maxCount) {
            maxCount = count[vote];
            winner = vote;
        }
    }
    
    for (auto& pair : count) {
        if (pair.second == maxCount && pair.first != winner) {
            return {' ', -1};
        }
    }
    
    return {winner, maxCount};
}

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<char> votes(n);
        for (int i = 0; i < n; i++) {
            std::cin >> votes[i];
        }
        auto result = findWinner(votes);
        if (result.second == -1) {
            std::cout << "TIE\n";
        } else {
            std::cout << result.first << " " << result.second << "\n";
        }
    }
    
    return 0;
}