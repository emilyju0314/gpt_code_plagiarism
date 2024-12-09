#include <iostream>
#include <vector>

// Function to calculate the number of ways to pay a given amount using coins of Silverland
int countWays(int amount) {
    std::vector<int> dp(amount + 1, 0);
    dp[0] = 1;

    // Possible coin values
    std::vector<int> coins = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144, 169, 196, 225, 256, 289};

    // Calculate the number of ways for each coin value
    for (int coin : coins) {
        for (int i = coin; i <= amount; i++) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[amount];
}

int main() {
    int amount;
    while (std::cin >> amount && amount != 0) {
        int ways = countWays(amount);
        std::cout << ways << std::endl;
    }

    return 0;
}