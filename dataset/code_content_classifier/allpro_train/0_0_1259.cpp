#include <iostream>
#include <vector>
#include <queue>

#define MOD 1000000007
#define INF 1e9

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, x;
        cin >> u >> v >> x;
        graph[u].push_back(make_pair(v, 1 << x));
        graph[v].push_back(make_pair(u, 1 << x));
    }

    int s, t;
    cin >> s >> t;

    vector<int> dist(n + 1, INF);
    dist[s] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, s));

    while(!pq.empty()){
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto edge : graph[u]){
            int v = edge.first;
            int w = edge.second;
            if(dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }

    if(dist[t] == INF){
        cout << "-1" << endl;
    } else {
        vector<int> path;
        int curr = t;
        while(curr != s){
            path.push_back(curr);
            for(auto edge : graph[curr]){
                int v = edge.first;
                int w = edge.second;
                if(dist[curr] == dist[v] + w){
                    curr = v;
                    break;
                }
            }
        }
        path.push_back(s);

        cout << dist[t] % MOD << endl;
        cout << path.size() << endl;
        for(int i = path.size() - 1; i >= 0; i--){
            cout << path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}