#include <iostream>

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    std::cin >> n;

    long long sum = 0;
    for (int u = 1; u <= n; u++) {
        for (int v = u + 1; v <= n; v++) {
            long long dist = gcd(u, v) + 1;
            sum += dist;
        }
    }

    std::cout << sum << std::endl;

    return 0;
}