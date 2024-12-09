#include <iostream>
#include <vector>
#include <cmath>

#define MOD 1000000007

std::vector<int> fibonacci = {0, 1};

int fib(int n) {
    if (n >= fibonacci.size()) {
        fibonacci.push_back((fib(n - 1) + fib(n - 2)) % MOD);
    }
    return fibonacci[n];
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A1(N), A2(N);
    for (int i = 0; i < N; i++) {
        std::cin >> A1[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> A2[i];
    }

    for (int i = 0; i < Q; i++) {
        int type, k, l, r, x;
        std::cin >> type >> k >> l >> r;

        if (type == 1) {
            std::cin >> x;
            for (int j = l - 1; j < r; j++) {
                A1[j] = std::min(A1[j], x);
            }
        } else if (type == 2) {
            std::cin >> x;
            for (int j = l - 1; j < r; j++) {
                A1[j] = std::max(A1[j], x);
            }
        } else if (type == 3) {
            std::cin >> x;
            for (int j = l - 1; j < r; j++) {
                A1[j] += x;
            }
        } else if (type == 4) {
            int result = 0;
            for (int j = l - 1; j < r; j++) {
                result += fib(A1[j] + A2[j]);
                result %= MOD;
            }
            std::cout << result << std::endl;
        }
    }

    return 0;
}