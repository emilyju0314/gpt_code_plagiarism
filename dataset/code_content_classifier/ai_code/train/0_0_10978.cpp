#include <iostream>

int main() {
    int N;
    std::cin >> N;
    
    int prev_t = 0, prev_x = 0, prev_y = 0;
    
    for (int i = 0; i < N; i++) {
        int t, x, y;
        std::cin >> t >> x >> y;
        
        int distance = abs(x - prev_x) + abs(y - prev_y);
        int time_diff = t - prev_t;
        
        if (time_diff < distance || (time_diff - distance) % 2 != 0) {
            std::cout << "No" << std::endl;
            return 0;
        }
        
        prev_t = t;
        prev_x = x;
        prev_y = y;
    }
    
    std::cout << "Yes" << std::endl;
    
    return 0;
}