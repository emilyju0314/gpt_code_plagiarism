#include <iostream>
#include <string>
#include <vector>

bool isGoodSubsequence(const std::string& s, int l, int r) {
    char c1 = s[l-1];
    char c2 = s[r-1];
    if (c1 == c2) {
        return false;
    }
    return true;
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i) {
        int n, q;
        std::cin >> n >> q;

        std::string s;
        std::cin >> s;

        for (int j = 0; j < q; ++j) {
            int l, r;
            std::cin >> l >> r;

            if (isGoodSubsequence(s, l, r)) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }

    return 0;
}