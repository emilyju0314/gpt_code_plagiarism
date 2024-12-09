#include <iostream>
#include <vector>
#include <algorithm>

bool isPalindrome(std::string str) {
    int n = str.length();
    for(int i = 0; i < n / 2; i++) {
        if(str[i] != str[n - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> digits(n);
    for(int i = 0; i < n; i++) {
        std::cin >> digits[i];
    }
    
    std::sort(digits.begin(), digits.end());
    
    std::vector<std::string> beautifulIPs;
    
    do {
        for(int a = 0; a < (1 << n); a++) {
            std::string ip = "";
            for(int i = 0; i < 4; i++) {
                int octet = 0;
                for(int j = 0; j < n; j++) {
                    if((a >> j) & 1) {
                        octet = octet * 10 + digits[j];
                    }
                }
                ip += std::to_string(octet) + ".";
            }
            ip.pop_back(); // Remove the trailing '.'
            if(isPalindrome(ip)) {
                beautifulIPs.push_back(ip);
            }
        }
    } while(std::next_permutation(digits.begin(), digits.end()));
    
    std::cout << beautifulIPs.size() << std::endl;
    for(const std::string& ip : beautifulIPs) {
        std::cout << ip << std::endl;
    }
    
    return 0;
}