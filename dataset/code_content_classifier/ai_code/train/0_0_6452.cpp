#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

const int INF = 1e9;

struct Edge {
    int to;
    int capacity;
};

int main() {
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < m; i++) {
        int ai, bi, ci;
        cin >> ai >> bi >> ci;
        ai--; bi--;
        graph[ai].push_back({bi, ci});
    }

    vector<vector<int>> dist(n, vector<int>(x + 1, INF));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    dist[0][x] = 0;
    pq.push({0, {0, x}});

    while (!pq.empty()) {
        auto curr = pq.top();
        pq.pop();
        
        int cost = curr.first;
        int node = curr.second.first;
        int bears = curr.second.second;

        if (dist[node][bears] < cost) continue;

        for (const Edge& e : graph[node]) {
            int nextNode = e.to;
            int remainingBears = min(bears, e.capacity);
            int nextCost = cost + e.capacity;

            if (dist[nextNode][remainingBears] > nextCost) {
                dist[nextNode][remainingBears] = nextCost;
                pq.push({nextCost, {nextNode, remainingBears}});
            }
        }
    }

    double maxWeight = 0.0;
    for (int i = 1; i <= x; i++) {
        if (dist[n-1][i] == INF) continue;
        maxWeight = max(maxWeight, double(dist[n-1][i]) / double(i));
    }

    cout << fixed << setprecision(10) << maxWeight << endl;

    return 0;
}