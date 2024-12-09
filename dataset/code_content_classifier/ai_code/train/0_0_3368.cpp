#include <iostream>
#include <vector>
#include <cmath>

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

double reflect_angle(Point wall_start, Point wall_end, Point lamp) {
    double angle_wall = atan2(wall_end.y - wall_start.y, wall_end.x - wall_start.x);
    double angle_lamp = atan2(lamp.y - wall_start.y, lamp.x - wall_start.x);
    return 2*angle_wall - angle_lamp;
}

double unilluminated_length(Point wall_start, Point wall_end, Point lamp) {
    double angle_reflect = reflect_angle(wall_start, wall_end, lamp);
    double angle_wall = atan2(wall_end.y - wall_start.y, wall_end.x - wall_start.x);
    
    if ((angle_reflect >= angle_wall && angle_reflect <= angle_wall + M_PI) ||
        (angle_reflect <= angle_wall && angle_reflect >= angle_wall - M_PI)) {
        return 0;
    } else {
        return distance(wall_start, wall_end);
    }
}

int main() {
    int N;
    std::cin >> N;
    
    while (N != 0) {
        std::vector<Point> corners(N);
        for (int i = 0; i < N; i++) {
            std::cin >> corners[i].x >> corners[i].y;
        }
        
        Point lamp;
        std::cin >> lamp.x >> lamp.y;
        
        double total_unilluminated = 0;
        for (int i = 0; i < N; i++) {
            total_unilluminated += unilluminated_length(corners[i], corners[(i+1)%N], lamp);
        }
        
        std::cout << total_unilluminated << std::endl;
        
        std::cin >> N;
    }
    
    return 0;
}