#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    int px, py, vx, vy, a, b, c, d;
    std::cin >> px >> py >> vx >> vy >> a >> b >> c >> d;

    std::cout << std::fixed << std::setprecision(12);

    // Calculate coordinates
    double angle = atan2(vy, vx);
    double base_x = px;
    double base_y = py;
    double tip_x = px + b * cos(angle);
    double tip_y = py + b * sin(angle);
    double rect_side_x1 = px - c/2 * sin(angle);
    double rect_side_y1 = py + c/2 * cos(angle);
    double rect_side_x2 = px + c/2 * sin(angle);
    double rect_side_y2 = py - c/2 * cos(angle);

    // Output coordinates in counter-clockwise order
    std::cout << tip_x << " " << tip_y << std::endl;
    std::cout << rect_side_x1 << " " << rect_side_y1 << std::endl;
    std::cout << base_x << " " << base_y << std::endl;
    std::cout << rect_side_x2 << " " << rect_side_y2 << std::endl;

    double rect_corner1_x = rect_side_x1 + (d / 2) * cos(angle - M_PI/2);
    double rect_corner1_y = rect_side_y1 + (d / 2) * sin(angle - M_PI/2);
    double rect_corner2_x = rect_side_x1 + (d / 2) * cos(angle + M_PI/2);
    double rect_corner2_y = rect_side_y1 + (d / 2) * sin(angle + M_PI/2);
    double rect_corner3_x = rect_side_x2 + (d / 2) * cos(angle + M_PI/2);
    double rect_corner3_y = rect_side_y2 + (d / 2) * sin(angle + M_PI/2);
    double rect_corner4_x = rect_side_x2 + (d / 2) * cos(angle - M_PI/2);
    double rect_corner4_y = rect_side_y2 + (d / 2) * sin(angle - M_PI/2);

    std::cout << rect_corner1_x << " " << rect_corner1_y << std::endl;
    std::cout << rect_corner2_x << " " << rect_corner2_y << std::endl;
    std::cout << rect_corner3_x << " " << rect_corner3_y << std::endl;
    std::cout << rect_corner4_x << " " << rect_corner4_y << std::endl;

    return 0;
}