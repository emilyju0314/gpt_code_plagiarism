#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int dijkstra(vector<vector<int>>& graph, int start, int end) {
    int n = graph.size();
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    
    dist[start] = 0;
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        visited[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !visited[v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist[end];
}

int prim(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> parent(n, -1);
    vector<int> key(n, INF);
    vector<bool> mst(n, false);
    
    key[0] = 0;
    
    for (int count = 0; count < n - 1; count++) {
        int u = -1;
        for (int v = 0; v < n; v++) {
            if (!mst[v] && (u == -1 || key[v] < key[u])) {
                u = v;
            }
        }
        
        mst[u] = true;
        
        for (int v = 0; v < n; v++) {
            if (graph[u][v] != 0 && !mst[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    
    int min_length = 0;
    for (int i = 1; i < n; i++) {
        min_length += graph[i][parent[i]];
    }
    
    return min_length;
}

int main() {
    int s, d;
    while (cin >> s >> d) {
        if (s == 0 && d == 0) {
            break;
        }
        
        vector<vector<int>> hot_spring_district(s, vector<int>(d));
        vector<vector<int>> district_distances(d, vector<int>(d));
        
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < d; j++) {
                cin >> hot_spring_district[i][j];
            }
        }
        
        for (int i = 0; i < d-1; i++) {
            for (int j = 0; j < d-i; j++) {
                cin >> district_distances[i][j];
            }
        }
        
        vector<vector<int>> graph(s + d, vector<int>(s + d, 0));
        
        for (int i = 0; i < s; i++) {
            for (int j = 0; j < d; j++) {
                if (hot_spring_district[i][j] != 0) {
                    graph[i][s + j] = hot_spring_district[i][j];
                    graph[s + j][i] = hot_spring_district[i][j];
                }
            }
        }
        
        int index = s;
        for (int i = 0; i < d-1; i++) {
            for (int j = 0; j < d-i; j++) {
                if (district_distances[i][j] != 0) {
                    graph[index][index + 1] = district_distances[i][j];
                    graph[index + 1][index] = district_distances[i][j];
                }
                index++;
            }
            index++;
        }
        
        int min_length = prim(graph);
        cout << min_length << endl;
    }
    
    return 0;
}