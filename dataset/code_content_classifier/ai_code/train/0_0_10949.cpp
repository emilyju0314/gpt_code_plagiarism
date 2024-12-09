#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y, z;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2) + pow(p1.z - p2.z, 2));
}

int main() {
    int n;
    cin >> n;

    vector<Point> planets(n);
    for (int i = 0; i < n; i++) {
        cin >> planets[i].x >> planets[i].y >> planets[i].z;
    }

    double max_distance = 0.0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            max_distance = max(max_distance, distance(planets[i], planets[j]));
        }
    }

    double time_to_reach_all_planets = max_distance / 2.0;
    cout << time_to_reach_all_planets << endl;

    return 0;
}