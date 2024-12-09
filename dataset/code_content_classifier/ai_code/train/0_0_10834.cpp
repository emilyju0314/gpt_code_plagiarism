#include <iostream>
#include <vector>

const int MOD = 998244353;

int add(int a, int b) {
    return (a + b) % MOD;
}

int sub(int a, int b) {
    return (a - b + MOD) % MOD;
}

int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}

int modInverse(int a) {
    int b = MOD, u = 0, v = 1;
    while (a != 0) {
        int q = b / a;
        int t = a;
        a = b % a;
        b = t;
        t = u;
        u = v - q * u;
        v = t;
    }
    if (v < 0) v += MOD;
    return v;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<int> likes(n), weights(n);
    for (int i = 0; i < n; i++) {
        std::cin >> likes[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> weights[i];
    }

    int total_likes = 0;
    for (int i = 0; i < n; i++) {
        if (likes[i] == 1) {
            total_likes += weights[i];
        }
    }

    int inv_total_likes = modInverse(total_likes);

    for (int i = 0; i < n; i++) {
        int q_i, p_i;
        if (likes[i] == 1) {
            q_i = add(weights[i], mult(mult(weights[i], m), inv_total_likes));
            p_i = 1;
        } else {
            q_i = sub(weights[i], mult(mult(weights[i], m), inv_total_likes));
            p_i = 1;
        }
        std::cout << modInverse(p_i) * q_i % MOD << std::endl;
    }

    return 0;
}