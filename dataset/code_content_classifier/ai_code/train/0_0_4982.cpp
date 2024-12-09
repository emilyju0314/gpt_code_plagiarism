#include<iostream>
#include<vector>
#include<algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::pair<int, int>> cards;
    for(int i = 0; i < n; i++) {
        int card;
        std::cin >> card;
        cards.push_back(std::make_pair(card, i+1));
    }

    std::sort(cards.begin(), cards.end());

    for(int i = 0; i < n/2; i++) {
        std::cout << cards[i].second << " " << cards[n-i-1].second << std::endl;
    }

    return 0;
}