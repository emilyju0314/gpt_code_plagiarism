#include <iostream>
#include <vector>
#include <queue>

#define INF 1000000000

using namespace std;

struct Vessel {
    int dest;
    int fare;
    
    Vessel(int d, int f) : dest(d), fare(f) {}
};

int main() {
    int n, k;
    
    while (cin >> n >> k && n != 0 && k != 0) {
        vector<vector<Vessel>> adjList(n + 1);
        vector<vector<int>> fares(n + 1, vector<int>(n + 1, INF));
        
        for (int i = 0; i < k; i++) {
            int type;
            cin >> type;
            if (type == 0) {
                int a, b;
                cin >> a >> b;
                
                vector<int> dist(n + 1, INF);
                priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
                
                dist[a] = 0;
                pq.push({0, a});
                
                while (!pq.empty()) {
                    int u = pq.top().second;
                    int d = pq.top().first;
                    pq.pop();
                    
                    if (d > dist[u]) {
                        continue;
                    }
                    
                    for (const Vessel& v : adjList[u]) {
                        int newDist = d + v.fare;
                        if (newDist < dist[v.dest]) {
                            dist[v.dest] = newDist;
                            pq.push({newDist, v.dest});
                        }
                    }
                }
                
                if (dist[b] == INF) {
                    cout << -1 << endl;
                } else {
                    cout << dist[b] << endl;
                }
            } else {
                int c, d, e;
                cin >> c >> d >> e;
                
                adjList[c].push_back(Vessel(d, e));
                adjList[d].push_back(Vessel(c, e));
                
                fares[c][d] = fares[d][c] = e;
            }
        }
    }
    
    return 0;
}