#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

double calculate_distance(Point p1, Point p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

int main() {
    int N, M;
    while (cin >> N >> M) {
        if (N == 0 && M == 0) {
            break;
        }
        
        vector<Point> vertices(N);
        vector<Point> castles(M);
        
        for (int i = 0; i < N; i++) {
            cin >> vertices[i].x >> vertices[i].y;
        }
        
        for (int i = 0; i < M; i++) {
            cin >> castles[i].x >> castles[i].y;
        }
        
        for (int i = 0; i < M; i++) {
            double area = 0.0;
            for (int j = 0; j < N; j++) {
                int next_vertex_idx = (j + 1) % N;
                double dist1 = calculate_distance(castles[i], vertices[j]);
                double dist2 = calculate_distance(castles[i], vertices[next_vertex_idx]);
                area += (dist1 * dist2) / 2.0;
            }
            cout << fixed;
            cout.precision(4);
            cout << area << endl;
        }
    }
    
    return 0;
}