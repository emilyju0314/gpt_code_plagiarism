#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> powers;
    int currentPower = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            powers.push_back(currentPower);
        }
        n /= 2;
        currentPower *= 2;
    }

    if (powers.size() > k) {
        std::cout << "NO" << std::endl;
    } else {
        std::cout << "YES" << std::endl;
        int remainingPowers = k - powers.size();
        for (int i = 0; i < powers.size(); i++) {
            std::cout << powers[i] << " ";
        }
        for (int i = 0; i < remainingPowers; i++) {
            if (i == remainingPowers - 1) {
                std::cout << currentPower << std::endl;
            } else {
                std::cout << currentPower << " ";
            }
            currentPower *= 2;
        }
    }

    return 0;
}