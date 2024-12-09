#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

struct Circle {
    int x, y, r;
};

double distance(int x1, int y1, int x2, int y2) {
    return sqrt((double)(x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<Circle> circles(n);
        for (int i = 0; i < n; i++) {
            cin >> circles[i].x >> circles[i].y >> circles[i].r;
        }

        vector<double> shortest_distance(n, 1e9);
        vector<bool> visited(n, false);

        priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
        pq.push({0, 0});
        shortest_distance[0] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (visited[u]) continue;
            visited[u] = true;

            for (int v = 0; v < n; v++) {
                if (v != u) {
                    double dist = distance(circles[u].x, circles[u].y, circles[v].x, circles[v].y) - circles[u].r - circles[v].r;
                    dist = max(dist, 0.0);
                    if (shortest_distance[u] + dist < shortest_distance[v]) {
                        shortest_distance[v] = shortest_distance[u] + dist;
                        pq.push({shortest_distance[v], v});
                    }
                }
            }
        }

        cout << fixed << shortest_distance[n-1] << endl;
    }

    return 0;
}