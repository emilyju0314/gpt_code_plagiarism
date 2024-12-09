#include <iostream>
#include <vector>
#include <cmath>

struct Circle {
    int x, y, r;
};

int countRegions(const std::vector<Circle>& circles) {
    int regions = 1 + circles.size(); // 1 for the infinite region and 1 for each circle
    
    for (int i = 0; i < circles.size(); i++) {
        for (int j = i + 1; j < circles.size(); j++) {
            double distance = sqrt(pow(circles[i].x - circles[j].x, 2) + pow(circles[i].y - circles[j].y, 2));
            if (distance < circles[i].r + circles[j].r && distance + circles[i].r > circles[j].r && distance + circles[j].r > circles[i].r) {
                regions++;
            }
        }
    }
    
    return regions;
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Circle> circles(n);
    for (int i = 0; i < n; i++) {
        std::cin >> circles[i].x >> circles[i].y >> circles[i].r;
    }
    
    int numRegions = countRegions(circles);
    std::cout << numRegions << std::endl;
    
    return 0;
}