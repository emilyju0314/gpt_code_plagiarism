#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int Fibonacci(int n) {
    int a = 0, b = 1;
    while (n-- > 0) {
        int temp = a;
        a = b;
        b = (temp + b) % MOD;
    }
    return a;
}

int SumFibonacci(int a, int b) {
    return (Fibonacci(a) + Fibonacci(b)) % MOD;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A1(N), A2(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A1[i];
    }
    for (int i = 0; i < N; ++i) {
        std::cin >> A2[i];
    }

    for (int q = 0; q < Q; ++q) {
        int type, k, l, r, x;
        std::cin >> type;
        
        if (type == 1 || type == 2) {
            std::cin >> k >> l >> r >> x;
            for (int i = l - 1; i < r; ++i) {
                if (type == 1) {
                    A1[i] = std::min(A1[i], x);
                    A2[i] = std::min(A2[i], x);
                } else {
                    A1[i] = std::max(A1[i], x);
                    A2[i] = std::max(A2[i], x);
                }
            }
        } else if (type == 3) {
            std::cin >> k >> l >> r >> x;
            for (int i = l - 1; i < r; ++i) {
                A1[i] = (A1[i] + x) % MOD;
                A2[i] = (A2[i] + x) % MOD;
            }
        } else {
            std::cin >> l >> r;
            int result = 0;
            for (int i = l - 1; i < r; ++i) {
                result = (result + SumFibonacci(A1[i], A2[i])) % MOD;
            }
            std::cout << result << std::endl;
        }
    }

    return 0;
}