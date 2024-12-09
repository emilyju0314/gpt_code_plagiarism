#include <iostream>
#include <cmath>

int main() {
    int px, py, cx, cy, r;
    std::cin >> px >> py >> cx >> cy >> r;
    
    // Calculate distance between point p and the center of circle c
    double distance = sqrt(pow(cx - px, 2) + pow(cy - py, 2));
    
    // Calculate the angle between the line connecting point p and the center of circle c and the x-axis
    double theta = atan2(py - cy, px - cx);
    
    // Calculate the angles at which the tangents intersect the circle
    double phi = asin(r / distance);
    
    // Calculate the tangent points
    double x1 = cx + r * cos(theta + phi);
    double y1 = cy + r * sin(theta + phi);
    
    double x2 = cx + r * cos(theta - phi);
    double y2 = cy + r * sin(theta - phi);
    
    // Print the tangent points with smaller x first
    if(x1 < x2) {
        std::cout << x1 << " " << y1 << std::endl;
        std::cout << x2 << " " << y2 << std::endl;
    } else {
        std::cout << x2 << " " << y2 << std::endl;
        std::cout << x1 << " " << y1 << std::endl;
    }
    
    return 0;
}