#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int INF = 1e9;

struct Road {
    int to;
    int cost;
    int idx;
};

int main() {
    int n, m;
    cin >> n >> m;

    int s, t;
    cin >> s >> t;

    vector<vector<Road>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        int x, y, w;
        cin >> x >> y >> w;
        adj[x].push_back({y, w, i + 1});
        adj[y].push_back({x, w, i + 1});
    }

    vector<vector<int>> dist(n + 1, vector<int>(3, INF));
    vector<vector<int>> prev(n + 1, vector<int>(3));

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    pq.push({0, {s, 0}});
    dist[s][0] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int cur = pq.top().second.first;
        int closed = pq.top().second.second;
        pq.pop();

        if (dist[cur][closed] < cost) {
            continue;
        }

        for (Road& road : adj[cur]) {
            if (dist[cur][closed] + road.cost < dist[road.to][closed]) {
                dist[road.to][closed] = dist[cur][closed] + road.cost;
                prev[road.to][closed] = cur;
                pq.push({dist[road.to][closed], {road.to, closed}});
            }

            if (closed < 2 && dist[cur][closed] < dist[road.to][closed + 1]) {
                dist[road.to][closed + 1] = dist[cur][closed];
                prev[road.to][closed + 1] = cur;
                pq.push({dist[road.to][closed + 1], {road.to, closed + 1}});
            }
        }
    }

    if (dist[t][0] == INF) {
        cout << -1 << endl;
    } else {
        int minBudget = INF;
        int closedRoads = 0;
        vector<int> closedRoadIndices;

        for (int i = 0; i < 3; i++) {
            if (dist[t][i] < minBudget) {
                minBudget = dist[t][i];
                closedRoads = i;
            }
        }

        vector<int> path;
        int cur = t;
        while (cur != s) {
            path.push_back(cur);
            cur = prev[cur][closedRoads];
        }
        path.push_back(s);
        reverse(path.begin(), path.end());

        for (int i = 1; i < path.size(); i++) {
            int from = path[i - 1];
            int to = path[i];
            for (Road& road : adj[from]) {
                if (road.to == to) {
                    closedRoadIndices.push_back(road.idx);
                    break;
                }
            }
        }

        cout << minBudget << endl;
        cout << closedRoads << endl;
        for(int i=0; i<closedRoadIndices.size(); i++){
            cout << closedRoadIndices[i] << " ";
        }
    }

    return 0;
}