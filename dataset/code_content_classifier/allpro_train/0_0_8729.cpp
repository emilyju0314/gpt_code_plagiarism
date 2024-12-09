#include <iostream>
#include <vector>
#include <algorithm>

std::string determinePokerRole(const std::vector<int>& hand) {
    std::sort(hand.begin(), hand.end());

    int num_unique = std::unique(hand.begin(), hand.end()) - hand.begin(); 

    if (num_unique == 5) {
        if ((hand[4] - hand[0]) == 4 || (hand[0] == 1 && hand[4] == 13)) {
            return "straight";
        } else {
            return "null";
        }
    } else if (num_unique == 4) {
        return "one pair";
    } else if (num_unique == 3) {
        if (hand[0] == hand[2] || hand[1] == hand[3] || hand[2] == hand[4]) {
            return "two pair";
        } else {
            return "three card";
        }
    } else if (num_unique == 2) {
        if (hand[1] == hand[3]) {
            return "full house";
        } else {
            return "four card";
        }
    } else {
        return "null";
    }
}

int main() {
    std::string line;
    while (getline(std::cin, line)) {
        std::vector<int> hand;
        size_t pos = 0;
        while ((pos = line.find(",")) != std::string::npos) {
            hand.push_back(std::stoi(line.substr(0, pos)));
            line.erase(0, pos + 1);
        }
        hand.push_back(std::stoi(line));

        std::string role = determinePokerRole(hand);
        std::cout << role << std::endl;
    }

    return 0;
}