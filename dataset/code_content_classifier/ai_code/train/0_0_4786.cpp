#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
    int i = 0, j = s.length() - 1;
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

std::string constructString(std::string s) {
    if (isPalindrome(s)) {
        return "NO";
    } else {
        int n = s.length();
        for (int i = 0; i < n; i++) {
            if (s[i] != 'a') {
                std::string result = s.substr(0, i) + "a" + s.substr(i);
                return "YES\n" + result;
            }
        }
        std::string result = s + "a";
        return "YES\n" + result;
    }
}

int main() {
    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) {
        std::string s;
        std::cin >> s;

        std::string output = constructString(s);
        
        std::cout << output << std::endl;
    }

    return 0;
}