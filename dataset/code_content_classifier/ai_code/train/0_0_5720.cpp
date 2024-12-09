#include <iostream>
#include <string>
#include <unordered_set>

bool isPalindrome(std::string str) {
    int start = 0;
    int end = str.length() - 1;
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int main() {
    std::string A, B;
    std::cin >> A >> B;

    std::unordered_set<std::string> palindromesA, palindromesB;

    for (int i = 0; i < A.length(); i++) {
        std::string temp;
        for (int j = i; j < A.length(); j++) {
            temp += A[j];
            if (isPalindrome(temp)) {
                palindromesA.insert(temp);
            }
        }
    }

    for (int i = 0; i < B.length(); i++) {
        std::string temp;
        for (int j = i; j < B.length(); j++) {
            temp += B[j];
            if (isPalindrome(temp)) {
                palindromesB.insert(temp);
            }
        }
    }

    int count = 0;
    for (const std::string& palindromeA : palindromesA) {
        for (const std::string& palindromeB : palindromesB) {
            std::string concatenated = palindromeA + palindromeB;
            if (isPalindrome(concatenated)) {
                count++;
            }
        }
    }

    std::cout << count << std::endl;

    return 0;
}