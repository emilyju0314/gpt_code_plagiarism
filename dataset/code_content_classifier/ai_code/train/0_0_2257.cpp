#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> slimes(n);
    for (int i = 0; i < n; i++) {
        std::cin >> slimes[i];
    }

    std::sort(slimes.begin(), slimes.end());

    long long result = slimes[n-1];
    for (int i = 0; i < n-1; i++) {
        result += slimes[i];
    }

    std::cout << result << std::endl;

    return 0;
}