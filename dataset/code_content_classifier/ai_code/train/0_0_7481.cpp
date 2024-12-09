#include <iostream>
#include <vector>
#include <algorithm>

const int MOD = 1000000007;

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;

    std::vector<int> l, r;
    int len_l, len_r;
    std::cin >> len_l;
    for(int i = 0; i < len_l; i++) {
        int digit;
        std::cin >> digit;
        l.push_back(digit);
    }
    std::cin >> len_r;
    for(int i = 0; i < len_r; i++) {
        int digit;
        std::cin >> digit;
        r.push_back(digit);
    }

    // Convert l and r to decimal numbers
    int l_decimal = 0;
    int r_decimal = 0;
    for(int i = 0; i < l.size(); i++) {
        l_decimal = l_decimal * m + l[i];
    }
    for(int i = 0; i < r.size(); i++) {
        r_decimal = r_decimal * m + r[i];
    }

    // Calculate the number of Mapo Tofu pieces
    std::vector<std::pair<std::vector<int>, int>> tofu_values;
    for(int i = 0; i < n; i++) {
        std::vector<int> tofu_number;
        int value;
        int len;
        std::cin >> len;
        for(int j = 0; j < len; j++) {
            int digit;
            std::cin >> digit;
            tofu_number.push_back(digit);
        }
        std::cin >> value;
        tofu_values.push_back(std::make_pair(tofu_number, value));
    }

    int count = 0;
    for(int num = l_decimal; num <= r_decimal; num++) {
        int value = 0;
        for(auto& tofu : tofu_values) {
            int string_num = 0;
            for(int i = 0; i < tofu.first.size(); i++) {
                string_num = string_num * m + tofu.first[i];
            }
            if(string_num == num) {
                value += tofu.second;
            }
        }
        if(value <= k) {
            count++;
        }
    }

    std::cout << count % MOD << std::endl;

    return 0;
}