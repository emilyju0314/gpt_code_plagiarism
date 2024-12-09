#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int T;
    std::cin >> T;

    while (T--) {
        int n;
        std::cin >> n;

        std::string red, blue;
        std::cin >> red >> blue;

        int n_R = 0, n_B = 0;
        std::vector<int> cards(n);
        for (int i = 0; i < n; i++) {
            cards[i] = i + 1;
        }

        do {
            int R = 0, B = 0;
            for (int i = 0; i < n; i++) {
                R = 10 * R + red[cards[i] - 1] - '0';
                B = 10 * B + blue[cards[i] - 1] - '0';
            }

            if (R > B) {
                n_R++;
            } else if (B > R) {
                n_B++;
            }
        } while (std::next_permutation(cards.begin(), cards.end()));

        if (n_R > n_B) {
            std::cout << "RED" << std::endl;
        } else if (n_B > n_R) {
            std::cout << "BLUE" << std::endl;
        } else {
            std::cout << "EQUAL" << std::endl;
        }
    }

    return 0;
}