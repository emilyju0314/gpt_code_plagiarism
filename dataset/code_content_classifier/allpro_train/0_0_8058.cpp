#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> skills(n);
    for (int i = 0; i < n; i++) {
        std::cin >> skills[i];
    }
    
    std::sort(skills.begin(), skills.end());
    
    int totalProblems = 0;
    for (int i = 0; i < n/2; i++) {
        totalProblems += std::abs(skills[i] - skills[n - i - 1]);
    }
    
    std::cout << totalProblems << std::endl;
    
    return 0;
}