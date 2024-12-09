#include <iostream>
#include <vector>

int main() {
    int N;
    std::cin >> N;
    
    std::vector<int> heights(N);
    for(int i = 0; i < N; i++) {
        std::cin >> heights[i];
    }
    
    bool possible = true;
    for(int i = 1; i < N; i++) {
        if(heights[i] < heights[i-1]) {
            if(heights[i] == heights[i-1] - 1) {
                heights[i-1]--;
            } else {
                possible = false;
                break;
            }
        }
    }
    
    if(possible) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    return 0;
}