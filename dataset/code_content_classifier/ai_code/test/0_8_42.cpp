#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

const int MOD = 1e9 + 7;

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i] >> b[i];
    }

    int t;
    std::cin >> t;

    std::vector<int> s(t);
    for (int i = 0; i < t; i++) {
        std::cin >> s[i];
    }

    std::unordered_map<int, int> complete;
    int total_complete = 0;
    long long time_travel = 0;

    for (int i = 0; i < n; i++) {
        if (complete[s[0]] == 0) {
            complete[s[0]] = 1;
            total_complete++;
        }

        if (total_complete == t) {
            time_travel = b[i];
            break;
        }

        if (complete[a[i]] == 0) {
            complete[a[i]] = 1;
            total_complete++;
        }
    }

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans += (time_travel - b[i] + MOD) % MOD;
        time_travel = (time_travel + (a[i] - b[i]) + MOD) % MOD;
    }

    std::cout << ans % MOD << std::endl;

    return 0;
}