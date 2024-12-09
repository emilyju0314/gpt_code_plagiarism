#include <iostream>
#include <vector>

bool canWin(const std::vector<int>& numbers) {
    int n = numbers.size();

    // If the length of the list is odd, Shikamaru will always win
    if (n % 2 == 1) {
        return true;
    }

    // If the length of the list is even, Asuma can mirror Shikamaru's moves
    // and win the game
    return false;
}

int main() {
    int n;
    std::cin >> n;

    bool shikamaruWins = true;
    for (int i = 0; i < n; i++) {
        int m;
        std::cin >> m;

        std::vector<int> numbers(m);
        for (int j = 0; j < m; j++) {
            std::cin >> numbers[j];
        }

        shikamaruWins = shikamaruWins && canWin(numbers);
    }

    if (shikamaruWins) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}