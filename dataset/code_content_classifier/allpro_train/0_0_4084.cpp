#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> fragments(n);
    for(int i = 0; i < n; i++) {
        std::cin >> fragments[i];
    }
    
    int min_sum = 0;
    for(int i = 0; i < n; i++) {
        int node = fragments[i] + 1;
        while(node % 2 == 0) {
            node /= 2;
            min_sum++;
        }
    }
    
    std::cout << min_sum << std::endl;
    
    return 0;
}