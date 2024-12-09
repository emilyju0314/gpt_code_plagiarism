#include <iostream>
#include <cmath>

using namespace std;

double distance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2));
}

int main() {
    double xp, yp, vp; // Persephone's initial position and speed
    double x, y, v, r; // Qwerty's initial position, speed, and safe distance from the star

    cin >> xp >> yp >> vp;
    cin >> x >> y >> v >> r;

    double distance_to_persephone = distance(x, y, xp, yp);
    double time_to_persephone = distance_to_persephone / v;

    double circle_center_x = 0, circle_center_y = 0;
    double distance_to_circle_center = distance(x, y, circle_center_x, circle_center_y);

    double safe_distance = r;
    double intersection_distance = sqrt(distance_to_circle_center * distance_to_circle_center - safe_distance * safe_distance);
    
    double angle_to_persephone = atan2(yp - y, xp - x);
    double intersection_x = x + intersection_distance * cos(angle_to_persephone);
    double intersection_y = y + intersection_distance * sin(angle_to_persephone);

    double intersection_to_persephone = distance(intersection_x, intersection_y, xp, yp);
    double time_to_intersection = intersection_to_persephone / vp;

    double delivery_time = max(time_to_persephone, time_to_intersection);
    
    cout << delivery_time << endl;

    return 0;
}