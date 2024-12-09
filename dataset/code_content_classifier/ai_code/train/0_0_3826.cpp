#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

const long long MOD = 998244353;

struct Pipe {
    int x, v, p;
};

int main() {
    int n;
    std::cin >> n;

    std::vector<Pipe> pipes(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> pipes[i].x >> pipes[i].v >> pipes[i].p;
    }

    long long ans = 0;
    for (int i = 1; i < n; ++i) {
        long long time_to_collision = std::abs(pipes[i].x - pipes[i-1].x) * MOD % pipes[i].v;
        long long right_prob = (pipes[i-1].p * (100 - pipes[i].p) + pipes[i].p * (100 - pipes[i-1].p));
        right_prob = right_prob * MOD % 100;

        long long contribution = time_to_collision * right_prob % MOD;
        ans = (ans + contribution) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}