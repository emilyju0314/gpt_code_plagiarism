#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the surface area of the polyhedron
double calculateSurfaceArea(vector<pair<int, int>>& points) {
    double area = 0;
    int n = points.size();

    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        area += (points[i].first * points[j].second) - (points[i].second * points[j].first);
    }

    return abs(area) / 2;
}

int main() {
    int n;
    
    while (true) {
        cin >> n;

        if (n == 0) {
            break;
        }

        vector<pair<int, int>> points;
        
        for (int i = 0; i < n; i++) {
            int ai, bi;
            cin >> ai >> bi;
            points.push_back(make_pair(ai, bi));
        }

        double surface_area = calculateSurfaceArea(points);
        cout << fixed << surface_area << endl;
    }

    return 0;
}