#include <iostream>
#include <vector>
#include <algorithm>

struct Point {
    int x;
    int y;
    int id;
};

bool comparePoints(Point p1, Point p2) {
    return p1.id < p2.id;
}

int main() {
    int n, q;
    std::cin >> n;
    
    std::vector<Point> points(n);
    for(int i = 0; i < n; i++) {
        std::cin >> points[i].x >> points[i].y;
        points[i].id = i;
    }
    
    std::cin >> q;
    
    for(int i = 0; i < q; i++) {
        int sx, tx, sy, ty;
        std::cin >> sx >> tx >> sy >> ty;
        
        std::vector<int> result;
        for(auto point : points) {
            if(point.x >= sx && point.x <= tx && point.y >= sy && point.y <= ty) {
                result.push_back(point.id);
            }
        }
        
        std::sort(result.begin(), result.end());
        
        for(auto id : result) {
            std::cout << id << std::endl;
        }
        
        std::cout << std::endl;
    }
    
    return 0;
}