#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> spots_to_close;

void dfs(int u, unordered_map<int, vector<int>>& graph, vector<bool>& visited) {
    visited[u] = true;
    for(int v : graph[u]) {
        if(!visited[v]) {
            dfs(v, graph, visited);
        }
    }
}

void close_spots(int n, unordered_map<int, vector<int>>& graph) {
    vector<bool> visited(n+1, false);

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            int open_spots = 0;
            vector<int> connected_spots;
            for(int j : graph[i]) {
                if(!visited[j]) {
                    open_spots++;
                    connected_spots.push_back(j);
                }
            }

            if(open_spots >= 2) {
                for(int conn : connected_spots) {
                    visited[conn] = true;
                }

                for(int j : connected_spots) {
                    dfs(j, graph, visited);
                }
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(!visited[i]) {
            spots_to_close.push_back(i);
        }
    }
}

int main() {
    int T;
    cin >> T;

    while(T--) {
        int n, m;
        cin >> n >> m;

        unordered_map<int, vector<int>> graph;
        for(int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
        }

        close_spots(n, graph);

        int k = spots_to_close.size();
        cout << k << endl;
        for(int i = 0; i < k; i++) {
            cout << spots_to_close[i] << " ";
        }
        cout << endl;

        spots_to_close.clear();
    }

    return 0;
}