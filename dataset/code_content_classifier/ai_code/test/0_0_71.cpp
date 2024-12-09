#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Point {
    int x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() {
    int N, K;
    cin >> N >> K;
    
    vector<Point> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    vector<vector<double>> dist(N, vector<double>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dist[i][j] = distance(points[i], points[j]);
        }
    }
    
    vector<bool> visited(N, false);
    visited[K - 1] = true;
    
    double minPath = 0;
    int cur = K - 1;
    
    for (int i = 0; i < N - 1; i++) {
        int next = -1;
        double minDist = INFINITY;
        
        for (int j = 0; j < N; j++) {
            if (!visited[j] && dist[cur][j] < minDist) {
                minDist = dist[cur][j];
                next = j;
            }
        }
        
        visited[next] = true;
        minPath += minDist;
        cur = next;
    }
    
    cout << fixed << setprecision(6) << minPath << endl;
    
    return 0;
}