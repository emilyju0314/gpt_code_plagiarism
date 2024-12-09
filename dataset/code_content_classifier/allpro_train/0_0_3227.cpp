#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> coins(n);
    int totalSum = 0;

    for (int i = 0; i < n; i++) {
        std::cin >> coins[i];
        totalSum += coins[i];
    }

    std::sort(coins.begin(), coins.end(), std::greater<int>());

    int mySum = 0, myCoins = 0;

    for (int i = 0; i < n; i++) {
        mySum += coins[i];
        myCoins++;

        if (mySum > totalSum - mySum) {
            break;
        }
    }

    std::cout << myCoins << std::endl;

    return 0;
}