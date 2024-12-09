#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <unordered_map>

using namespace std;

unordered_map<long long, vector<pair<long long, long long>>> graph;

void addEdge(long long u, long long v, long long w) {
    graph[u].push_back({v, w});
    graph[v].push_back({u, w});
}

long long dijkstra(long long src, long long dest) {
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
    unordered_map<long long, long long> dist;
    
    pq.push({0, src});
    dist[src] = 0;
    
    while (!pq.empty()) {
        long long u = pq.top().second;
        long long w = pq.top().first;
        pq.pop();
        
        if (u == dest) {
            return w;
        }
        
        for (auto neighbor : graph[u]) {
            long long v = neighbor.first;
            long long weight = neighbor.second;
            long long newDist = w + weight;
            
            if (!dist.count(v) || newDist < dist[v]) {
                dist[v] = newDist;
                pq.push({newDist, v});
            }
        }
    }
    
    return 0;
}

int main() {
    long long q;
    cin >> q;
    
    for (long long i = 0; i < q; i++) {
        long long type, v, u;
        cin >> type >> v >> u;
        
        if (type == 1) {
            long long w;
            cin >> w;
            while (v != u) {
                if (v < u) {
                    swap(v, u);
                }
                
                addEdge(v, v/2, w);
                v /= 2;
            }
        } else {
            long long ans = dijkstra(v, u);
            cout << ans << endl;
        }
    }
    
    return 0;
}