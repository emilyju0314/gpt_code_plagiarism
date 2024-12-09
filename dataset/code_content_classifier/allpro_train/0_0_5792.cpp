#include <iostream>
#include <vector>

int main() {
    int t;
    std::cin >> t;
    
    for(int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        std::vector<int> blocks(n);
        for(int j = 0; j < n; j++) {
            std::cin >> blocks[j];
        }
        
        int max_climb = 0;
        int max_descend = 0;
        
        for(int j = 0; j < n - 1; j++) {
            int diff = blocks[j+1] - blocks[j];
            if(diff > 0) {
                max_climb = std::max(max_climb, diff);
            } else {
                max_descend = std::max(max_descend, -diff);
            }
        }
        
        std::cout << max_climb << " " << max_descend << std::endl;
    }
    
    return 0;
}