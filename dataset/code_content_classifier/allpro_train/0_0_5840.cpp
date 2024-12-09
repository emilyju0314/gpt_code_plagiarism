#include <iostream>
#include <string>

#define MOD 1000000007

int main() {
    int n;
    std::string s;

    std::cin >> n >> s;

    long long count[4] = {0};
    for (int i = 0; i < n; i++) {
        if (s[i] == 'A') {
            count[0]++;
        } else if (s[i] == 'C') {
            count[1]++;
        } else if (s[i] == 'G') {
            count[2]++;
        } else {
            count[3]++;
        }
    }

    long long max_count = 0;
    for (int i = 0; i < 4; i++) {
        max_count = std::max(max_count, count[i]);
    }

    long long result = 0;
    for (int i = 0; i < 4; i++) {
        if (count[i] == max_count) {
            result++;
        }
    }

    long long ans = 1;
    for (int i = 0; i < n; i++) {
        ans = (ans * result) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}