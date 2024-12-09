#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

#define MOD 998244353

// Function to calculate the modular inverse
long long modInverse(long long a, long long m)
{
    long long m0 = m, t, q;
    long long x0 = 0, x1 = 1;

    if (m == 1)
        return 0;

    // Apply extended Euclid Algorithm
    while (a > 1)
    {
        q = a / m;
        t = m;

        m = a % m;
        a = t;
        t = x0;

        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0)
        x1 += m0;

    return x1;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> monsterStrengths(n);
    for (int i = 0; i < n; i++) {
        std::cin >> monsterStrengths[i];
    }

    std::vector<std::pair<int, int>> shields(m);
    for (int i = 0; i < m; i++) {
        std::cin >> shields[i].first >> shields[i].second;
    }

    std::sort(monsterStrengths.begin(), monsterStrengths.end());

    for (int i = 0; i < m; i++) {
        int a = shields[i].first;
        int b = shields[i].second;

        long long numerator = 0;
        long long denominator = 0;

        // Calculate the expected damage
        for (int j = 0; j < n; j++) {
            if (monsterStrengths[j] >= b) {
                numerator = (numerator + (denominator * monsterStrengths[j]) % MOD) % MOD;
                denominator++;
            } else if (a > 0) {
                a--;
            } else {
                numerator = (numerator + monsterStrengths[j]) % MOD;
            }
        }

        // Calculate the modular inverse of denominator
        long long inv = modInverse(denominator, MOD);

        // Calculate the final expected damage
        long long result = (numerator * inv) % MOD;
        std::cout << result << std::endl;
    }

    return 0;
}