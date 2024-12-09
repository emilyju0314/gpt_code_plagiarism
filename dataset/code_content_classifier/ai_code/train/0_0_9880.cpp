#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node, set<int>& path) {
    visited[node] = true;
    path.insert(node);

    for(int neighbor : graph[node]) {
        if(!visited[neighbor]) {
            dfs(graph, visited, neighbor, path);
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for(int i = 1; i < n; i++) {
        cin >> p[i];
    }

    vector<vector<int>> graph(n);
    for(int i = 1; i < n; i++) {
        graph[p[i]].push_back(i);
    }

    vector<bool> visited(n, false);
    set<int> path;
    
    dfs(graph, visited, 0, path);

    for(auto node : path) {
        cout << node + 1 << " ";
    }
    
    cout << endl;

    return 0;
}