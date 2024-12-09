// C++ program to find the maximum distance between two points
#include <bits/stdc++.h>
using namespace std;

// Function to calculate the distance between two points
double calculateDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> points;
    
    // Input the points
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.push_back({x, y});
    }
    
    // Calculate the distances between points
    double maxDistance = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double distance = calculateDistance(points[i].first, points[i].second, points[j].first, points[j].second);
            if (distance > maxDistance) {
                maxDistance = distance;
            }
        }
    }
    
    // Output the result
    cout << fixed << setprecision(10) << maxDistance << endl;
    
    return 0;
}