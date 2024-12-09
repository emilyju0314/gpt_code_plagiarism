#include <iostream>
#include <string>

bool isPalindrome(std::string s) {
    int i = 0;
    int j = s.length() - 1;
    
    while (i < j) {
        if (s[i] != s[j]) {
            return false;
        }
        i++;
        j--;
    }
    
    return true;
}

std::string findNthEvenLengthPalindrome(int n) {
    int count = 0;
    std::string num = "11";
    
    while (count < n) {
        if (isPalindrome(num)) {
            count++;
            if (count == n) {
                break;
            }
        }
        
        int len = num.length();
        if (len % 2 == 0) {
            int halfLen = len / 2;
            std::string firstHalf = num.substr(0, halfLen);
            std::string newNum = num + firstHalf;
            long long int val = stoll(newNum);
            val++;
            num = std::to_string(val);
        } else {
            num += "1";
        }
    }
    
    return num;
}

int main() {
    int n;
    std::cin >> n;
    
    std::string result = findNthEvenLengthPalindrome(n);
    std::cout << result << std::endl;
    
    return 0;
}