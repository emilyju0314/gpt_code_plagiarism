#include <iostream>
#include <algorithm>

int main() {
    int t;
    std::cin >> t;
    
    while(t--) {
        int r, g, b;
        std::cin >> r >> g >> b;
        
        int days = 0;
        
        // Sort the candies to maximize the number of days Tanya can eat candies
        int candy[3] = {r, g, b};
        std::sort(candy, candy+3);
        
        // Calculate the number of days Tanya can eat candies
        if(candy[2] <= candy[0] + candy[1]) {
            days = candy[2] + (candy[0] + candy[1] - candy[2]) / 2;
        } else {
            days = candy[0] + candy[1];
        }
        
        std::cout << days << std::endl;
    }
    
    return 0;
}