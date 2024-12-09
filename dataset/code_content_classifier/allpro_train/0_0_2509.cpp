#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdio>

using namespace std;

struct Vertex {
    int r, i;
    double dist;

    bool operator>(const Vertex& other) const {
        return dist > other.dist;
    }
};

double calculateDistance(int r1, int i1, int r2, int i2) {
    double x1 = r1 * cos(2 * M_PI * i1 / n);
    double y1 = r1 * sin(2 * M_PI * i1 / n);
    double x2 = r2 * cos(2 * M_PI * i2 / n);
    double y2 = r2 * sin(2 * M_PI * i2 / n);
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int n, x;
    while (cin >> n >> x && n != 0) {
        int rS, iS, rT, iT;
        cin >> rS >> iS >> rT >> iT;

        vector<vector<bool>> damaged(n + 1, vector<bool>(107, false));
        for (int i = 0; i < x; i++) {
            int rA, iA, rB, iB;
            cin >> rA >> iA >> rB >> iB;
            damaged[iA][rA] = damaged[iB][rB] = true;
        }

        priority_queue<Vertex, vector<Vertex>, greater<Vertex>> pq;
        vector<vector<double>> dist(n + 1, vector<double>(107, 1e9));
        pq.push({rS, iS, 0});
        dist[iS][rS] = 0;

        while (!pq.empty()) {
            Vertex v = pq.top();
            pq.pop();

            if (v.r == rT && v.i == iT) {
                printf("%.2f\n", v.dist);
                break;
            }

            for (int i = 0; i < n; i++) {
                int r = v.r + (i % 2 == 0 ? 1 : -1);
                if (r >= 1 && r <= 100 && !damaged[v.i][v.r] && dist[v.i][v.r] + 1 < dist[(v.i + 1) % n][r]) {
                    dist[(v.i + 1) % n][r] = dist[v.i][v.r] + 1;
                    pq.push({r, (v.i + 1) % n, dist[(v.i + 1) % n][r]});
                }
            }
        }
    }

    return 0;
}