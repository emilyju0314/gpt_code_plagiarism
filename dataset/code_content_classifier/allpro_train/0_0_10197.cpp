#include <iostream>

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int K;
    std::cin >> K;

    long long ans = 0;

    for (int a = 1; a <= K; a++) {
        for (int b = 1; b <= K; b++) {
            for (int c = 1; c <= K; c++) {
                int g = gcd(a, gcd(b, c));
                ans += g;
            }
        }
    }

    std::cout << ans << std::endl;

    return 0;
}