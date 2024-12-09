#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool checkTree(int n, vector<vector<int>>& edges) {
    set<int> vertices;
    for (int i = 1; i <= n; i++) {
        vertices.insert(i);
    }
    
    vector<int> degree(n + 1, 0);
    
    for (int i = 0; i < edges.size(); i++) {
        degree[edges[i][0]]++;
        degree[edges[i][1]]++;
    }
    
    vector<bool> visited(n + 1, false);
    
    for (int i = 1; i <= n; i++) {
        if (degree[i] > 1) {
            visited[i] = true;
            vertices.erase(i);
        }
    }
    
    while (!vertices.empty()) {
        int curr = *vertices.begin();
        vertices.erase(curr);
        
        bool connected = false;
        for (int i = 0; i < edges.size(); i++) {
            if ((edges[i][0] == curr || edges[i][1] == curr) && (visited[edges[i][0]] || visited[edges[i][1]])) {
                visited[edges[i][0]] = visited[edges[i][1]] = true;
                if (edges[i][0] == curr) {
                    vertices.erase(edges[i][1]);
                } else {
                    vertices.erase(edges[i][0]);
                }
                connected = true;
                break;
            }
        }
        
        if (!connected) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        
        vector<vector<int>> edges;
        
        for (int j = 0; j < k; j++) {
            int m;
            cin >> m;
            
            for (int l = 0; l < m; l++) {
                int u, v;
                cin >> u >> v;
                edges.push_back({u, v});
            }
        }
        
        if (checkTree(n, edges)) {
            cout << "YES" << endl;
            for (int j = 0; j < n - 1; j++) {
                cout << edges[j][0] << " " << edges[j][1] << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}