#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    while (std::cin >> n && n != 0) {
        std::vector<int> Taro(n), Hanako(n);
        for (int i = 0; i < n; i++) {
            std::cin >> Taro[i];
        }

        std::sort(Taro.begin(), Taro.end());

        int TaroScore = 0, HanakoScore = 0;
        std::vector<int> cardsInPlay;
        int currentPlayer = 0;

        int i = 0;
        while (i < n) {
            if (cardsInPlay.empty() || Taro[i] > cardsInPlay.back()) {
                cardsInPlay.push_back(Taro[i]);
                i++;
                currentPlayer = 1 - currentPlayer;
            } else {
                if (currentPlayer == 0) {
                    TaroScore++;
                } else {
                    HanakoScore++;
                }
                currentPlayer = 1 - currentPlayer;
            }
        }

        std::cout << TaroScore << std::endl;
        std::cout << HanakoScore << std::endl;
    }
    
    return 0;
}