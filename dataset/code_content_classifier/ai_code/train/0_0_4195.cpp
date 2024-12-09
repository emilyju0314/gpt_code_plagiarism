#include <iostream>
#include <vector>
#include <string>
#include <cmath>

const int MOD = 1000000007;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> l, r;
    int len;
    std::cin >> len;
    l.resize(len);
    for(int i = 0; i < len; i++) {
        std::cin >> l[i];
    }

    std::cin >> len;
    r.resize(len);
    for (int i = 0; i < len; i++) {
        std::cin >> r[i];
    }

    int max_length = (int)log10(r.size()) + 1;

    std::vector<int> values(n);
    std::vector<std::string> strings(n);
    for(int i = 0; i < n; i++) {
        std::cin >> len;
        strings[i] = "";
        for (int j = 0; j < max_length - len; j++) {
            strings[i] += '0';
        }
        for(int j = 0; j < len; j++) {
            int digit;
            std::cin >> digit;
            strings[i] += std::to_string(digit);
        }
        std::cin >> values[i];
    }

    int ans = 0;

    for (int i = 0; i < r.size(); i++) {
        std::string num = "";
        for(int j = 0; j < max_length - r.size(); j++) {
            num += '0';
        }
        num += std::to_string(i);

        int num_value = 0;
        for (int j = 0; j < n; j++) {
            std::size_t found = num.find(strings[j]);
            while (found != std::string::npos) {
                num_value += values[j];
                found = num.find(strings[j], found + 1);
            }
        }

        if(num_value <= k) {
            ans++;
        }
    }

    std::cout << ans % MOD << std::endl;

    return 0;
}