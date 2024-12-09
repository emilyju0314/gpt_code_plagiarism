#include <iostream>
#include <vector>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> x(n), v(n), p(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i] >> v[i] >> p[i];
    }

    long long expected_duration = 0;
    long long total_pairs = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((x[i] < x[j] && p[i] > p[j]) || (x[i] > x[j] && p[i] < p[j])) {
                long long time_to_collision = (long long)(x[j] - x[i]) * (p[i] + p[j]);
                expected_duration = (expected_duration + time_to_collision) % MOD;
                total_pairs++;
            }
        }
    }

    if (total_pairs == 0) {
        std::cout << 0 << std::endl;
    } else {
        long long inverse_total_pairs = 1;
        for (int i = 0; i < total_pairs - 1; i++) {
            inverse_total_pairs = (inverse_total_pairs * 499122177) % MOD;
        }

        long long answer = (expected_duration * inverse_total_pairs) % MOD;
        std::cout << answer << std::endl;
    }

    return 0;
}