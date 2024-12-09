#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

const int MOD = 998244353;

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> strings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }

    int len = strings.size();
    std::unordered_map<std::string, int> subsequence_count;

    for (int mask = 1; mask < (1 << n); ++mask) {
        std::string subsequence;
        int sum_indices = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                subsequence += strings[i];
                sum_indices += i + 1;
            }
        }

        std::string unique_subsequence;
        std::vector<bool> taken(26, false);

        for (char ch : subsequence) {
            if (!taken[ch - 'a']) {
                unique_subsequence += ch;
                taken[ch - 'a'] = true;
            }
        }

        subsequence_count[unique_subsequence]++;
    }

    int result = 0;
    for (auto const& it : subsequence_count) {
        int k = it.first.size();
        int f_val = it.second % MOD;
        int x_val = k * it.first.size();
        result ^= (f_val * x_val) % MOD;
    }

    std::cout << result << std::endl;

    return 0;
}