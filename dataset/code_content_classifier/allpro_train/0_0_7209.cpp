#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

const int MOD = 1000000007;

long long moduloPower(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result * base) % MOD;
        }
        base = (base * base) % MOD;
        exponent /= 2;
    }
    return result;
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        std::cin >> sequence[i];
    }

    std::sort(sequence.begin(), sequence.end());

    std::unordered_set<int> set;
    for (int i = 0; i < n; i++) {
        set.insert(sequence[i]);
    }

    int numUniqueLuckyNumbers = set.size();
    int numLuckySubsequences = moduloPower(2, n) - moduloPower(2, n - numUniqueLuckyNumbers);

    std::cout << numLuckySubsequences << std::endl;

    return 0;
}