#include <iostream>
#include <string>

int main() {
    std::string ticket;
    std::cin >> ticket;
    
    int sum_first_three = 0, sum_last_three = 0;
    
    for(int i = 0; i < 3; i++) {
        sum_first_three += ticket[i] - '0';
        sum_last_three += ticket[i+3] - '0';
    }
    
    int replacements_needed = 0;
    if(sum_first_three > sum_last_three) {
        for(int i = 0; i < 3; i++) {
            replacements_needed += std::max(0, '0' + 9 - ticket[i]);
        }
    } else {
        for(int i = 3; i < 6; i++) {
            replacements_needed += std::max(0, '0' + 9 - ticket[i]);
        }
    }
    
    std::cout << replacements_needed << std::endl;
    
    return 0;
}