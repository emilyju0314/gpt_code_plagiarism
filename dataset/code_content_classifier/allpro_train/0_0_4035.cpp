#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::vector<int> breaks;

    breaks.push_back(0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            breaks.push_back(i+1);
        }
    }
    breaks.push_back(n+1);

    int l = 0, r = n+1;
    while (l < r-1) {
        int m = (l + r) / 2;
        int cnt = 0;
        for (size_t i = 0; i < breaks.size()-1; ++i) {
            cnt += (breaks[i+1] - breaks[i] - 1) / m;
        }

        if (cnt <= k) {
            r = m;
        } else {
            l = m;
        }
    }

    std::cout << r - 1 << std::endl;

    return 0;
}