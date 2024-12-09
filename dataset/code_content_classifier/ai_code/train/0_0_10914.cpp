#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> x(n);
    for(int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    
    std::vector<int> y(n);
    for(int i = 0; i < n; i++) {
        std::cin >> y[i];
    }
    
    int sum_x = 0, sum_y = 0;
    for(int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
    }
    
    if(sum_x < sum_y) {
        std::cout << "No" << std::endl;
    } else {
        std::cout << "Yes" << std::endl;
    }
    
    return 0;
}