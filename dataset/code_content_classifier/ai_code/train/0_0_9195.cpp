#include <iostream>
#include <string>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string s;
        std::cin >> s;

        int left = 0, right = 0;
        for (char c : s) {
            if (c == 'L') left++;
            else right++;
        }

        int ans = std::max(left, right) + 1;
        std::cout << ans << std::endl;
    }

    return 0;
}