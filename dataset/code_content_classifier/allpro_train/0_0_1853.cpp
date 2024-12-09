#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> cows(n);
    for(int i = 0; i < n; i++) {
        std::cin >> cows[i];
    }
    
    long long milkLost = 0;
    int numFacingRight = 0;
    
    for(int i = 0; i < n; i++) {
        if(cows[i] == 1) {
            numFacingRight++;
        } else {
            milkLost += numFacingRight;
        }
    }
    
    std::cout << milkLost << std::endl;
    
    return 0;
}