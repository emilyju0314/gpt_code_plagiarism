#include <iostream>
#include <cmath>

double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

bool isLetterA(int x1, int y1, int x2, int y2, int x3, int y3) {
    double AB = distance(x1, y1, x2, y2);
    double AC = distance(x1, y1, x3, y3);
    double BC = distance(x2, y2, x3, y3);
    
    if (AB == 0 || AC == 0 || BC == 0) {
        return false;
    }
    
    if (AB < AC) {
        std::swap(AB, AC);
        std::swap(x2, x3);
        std::swap(y2, y3);
    }
    
    if (AB < BC) {
        std::swap(AB, BC);
        std::swap(x1, x2);
        std::swap(y1, y2);
    }
    
    if (AC < BC) {
        std::swap(AC, BC);
        std::swap(x1, x3);
        std::swap(y1, y3);
    }
    
    double ratio1 = AC / AB;
    double ratio2 = BC / AB;
    
    double cos_angle = (pow(AB, 2) + pow(AC, 2) - pow(BC, 2)) / (2 * AB * AC);
    double angle = acos(cos_angle) * 180 / M_PI;
    
    return (angle > 0 && angle < 90 && ratio1 >= 1/4 && ratio2 >= 1/4);
}

int main() {
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; ++i) {
        int x1, y1, x2, y2, x3, y3;
        std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
        
        if (isLetterA(x1, y1, x2, y2, x3, y3)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    
    return 0;
}