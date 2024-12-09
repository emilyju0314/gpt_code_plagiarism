#include <iostream>
#include <string>

int main() {
    int n;
    std::string s;
    
    std::cin >> n;
    std::cin >> s;
    
    int longest_balanced = 0;
    
    for(int i = 0; i < n; i++) {
        int zeros = 0, ones = 0;
        
        for(int j = i; j < n; j++) {
            if(s[j] == '0') {
                zeros++;
            } else {
                ones++;
            }
            
            if(zeros == ones) {
                longest_balanced = std::max(longest_balanced, j - i + 1);
            }
        }
    }
    
    std::cout << longest_balanced << std::endl;
    
    return 0;
}