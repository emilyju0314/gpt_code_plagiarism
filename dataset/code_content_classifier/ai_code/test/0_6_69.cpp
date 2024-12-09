#include <iostream>
#include <vector>

const int MOD = 1e9 + 7;

int fibonacci(int n) {
    if(n == 0) return 0;
    if(n == 1) return 1;
    int a = 0, b = 1, c;
    for(int i = 2; i <= n; i++) {
        c = (a + b) % MOD;
        a = b;
        b = c;
    }
    return b;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A1(N), A2(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A1[i];
    }
    for(int i = 0; i < N; i++) {
        std::cin >> A2[i];
    }

    for(int q = 0; q < Q; q++) {
        int type, k, l, r, x;
        std::cin >> type;
        if(type == 4) {
            std::cin >> l >> r;
            int result = 0;
            for(int i = l-1; i < r; i++) {
                result = (result + fibonacci(A1[i] + A2[i])) % MOD;
            }
            std::cout << result << std::endl;
        } else {
            std::cin >> k >> l >> r >> x;
            for(int i = l-1; i < r; i++) {
                if(type == 1) {
                    A1[i] = std::min(A1[i], x);
                } else if(type == 2) {
                    A1[i] = std::max(A1[i], x);
                } else if(type == 3) {
                    A1[i] = (A1[i] + x) % MOD;
                }
            }
        }
    }

    return 0;
}