#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

double distanceToClosestHideout(int W, int H, vector<Point>& hideouts) {
    double minDistance = numeric_limits<double>::max();
    
    for (int i = 0; i < W; i++) {
        double leftDistance = i;
        double rightDistance = W - i;
        
        double topDistance = H;
        double bottomDistance = H;
        
        for (Point& hideout : hideouts) {
            double hDistance = min(abs(i - hideout.x), min(abs(W - i), abs(i)));
            double vDistance = min(abs(H - hideout.y), hideout.y);
            
            topDistance = min(topDistance, vDistance);
            bottomDistance = min(bottomDistance, vDistance);
            
            minDistance = min(minDistance, min(hDistance, min(leftDistance, min(rightDistance, min(topDistance, bottomDistance))));
        }
    }
    
    return minDistance;
}

int main() {
    int W, H, N;
    cin >> W >> H >> N;
    
    vector<Point> hideouts(N);
    for (int i = 0; i < N; i++) {
        cin >> hideouts[i].x >> hideouts[i].y;
    }
    
    double result = distanceToClosestHideout(W, H, hideouts);
    
    cout << fixed << setprecision(3) << result << endl;
    
    return 0;
}