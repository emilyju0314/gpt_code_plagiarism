#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> sticks(12);
    
    // Input
    for(int i = 0; i < 12; i++) {
        std::cin >> sticks[i];
    }
    
    // Sort the sticks in non-decreasing order
    std::sort(sticks.begin(), sticks.end());
    
    // Check if a rectangular parallelepiped can be formed
    if(sticks[0] == sticks[1] && sticks[1] == sticks[2] && sticks[2] == sticks[3] &&
       sticks[4] == sticks[5] && sticks[5] == sticks[6] && sticks[6] == sticks[7] &&
       sticks[8] == sticks[9] && sticks[9] == sticks[10] && sticks[10] == sticks[11]) {
        if(sticks[0] == sticks[4] && sticks[4] == sticks[8]) {
            std::cout << "yes" << std::endl;
        } else {
            std::cout << "no" << std::endl;
        }
    } else {
        std::cout << "no" << std::endl;
    }
    
    return 0;
}