#include <iostream>
#include <vector>

struct Rectangle {
    int x1, y1, x2, y2, x3, y3, x4, y4;
};

double calculateArea(Rectangle rect) {
    // Using Shoelace formula to calculate the area of the rectangle
    return 0.5 * abs((rect.x1 - rect.x3) * (rect.y2 - rect.y1) + (rect.x2 - rect.x1) * (rect.y2 - rect.y3));
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Rectangle> photos(n);
    double totalArea = 0.0;
    
    for (int i = 0; i < n; i++) {
        std::cin >> photos[i].x1 >> photos[i].y1 >> photos[i].x2 >> photos[i].y2 >> photos[i].x3 >> photos[i].y3 >> photos[i].x4 >> photos[i].y4;
        totalArea += calculateArea(photos[i]);
    }
    
    double expectedScore = 0.0;
    
    for (int i = 0; i < n; i++) {
        expectedScore += calculateArea(photos[i]) / totalArea;
    }
    
    std::cout << expectedScore << std::endl;
    
    return 0;
}