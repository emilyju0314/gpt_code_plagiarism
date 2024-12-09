#include <iostream>
#include <vector>
#include <unordered_map>

long long f(long long x) {
    if (x % 2 == 0) {
        return x / 2;
    } else {
        return x - 1;
    }
}

int main() {
    long long n, k;
    std::cin >> n >> k;

    std::unordered_map<long long, int> countMap;

    for (long long x = 1; x <= n; x++) {
        long long value = x;
        while (value != 1) {
            countMap[value]++;
            value = f(value);
        }
        countMap[1]++;
    }

    long long maxVal = 0;
    for (auto entry : countMap) {
        if (entry.second >= k) {
            maxVal = std::max(maxVal, entry.first);
        }
    }

    std::cout << maxVal << std::endl;

    return 0;
}