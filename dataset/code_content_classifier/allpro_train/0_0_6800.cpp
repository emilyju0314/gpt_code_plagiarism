#include <iostream>
#include <string>
#include <algorithm>

bool isSpalindrome(std::string s) {
    int n = s.length();
    for (int i = 0; i < n/2; i++) {
        if (s[i] != s[n-i-1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string s;
    std::cin >> s;

    std::string first_half = s.substr(0, s.length()/2);
    std::string second_half = s.substr((s.length()+1)/2);

    std::reverse(second_half.begin(), second_half.end());

    if (first_half == second_half && isSpalindrome(s)) {
        std::cout << "TAK" << std::endl;
    } else {
        std::cout << "NIE" << std::endl;
    }

    return 0;
}