#include <iostream>
#include <string>
#include <vector>

bool canBePalindrome(std::string s) {
    int n = s.size();
    for (int i = 0; i < n/2; i++) {
        if (abs(s[i] - s[n - i - 1]) > 2 || abs(s[i] - s[n - i - 1]) == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int T;
    std::cin >> T;

    std::vector<std::string> results;

    for (int t = 0; t < T; t++) {
        int n;
        std::string s;
        std::cin >> n >> s;

        if (canBePalindrome(s)) {
            results.push_back("YES");
        } else {
            results.push_back("NO");
        }
    }

    for (const std::string& res : results) {
        std::cout << res << std::endl;
    }

    return 0;
}