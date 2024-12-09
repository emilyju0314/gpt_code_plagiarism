#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

int main() {
    int n;
    cin >> n;

    vector<Point> polygon(n);
    for(int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    int s, t;
    cin >> s >> t;

    if (s > t) {
        swap(s, t); // Ensure s < t
    }

    double min_distance = distance(polygon[s-1], polygon[t-1]);

    for (int i = 1; i < n; i++) {
        double current_distance = 0;
        
        // Case 1: Transfer
        current_distance = distance(polygon[s-1], polygon[i]);
        current_distance += distance(polygon[i], polygon[t-1]);
        min_distance = min(min_distance, current_distance);

        // Case 2: Descend
        if (polygon[s-1].x == polygon[i].x && polygon[s-1].y >= polygon[i].y && polygon[i].x == polygon[t-1].x && polygon[t-1].y >= polygon[i].y) {
            current_distance = abs(polygon[s-1].y - polygon[t-1].y);
            min_distance = min(min_distance, current_distance);
        }
    }

    cout << min_distance << endl;

    return 0;
}