#include <iostream>
#include <algorithm>

bool isSubsequence(const std::string& s, const std::string& t) {
    int j = 0;
    for (int i = 0; i < t.length() && j < s.length(); i++) {
        if (s[j] == t[i]) {
            j++;
        }
    }
    return j == s.length();
}

int longestUncommonSubsequenceLength(std::string a, std::string b) {
    if (a == b) {
        return -1;
    }
    return std::max(a.length(), b.length());
}

int main() {
    std::string a, b;
    std::cin >> a >> b;

    int result = longestUncommonSubsequenceLength(a, b);

    std::cout << result << std::endl;

    return 0;
}