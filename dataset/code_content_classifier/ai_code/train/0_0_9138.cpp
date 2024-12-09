#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> heights(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> heights[i];
    }
    
    int max_watered_sections = 0;
    
    for (int i = 0; i < n; ++i) {
        int watered_sections = 1;
        
        // Water left
        for (int j = i - 1; j >= 0; --j) {
            if (heights[j] <= heights[j + 1]) {
                watered_sections++;
            } else {
                break;
            }
        }
        
        // Water right
        for (int j = i + 1; j < n; ++j) {
            if (heights[j] <= heights[j - 1]) {
                watered_sections++;
            } else {
                break;
            }
        }
        
        max_watered_sections = std::max(max_watered_sections, watered_sections);
    }
    
    std::cout << max_watered_sections << std::endl;
    
    return 0;
}