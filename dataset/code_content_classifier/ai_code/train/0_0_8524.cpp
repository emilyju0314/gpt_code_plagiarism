#include <iostream>
#include <map>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string cards;
    std::cin >> cards;

    std::map<char, int> frequency;
    for (char c : cards) {
        frequency[c]++;
    }

    long long coins = 0;
    for (auto it = frequency.rbegin(); it != frequency.rend(); ++it) {
        if (k == 0) {
            break;
        }
        int num_cards = std::min(k, it->second);
        coins += (long long)num_cards * num_cards;
        k -= num_cards;
    }

    std::cout << coins << std::endl;

    return 0;
}