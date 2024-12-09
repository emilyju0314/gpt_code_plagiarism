#include <iostream>
#include <string>

int main() {
    std::string deck;
    int m;

    while (std::cin >> deck) {
        if (deck == "-") {
            break; // end of input
        }

        std::cin >> m;

        for (int i = 0; i < m; ++i) {
            int h;
            std::cin >> h;

            std::string bottom = deck.substr(0, h);
            std::string top = deck.substr(h);
            deck = top + bottom;
        }

        std::cout << deck << std::endl;
    }

    return 0;
}