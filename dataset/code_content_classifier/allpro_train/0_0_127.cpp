#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> robots(n);
    for (int i = 0; i < n; i++) {
        std::cin >> robots[i];
    }
    
    int index = (k-1) % (2*n);
    if (index < n) {
        std::cout << robots[index] << std::endl;
    } else {
        std::cout << robots[n - (index - n) - 1] << std::endl;
    }
    
    return 0;
}