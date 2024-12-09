#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double euclideanDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

int main() {
    int n;
    cin >> n;
    
    vector<Point> generators(n);
    for (int i = 0; i < n; i++) {
        cin >> generators[i].x >> generators[i].y;
    }
    
    int m;
    cin >> m;
    
    vector<Point> vertices(m);
    for (int i = 0; i < m; i++) {
        cin >> vertices[i].x >> vertices[i].y;
    }
    
    double minSumOfSquares = 1e18; // Initialize with a big value
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            double sumOfSquares = 0.0;
            for (int k = 0; k < m; k++) {
                double dist = euclideanDistance(vertices[k], generators[j]);
                sumOfSquares += dist * dist;
            }
            if (sumOfSquares < minSumOfSquares) {
                minSumOfSquares = sumOfSquares;
            }
        }
    }
    
    cout << fixed;
    cout.precision(8);
    cout << minSumOfSquares << endl;
    
    return 0;
}