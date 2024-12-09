#include <iostream>
#include <cmath>

int main() {
    int x1, x2, y1, y2, n;
    std::cin >> x1 >> y1 >> x2 >> y2;
    
    int min_distance = INT_MAX;
    int start_point;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        std::cin >> x >> y;
        
        int distance = abs(x - x1) + abs(y - y1) + abs(x - x2) + abs(y - y2);
        if (distance < min_distance) {
            min_distance = distance;
            start_point = x;
        }
    }
    
    std::cout << start_point << " " << min_distance << std::endl;
    
    return 0;
}