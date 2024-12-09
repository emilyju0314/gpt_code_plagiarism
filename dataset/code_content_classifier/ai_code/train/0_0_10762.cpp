#include <iostream>
#include <string>

int main() {
    int N, M;
    std::cin >> N >> M;

    // Convert N to base M
    std::string converted;
    while (N > 0) {
        int digit = N % M;
        if (digit >= 10) {
            converted += '0' + digit;
        } else {
            converted += 'A' + digit - 10;
        }
        N /= M;
    }

    // Check if the converted number is a palindrome
    bool isPalindrome = true;
    for (int i = 0; i < converted.length() / 2; i++) {
        if (converted[i] != converted[converted.length() - 1 - i]) {
            isPalindrome = false;
            break;
        }
    }

    // Output "YES" if palindrome, "NO" otherwise
    if (isPalindrome) {
        std::cout << "YES" << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }

    return 0;
}