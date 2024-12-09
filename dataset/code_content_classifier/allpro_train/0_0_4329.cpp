#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.141592653589793;


double calculateDistance(double x1, double y1, double x2, double y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double findShortestDistance(int n, int r, int R, int xs, int ys, int xt, int yt) {
    double angle = pi / n;
    double distance_XT = calculateDistance(0, 0, xt, yt);
    double distance_with_wall = R * sin(pi / (2 * n));
    
    double deltaX = xt - xs;
    double deltaY = yt - ys;
    double angle_with_XT = atan2(deltaY, deltaX);
    
    double minAngleWithDoor = angle_with_XT - (angle / 2);
    double maxAngleWithDoor = angle_with_XT + (angle / 2);

    if (minAngleWithDoor < 0) minAngleWithDoor += 2 * pi;
    if (maxAngleWithDoor > 2 * pi) maxAngleWithDoor -= 2 * pi;

    if ((minAngleWithDoor <= pi / 2 && maxAngleWithDoor >= pi / 2) || (minAngleWithDoor <= 3 * pi / 2 && maxAngleWithDoor >= 3 * pi / 2)) {
        return -1;
    }

    double resultDistance = distance_XT;
    if (angle_with_XT < minAngleWithDoor) {
        resultDistance = min(resultDistance, distance_XT + R - r);
    }
    if (angle_with_XT > maxAngleWithDoor) {
        resultDistance = min(resultDistance, distance_XT + R - r);
    }

    return resultDistance;
}

int main() {
    while (true) {
        int n, r, R, xs, ys, xt, yt;
        cin >> n;
        if (n == 0) break;
        cin >> r >> R >> xs >> ys >> xt >> yt;
        
        double shortestDistance = findShortestDistance(n, r, R, xs, ys, xt, yt);
        
        if (shortestDistance == -1) {
            cout << -1 << endl;
        } else {
            cout << shortestDistance << endl;
        }
    }

    return 0;
}