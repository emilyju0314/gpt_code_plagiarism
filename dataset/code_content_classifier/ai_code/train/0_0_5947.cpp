#include <iostream>
#include <string>

bool isPalindrome(std::string str) {
    int i = 0;
    int j = str.length() - 1;
    
    while (i < j) {
        if (str[i] != str[j]) {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

int main() {
    std::string S;
    std::cin >> S;
    
    int N = S.length();
    
    if (!isPalindrome(S)) {
        std::cout << "No" << std::endl;
        return 0;
    }
    
    std::string start = S.substr(0, ((N - 1) / 2));
    std::string end = S.substr(((N + 3) / 2) - 1, N);
    
    if (isPalindrome(start) && isPalindrome(end)) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}