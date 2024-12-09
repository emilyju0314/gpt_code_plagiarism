#include <iostream>
#include <vector>

#define MOD 998244353

int main() {
    int n;
    std::cin >> n;

    std::vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long prev = 0, curr = 1;
    for (int i = 0; i < n; i++) {
        long long temp = curr;
        curr = (curr * (a[i] - 1 - prev)) % MOD;
        prev = temp;
    }

    std::cout << curr << std::endl;

    return 0;
}