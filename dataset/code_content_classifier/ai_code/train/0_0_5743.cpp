#include <iostream>
#include <vector>

int main() {
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> balls(n);
    for (int i = 0; i < n; i++) {
        std::cin >> balls[i];
    }
    
    int min_balls = balls[x-1];
    int min_index = x-1;
    for (int i = 0; i < n; i++) {
        if (balls[i] < min_balls) {
            min_balls = balls[i];
            min_index = i;
        }
    }
    
    std::vector<int> initial_balls(n);
    for (int i = 0; i < n; i++) {
        initial_balls[(i-x+n)%n] = balls[i];
    }
    
    int diff = balls[min_index];
    for (int i = 0; i < n; i++) {
        initial_balls[i] += diff - min_balls;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << initial_balls[i] << " ";
    }
    
    return 0;
}