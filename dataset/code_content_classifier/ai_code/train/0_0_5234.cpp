#include <iostream>
#include <string>

int main() {
    std::string results[3];
    for (int i = 0; i < 3; i++) {
        std::cin >> results[i];
    }

    char coins[3] = {'A', 'B', 'C'};

    do {
        bool valid = true;
        for (int i = 0; i < 3; i++) {
            if ((results[i][1] == '>' && coins[results[i][0]-'A'] <= coins[results[i][2]-'A']) ||
                (results[i][1] == '<' && coins[results[i][0]-'A'] >= coins[results[i][2]-'A'])) {
                valid = false;
                break;
            }
        }
        if (valid) {
            for (int i = 0; i < 3; i++) {
                std::cout << coins[i];
            }
            break;
        }
    } while (std::next_permutation(coins, coins+3));

    if (!std::next_permutation(coins, coins+3)) {
        std::cout << "Impossible";
    }

    return 0;
}