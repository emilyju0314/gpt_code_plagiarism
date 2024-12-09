#include <iostream>
#include <string>
#include <unordered_set>

int findMinUniqueCommonSubstring(const std::string& s1, const std::string& s2) {
    int minLen = std::min(s1.length(), s2.length());
    std::unordered_set<std::string> substrings1;

    for(int len = minLen; len > 0; len--) {
        for(int i = 0; i + len <= s1.length(); i++) {
            std::string substring = s1.substr(i, len);
            substrings1.insert(substring);
        }
    }

    minLen = std::min(minLen, (int)s2.length());
    
    for(int len = minLen; len > 0; len--) {
        for(int i = 0; i + len <= s2.length(); i++) {
            std::string substring = s2.substr(i, len);
            if(substrings1.count(substring) == 1) {
                return len;
            }
        }
    }

    return -1;
}

int main() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    int result = findMinUniqueCommonSubstring(s1, s2);
    std::cout << result << std::endl;

    return 0;
}