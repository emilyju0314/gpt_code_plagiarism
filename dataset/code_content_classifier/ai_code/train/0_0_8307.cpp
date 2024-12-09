#include <iostream>

int main() {
    int payment;
    while (true) {
        std::cin >> payment;
        if (payment == 0) {
            break;
        }

        int coins[4];
        for (int i = 0; i < 4; i++) {
            std::cin >> coins[i];
        }

        int change = 500 - payment;
        int coin_types[] = {10, 50, 100, 500};

        bool first = true;
        for (int i = 3; i >= 0; i--) {
            while (coins[i] > 0 && change >= coin_types[i]) {
                if (!first) {
                    std::cout << std::endl;
                }
                std::cout << coin_types[i] << " 1";
                coins[i]--;
                first = false;
                change -= coin_types[i];
            }
        }
        
        if (!first) {
            std::cout << std::endl;
        }
    }

    return 0;
}