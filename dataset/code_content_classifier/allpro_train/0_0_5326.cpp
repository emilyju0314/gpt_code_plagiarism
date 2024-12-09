#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate the angle between two vectors
double calculateAngle(int x1, int y1, int x2, int y2) {
    double dot_product = x1*x2 + y1*y2;
    double magnitude1 = sqrt(x1*x1 + y1*y1);
    double magnitude2 = sqrt(x2*x2 + y2*y2);
    return acos(dot_product / (magnitude1 * magnitude2));
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> vectors(n);
    for (int i = 0; i < n; i++) {
        cin >> vectors[i].first >> vectors[i].second;
    }

    double min_angle = M_PI; // Initialize with maximum possible value
    int a = -1, b = -1;

    for (int i = 0; i < n; i++) {
        double angle = calculateAngle(vectors[i].first, vectors[i].second, vectors[(i+1)%n].first, vectors[(i+1)%n].second);
        if (angle < min_angle) {
            min_angle = angle;
            a = i+1;
            b = (i+1)%n + 1;
        }
    }

    cout << a << " " << b << endl;

    return 0;
}