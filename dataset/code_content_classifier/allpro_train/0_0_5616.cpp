#include <iostream>
#include <cmath>

using namespace std;

struct Point {
    int x;
    int y;
};

struct Wall {
    Point center;
    int radius;
};

bool isPointInsideWall(Point p, Wall w) {
    double distance = sqrt((p.x - w.center.x) * (p.x - w.center.x) + (p.y - w.center.y) * (p.y - w.center.y));
    return distance <= w.radius;
}

bool canSee(Point taro, Point demon, Wall* walls, int n) {
    for (int i = 0; i < n; i++) {
        if (isPointInsideWall(taro, walls[i]) && isPointInsideWall(demon, walls[i])) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        Wall walls[n];
        for (int i = 0; i < n; i++) {
            cin >> walls[i].center.x >> walls[i].center.y >> walls[i].radius;
        }

        int m;
        cin >> m;
        for (int i = 0; i < m; i++) {
            Point taro, demon;
            cin >> taro.x >> taro.y >> demon.x >> demon.y;

            if (canSee(taro, demon, walls, n)) {
                cout << "Danger" << endl;
            } else {
                cout << "Safe" << endl;
            }
        }
    }

    return 0;
}