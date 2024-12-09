#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

int computeArea(const Point& A, const Point& B, const Point& C) {
    return std::abs((A.x*(B.y - C.y) + B.x*(C.y - A.y) + C.x*(A.y - B.y)) / 2);
}

bool canBeSuperposed(const std::vector<Point>& T1, const std::vector<Point>& T2) {
    int areaT1 = computeArea(T1[0], T1[1], T1[2]);
    int areaT2 = computeArea(T2[0], T2[1], T2[2]);
    
    if (areaT1 != areaT2) return false;
    
    for (int i = 0; i < 3; i++) {
        bool found = false;
        for (int j = 0; j < 3; j++) {
            if (T1[i].x == T2[j].x && T1[i].y == T2[j].y) {
                found = true;
                break;
            }
        }
        if (!found) return false;
    }
    
    return true;
}

int main() {
    std::vector<Point> T1(3);
    std::vector<Point> T2(3);
    
    while (std::cin >> T1[0].x >> T1[0].y) {
        std::cin >> T1[1].x >> T1[1].y;
        std::cin >> T1[2].x >> T1[2].y;
        std::cin >> T2[0].x >> T2[0].y;
        std::cin >> T2[1].x >> T2[1].y;
        std::cin >> T2[2].x >> T2[2].y;
        
        if (canBeSuperposed(T1, T2)) {
            std::cout << "0" << std::endl;
            continue;
        }
        
        int minOps = 4;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int dx = T2[j].x - T1[i].x;
                int dy = T2[j].y - T1[i].y;
                int ops = 1;
                std::vector<Point> tempT1 = T1;
                
                for (int k = 0; k < 3; k++) {
                    tempT1[k].x += dx;
                    tempT1[k].y += dy;
                }
                
                if (canBeSuperposed(tempT1, T2)) {
                    minOps = std::min(minOps, ops);
                }
            }
        }
        
        if (minOps < 4) {
            std::cout << minOps << std::endl;
        } else {
            std::cout << "Many" << std::endl;
        }
    }
    
    return 0;
}