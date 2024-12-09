#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

struct Ring {
    double x, y, r;
};

double euclideanDistance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double hausdorffDistance(Ring r1, Ring r2) {
    double d = euclideanDistance({r1.x, r1.y}, {r2.x, r2.y});
    double d_pp = abs(d + r1.r + r2.r);
    double d_pm = abs(d + r1.r - r2.r);
    double d_mp = abs(d - r1.r + r2.r);
    double d_mm = abs(d - r1.r - r2.r);
    
    return max({min(d_mm, d_pm), min(d_mp, d_pp), min(d_mm, d_mp), min(d_pm, d_pp)});
}

int main() {
    int k, n;
    cin >> k >> n;
    
    vector<vector<Point>> samples(k, vector<Point>(n));
    
    for(int i = 0; i < k * n; i++) {
        int x, y;
        cin >> x >> y;
        samples[i / n][i % n] = {x, y};
    }
    
    // Perform the necessary calculations to recover the rings
    // ...

    // Output the result
    for(int i = 0; i < k; i++) {
        cout << "Ring " << i + 1 << ":" << endl;
        cout << "Center: " << "x = " << " y = " << " Radius: " << endl;
    }

    return 0;
}