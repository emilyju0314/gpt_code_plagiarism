#include <iostream>
#include <vector>
#include <algorithm>

const long long MOD = 1000000007;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> computers(n);
    for (int i = 0; i < n; i++) {
        std::cin >> computers[i];
    }

    std::sort(computers.begin(), computers.end());

    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long contribution = (long long)computers[i] * (i + 1) * (n - i);
        result = (result + contribution) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}