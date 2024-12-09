#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 998244353;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> chickens(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> chickens[i];
    }
    
    std::sort(chickens.begin(), chickens.end());

    long long result = 1;
    for (int i = 0; i < N; ++i) {
        result = (result * gcd(chickens[i], i)) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}