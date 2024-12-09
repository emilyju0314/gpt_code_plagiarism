#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    long long prettiness = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            prettiness += (gcd(a[i], a[j]) * gcd(i+1, j+1)) % MOD;
            prettiness %= MOD;
        }
    }

    std::cout << prettiness << std::endl;

    return 0;
}