#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> points(n);
    for (int i = 0; i < n; i++) {
        std::cin >> points[i];
    }
    
    std::sort(points.begin(), points.end());
    
    if (n % 2 == 1) {
        std::cout << points[n/2] << std::endl;
    } else {
        std::cout << points[n/2 - 1] << std::endl;
    }
    
    return 0;
}