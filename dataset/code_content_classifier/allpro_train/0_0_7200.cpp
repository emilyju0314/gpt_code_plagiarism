#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

bool divisibleBy60(const std::string& number) {
    int sum = 0;
    int numZeroes = 0;
    for(char c : number) {
        if(c == '0') {
            numZeroes++;
        }
        sum += c - '0';
    }
    
    return (numZeroes > 0 && sum % 3 == 0);
}

int main() {
    int n;
    std::cin >> n;
    
    for(int i = 0; i < n; i++) {
        std::string num;
        std::cin >> num;
        std::sort(num.begin(), num.end());
        
        do {
            if(divisibleBy60(num)) {
                std::cout << "red\n";
                break;
            }
        } while(std::next_permutation(num.begin(), num.end()));
        
        if(num != "red") {
            std::cout << "cyan\n";
        }
    }
    
    return 0;
}