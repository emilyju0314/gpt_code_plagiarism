#include <iostream>
#include <vector>
#include <limits>
#include <queue>
using namespace std;

struct Edge {
    int dest;
    int weight;
};

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<Edge>> graph(n + 1);
    for(int i = 0; i < m; i++){
        int u, v, l;
        cin >> u >> v >> l;
        graph[u].push_back({v, l});
        graph[v].push_back({u, l});
    }

    vector<int> storages;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        storages.push_back(a);
    }

    int min_cost = numeric_limits<int>::max();
    for(int i = 1; i <= n; i++){
        if(k > 0 && find(storages.begin(), storages.end(), i) != storages.end()){
            continue;
        }

        vector<int> dist(n + 1, numeric_limits<int>::max());
        vector<bool> visited(n + 1, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});
        dist[i] = 0;

        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();

            if(visited[u]){
                continue;
            }

            visited[u] = true;

            for(Edge e : graph[u]){
                int v = e.dest;
                int weight = e.weight;

                if(dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        for(int j : storages){
            if(dist[j] != numeric_limits<int>::max()){
                min_cost = min(min_cost, dist[j]);
            }
        }
    }

    if(min_cost == numeric_limits<int>::max()){
        cout << -1 << endl;
    } else {
        cout << min_cost << endl;
    }

    return 0;
}