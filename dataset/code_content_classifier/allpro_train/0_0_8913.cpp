#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

bool isWithinRange(Point start, Point end, Point center, int radius) {
    return hypot(start.x - center.x, start.y - center.y) <= radius + 0.000001 ||
           hypot(end.x - center.x, end.y - center.y) <= radius + 0.000001;
}

int main() {
    int N, sx, sy, ex, ey;
    cin >> N >> sx >> sy >> ex >> ey;

    Point start = {sx, sy};
    Point end = {ex, ey};

    bool possible = true;
    
    for (int i = 0; i < N; i++) {
        int r, K;
        cin >> r >> K;
        
        vector<Point> vertices(K);
        for (int j = 0; j < K; j++) {
            cin >> vertices[j].x >> vertices[j].y;
        }

        for (int j = 0; j < K; j++) {
            Point p1 = vertices[j % K];
            Point p2 = vertices[(j + 1) % K];
            Point center = {p1.x, p1.y};
            
            for (double t = 0; t <= 1; t += 0.0001) {
                center.x = p1.x + t * (p2.x - p1.x);
                center.y = p1.y + t * (p2.y - p1.y);
                
                if (hypot(end.x - center.x, end.y - center.y) <= r + 0.000001) {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) {
                break;
            }
        }
        
        if (isWithinRange(start, end, vertices[0], r)) {
            possible = false;
        }
        
        if (!possible) {
            break;
        }
    }

    if (possible) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}