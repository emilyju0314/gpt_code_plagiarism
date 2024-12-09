#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int charToNum(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'a' + 10;
    }
}

char numToChar(int num) {
    if (num < 10) {
        return num + '0';
    } else {
        return num - 10 + 'a';
    }
}

int main() {
    std::string S;
    std::cin >> S;
    
    int len = S.size();
    std::vector<int> digits(len);
    for (int i = 0; i < len; i++) {
        digits[i] = charToNum(S[i]);
    }
    
    std::sort(digits.begin(), digits.end());
    
    std::vector<int> original(len), copied(len);
    int sum = 0;
    for (int i = 0; i < len; i++) {
        original[i] = digits[i];
        sum += digits[i];
    }
    
    if (original[0] == 0) {
        // Find the smallest non-zero value for the most significant digit
        for (int i = 1; i < 16; i++) {
            if (sum - original[0] + i <= 15) {
                original[0] = i;
                break;
            }
        }
    } else {
        // Check if sum of digits is valid
        if (sum < 16) {
            std::string ans;
            for (int i = 0; i < len; i++) {
                ans += numToChar(original[i]);
            }
            std::cout << ans << std::endl;
            return 0;
        }
    }
    
    std::cout << "NO" << std::endl;
    
    return 0;
}