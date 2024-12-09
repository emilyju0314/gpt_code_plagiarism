#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

bool isPalindrome(const std::string& s) {
    int left = 0, right = s.length() - 1;
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

long long factorial(int n) {
    if(n <= 1) {
        return 1;
    }
    return n * factorial(n-1);
}

int main() {
    std::string s;
    std::cin >> s;
    
    std::unordered_map<char, int> charCount;
    for(char c : s) {
        charCount[c]++;
    }
    
    int oddCount = 0;
    for(const auto& p : charCount) {
        if(p.second % 2 != 0) {
            oddCount++;
        }
    }
    
    if(oddCount > 1) {
        std::cout << 0 << std::endl;
        return 0;
    }
    
    int n = s.length();
    long long ans = factorial(n / 2);
    for(const auto& p : charCount) {
        ans /= factorial(p.second / 2);
    }
    
    if(oddCount == 1) {
        ans *= (n / 2 + 1);
    }
    
    std::cout << ans << std::endl;
    
    return 0;
}