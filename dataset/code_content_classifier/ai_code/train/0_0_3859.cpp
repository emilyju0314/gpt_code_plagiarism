#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

struct Point {
    int x, y, z;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main() {
    int n;
    std::cin >> n;
    
    std::vector<Point> points(n+1);
    for(int i = 0; i <= n; i++) {
        std::cin >> points[i].x >> points[i].y >> points[i].z;
    }
    
    double vp, vs;
    std::cin >> vp >> vs;
    
    Point harry;
    std::cin >> harry.x >> harry.y >> harry.z;
    
    double min_time = distance(harry, points[0]) / vp;
    for(int i = 1; i <= n; i++) {
        double time_to_point = distance(points[i-1], points[i]) / vs;
        double time_if_catch = distance(harry, points[i]) / vp;
        if(time_to_point + time_if_catch < min_time) {
            min_time = time_to_point + time_if_catch;
        }
    }
    
    double x = points.back().x;
    double y = points.back().y;
    double z = points.back().z;
    
    if(min_time * vs <= distance(harry, points.back())) {
        std::cout << "YES" << std::endl;
        std::cout << std::fixed << std::setprecision(10) << min_time << std::endl;
        std::cout << std::fixed << std::setprecision(10) << x << " " << y << " " << z << std::endl;
    } else {
        std::cout << "NO" << std::endl;
    }
    
    return 0;
}