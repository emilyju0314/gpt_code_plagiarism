#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> balls(n);
    for(int i = 0; i < n; i++) {
        std::cin >> balls[i];
    }
    
    int max_balls = *std::max_element(balls.begin(), balls.end());
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += max_balls - balls[i];
    }
    
    std::cout << max_balls - sum << std::endl;
    
    return 0;
}