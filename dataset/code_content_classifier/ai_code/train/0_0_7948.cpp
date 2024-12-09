#include <iostream>
#include <string>

bool isPalindrome(int number) {
    std::string str = std::to_string(number);
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
    int A, B;
    std::cin >> A >> B;
    
    int count = 0;
    for (int i = A; i <= B; i++) {
        if (isPalindrome(i)) {
            count++;
        }
    }
    
    std::cout << count << std::endl;
    
    return 0;
}