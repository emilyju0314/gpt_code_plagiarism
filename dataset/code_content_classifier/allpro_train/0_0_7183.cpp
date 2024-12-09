#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

int beautyOfPair(vector<vector<int>>& adjList, int s, int t, int N) {
    vector<int> dist(N, INT_MAX);
    dist[s] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (int v : adjList[u]) {
            if (dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[t];
}

int main() {
    int N, M, s, t;
    cin >> N >> M >> s >> t;
    
    vector<vector<int>> adjList(N);
    
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        
        adjList[x-1].push_back(y-1);
        adjList[y-1].push_back(x-1);
    }
    
    int shortestPath = beautyOfPair(adjList, s-1, t-1, N);
    int count = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j : adjList[i]) {
            if (beautyOfPair(adjList, s-1, i, N) + beautyOfPair(adjList, j, t-1, N) + 1 > shortestPath) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}