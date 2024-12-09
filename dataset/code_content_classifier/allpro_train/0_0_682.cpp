#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point p1, Point p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

bool isPointInsideCircle(Point center, double radius, Point p) {
    return distance(center, p) <= radius;
}

int main() {
    int N, M, K;
    
    while (cin >> N >> M >> K) {
        if (N == 0 && M == 0 && K == 0) {
            break;
        }
        
        vector<Point> settlements(N);
        for (int i = 0; i < N; i++) {
            cin >> settlements[i].x >> settlements[i].y;
        }
        
        double min_radius = 1000.0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                for (int k = 1; k <= M / 2; k++) {
                    double angle = (360.0 / M) * j;
                    Point center = { settlements[i].x + k * cos(angle), settlements[i].y + k * sin(angle) };
                    double max_distance = 0.0;
                    
                    for (int l = 0; l < N; l++) {
                        double d = distance(center, settlements[l]);
                        max_distance = max(max_distance, d);
                    }
                    
                    bool isCovered = true;
                    for (int l = 0; l < N; l++) {
                        if (!isPointInsideCircle(center, max_distance, settlements[l])) {
                            isCovered = false;
                            break;
                        }
                    }
                    
                    if (isCovered) {
                        min_radius = min(min_radius, max_distance);
                    }
                }
            }
        }
        
        cout << fixed;
        cout.precision(10);
        cout << min_radius << endl;
    }
    
    return 0;
}