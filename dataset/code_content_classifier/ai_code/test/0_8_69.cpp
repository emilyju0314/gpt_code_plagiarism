#include <iostream>
#include <vector>
#define MOD 1000000007

int F(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return (F(k-1) + F(k-2)) % MOD;
}

int main() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::vector<int> A1(N);
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        A1[i] = val;
    }
    
    std::vector<int> A2(N);
    for (int i = 0; i < N; i++) {
        int val;
        std::cin >> val;
        A2[i] = val;
    }
    
    for (int q = 0; q < Q; q++) {
        int type;
        std::cin >> type;
        
        if (type == 4) {
            int l, r;
            std::cin >> l >> r;
            int total = 0;
            for (int i = l-1; i < r; i++) {
                total = (total + F(A1[i] + A2[i])) % MOD;
            }
            std::cout << total << std::endl;
        } else {
            int k, l, r, x;
            std::cin >> k >> l >> r >> x;

            if (k == 1) {
                for (int i = l-1; i < r; i++) {
                    A1[i] = std::min(A1[i], x);
                }
            } else if (k == 2) {
                for (int i = l-1; i < r; i++) {
                    A1[i] = std::max(A1[i], x);
                }
            } else {
                for (int i = l-1; i < r; i++) {
                    A1[i] = (A1[i] + x) % MOD;
                }
            }
        }
    }
    
    return 0;
}