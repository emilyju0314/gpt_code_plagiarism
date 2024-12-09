#include <iostream>
#include <string>
#include <algorithm>

std::string lexicographicallyLargestPalindromicSubsequence(std::string s) {
    int n = s.length();
    std::string ans = "";
    
    for(int i = 0; i < n; i++) {
        if(s[i] > s[n-1-i]) {
            ans += s[i];
        } else {
            ans += s[n-1-i];
        }
    }
    
    return ans;
}

int main() {
    std::string s;
    std::cin >> s;

    std::string result = lexicographicallyLargestPalindromicSubsequence(s);
    std::cout << result << std::endl;

    return 0;
}