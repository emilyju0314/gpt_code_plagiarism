#include <iostream>
#include <cmath>
#include <vector>

struct Circle {
    int x, y, r;
};

int main() {
    int x0, y0, v, T;
    std::cin >> x0 >> y0 >> v >> T;
    
    int n;
    std::cin >> n;
    
    std::vector<Circle> circles(n);
    for(int i = 0; i < n; i++) {
        std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
    
    // Your code for calculating the probability goes here
    
    return 0;
}