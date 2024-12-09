#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double polygonArea(vector<Point>& polygon) {
    int n = polygon.size();
    double area = 0.0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (polygon[i].x + polygon[j].x) * (polygon[i].y - polygon[j].y);
    }
    return abs(area) / 2.0;
}

int main() {
    int n, q;
    cin >> n >> q;

    vector<Point> polygon(n);
    for (int i = 0; i < n; i++) {
        cin >> polygon[i].x >> polygon[i].y;
    }

    // Calculate the area of the original polygon
    double originalArea = polygonArea(polygon);

    // Sort the x-coordinates of the polygon vertices
    vector<int> xCoords;
    for (int i = 0; i < n; i++) {
        xCoords.push_back(polygon[i].x);
    }
    sort(xCoords.begin(), xCoords.end());

    for (int i = 0; i < q; i++) {
        int f;
        cin >> f;

        // Find the two vertices of the polygon that are closest to the fold line x=f
        auto low = lower_bound(xCoords.begin(), xCoords.end(), f);
        int idx = low - xCoords.begin();
        int right = xCoords[idx];
        int left = xCoords[(idx - 1 + n) % n];

        // Calculate the x-coordinate of the strip
        double stripWidth = abs(left - right);

        // Calculate the area of the folded shape
        double foldedArea = originalArea + stripWidth * abs(polygon[idx].y - polygon[(idx - 1 + n) % n].y);

        cout << fixed;
        cout.precision(10);
        cout << foldedArea << endl;
    }

    return 0;
}