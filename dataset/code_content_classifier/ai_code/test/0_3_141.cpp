#include <iostream>
#include <string>
#include <algorithm>

std::string addNumbers(const std::string& a, const std::string& b) {
    std::string result = "";
    int carry = 0;
    
    int idxA = a.length() - 1;
    int idxB = b.length() - 1;

    while (idxA >= 0 || idxB >= 0) {
        int sum = carry;
        if (idxA >= 0) {
            sum += a[idxA] - '0';
            idxA--;
        }
        if (idxB >= 0) {
            sum += b[idxB] - '0';
            idxB--;
        }

        result.insert(result.begin(), (sum % 10) + '0');
        carry = sum / 10;
    }

    if (carry > 0) {
        result.insert(result.begin(), carry + '0');
    }

    return result;
}

std::string findB(const std::string& a, const std::string& s) {
    std::string b = "0";
    while (b.length() < s.length()) {
        b.insert(b.begin(), '0');
    }

    while (true) {
        if (addNumbers(a, b) == s) {
            return b;
        }

        int idx = b.length() - 1;
        while (b[idx] == '9') {
            b[idx] = '0';
            idx--;
        }
        if (idx < 0) {
            return "-1";
        }
        b[idx] = b[idx] + 1;
    }
}

int main() {
    int t;
    std::cin >> t;

    while (t--) {
        std::string a, s;
        std::cin >> a >> s;
        
        std::cout << findB(a, s) << std::endl;
    }

    return 0;
}