#include <iostream>
#include <vector>
#include <queue>

#define INF 1e9

using namespace std;

struct Edge {
    int to, distance, delay;
};

int main() {
    int n, m;
    while (cin >> n >> m && n && m) {
        vector<vector<Edge>> adjList(n);
        vector<int> dist(n, INF);
        
        string s, p, g;
        cin >> s >> p >> g;
        
        for (int i = 0; i < m; i++) {
            string ai, bi;
            int di, ti;
            cin >> ai >> bi >> di >> ti;
            adjList[ai].push_back({bi, di, ti});
            adjList[bi].push_back({ai, di, ti});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, s});
        dist[s] = 0;
        
        while (!pq.empty()) {
            auto [d, u] = pq.top(); pq.pop();
            if (d > dist[u]) continue;
            
            for (Edge e : adjList[u]) {
                if (dist[u] + e.distance / 40 + e.delay >= dist[e.to]) continue;
                
                dist[e.to] = dist[u] + e.distance / 40 + e.delay;
                pq.push({dist[e.to], e.to});
            }
        }
        
        cout << dist[g] << endl;
    }
    
    return 0;
}