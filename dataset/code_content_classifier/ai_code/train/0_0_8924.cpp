#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> sushi(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> sushi[i];
    }

    int countTuna = 0, countEel = 0;
    int maxLen = 0, left = 0;

    for (int right = 0; right < n; ++right) {
        if (sushi[right] == 1) {
            ++countTuna;
        } else {
            ++countEel;
        }

        while (countTuna > 0 && countEel > 0) {
            if (sushi[left] == 1) {
                --countTuna;
            } else {
                --countEel;
            }
            ++left;
        }

        maxLen = std::max(maxLen, right - left + 1);
    }

    std::cout << maxLen << std::endl;

    return 0;
}