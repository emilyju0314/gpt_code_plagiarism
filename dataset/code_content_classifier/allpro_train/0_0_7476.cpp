#include <iostream>
#include <vector>

const int MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> throws(n);
    for (int i = 0; i < n; i++) {
        std::cin >> throws[i];
    }

    long long result = 1;
    int count1 = 0, count2 = 0;

    for (int i = 0; i < n; i++) {
        if (throws[i] == 1) {
            count1++;
        } else {
            count2++;
        }
    }

    for (int i = 1; i <= count1; i++) {
        result = (result * i) % MOD;
    }

    if (count1 > 1) {
        result = (result * ((count1 * (count1 - 1)) / 2) % MOD) % MOD;
    }

    for (int i = 1; i <= count2; i++) {
        result = (result * i) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}