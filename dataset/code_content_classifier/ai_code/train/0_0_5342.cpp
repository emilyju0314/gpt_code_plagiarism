#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct TaxiDriver {
    int maxDistance;
    int cost;
};

struct Road {
    int dest;
    int length;
};

int main() {
    int n, m;
    cin >> n >> m;

    int x, y;
    cin >> x >> y;

    vector<vector<Road>> roads(n+1);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        roads[u].push_back({v, w});
        roads[v].push_back({u, w});
    }

    vector<TaxiDriver> drivers(n+1);
    for(int i = 1; i <= n; i++) {
        int t, c;
        cin >> t >> c;
        drivers[i] = {t, c};
    }

    vector<int> dist(n+1, INT_MAX);
    vector<int> cost(n+1, INT_MAX);
    dist[x] = 0;
    cost[x] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});

    while(!pq.empty()) {
        int curr = pq.top().second;
        int currDist = pq.top().first;
        pq.pop();

        if(curr == y) {
            cout << cost[y] << endl;
            return 0;
        }

        for(auto& road : roads[curr]) {
            int next = road.dest;
            int roadLength = road.length;
            if(dist[curr] + roadLength < drivers[next].maxDistance && dist[curr] + roadLength < dist[next]) {
                dist[next] = dist[curr] + roadLength;
                cost[next] = cost[curr] + drivers[next].cost;
                pq.push({dist[next], next});
            }
        }
    }

    cout << "-1" << endl;
    return 0;
}