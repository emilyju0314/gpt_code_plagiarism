#include <iostream>
#include <vector>

const long long MOD = 51123987;

int main() {
    int n;
    std::cin >> n;

    std::string text;
    std::cin >> text;

    std::vector<int> d1(n), d2(n);
    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r) ? 1 : std::min(d1[l + r - i], r - i + 1);
        while (0 <= i - k && i + k < n && text[i - k] == text[i + k]) {
            ++k;
        }
        d1[i] = k--;
        if (i + k > r) {
            l = i - k;
            r = i + k;
        }
    }

    for (int i = 0, l = 0, r = -1; i < n; ++i) {
        int k = (i > r) ? 0 : std::min(d2[l + r - i + 1], r - i + 1);
        while (0 <= i - k - 1 && i + k < n && text[i - k - 1] == text[i + k]) {
            ++k;
        }
        d2[i] = k--;
        if (i + k > r) {
            l = i - k - 1;
            r = i + k;
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = (ans + d1[i] + d2[i]) % MOD;
    }

    std::cout << ans << std::endl;

    return 0;
}