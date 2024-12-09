#include <iostream>
#include <string>
#include <set>

int main() {
    std::string tableCard, handCard;
    std::set<char> handRanks, handSuits;

    std::cin >> tableCard;

    for (int i = 0; i < 5; i++) {
        std::cin >> handCard;
        handRanks.insert(handCard[0]);
        handSuits.insert(handCard[1]);
    }

    if (handRanks.count(tableCard[0]) > 0 || handSuits.count(tableCard[1]) > 0) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}