#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m, q;
vector<vector<pair<int, int>>> graph;
vector<vector<int>> colorList;

void dfs(int u, int v, set<int>& visited, set<int>& colors) {
    if (u == v) return;
    visited.insert(u);
    for (auto& edge : graph[u]) {
        if (visited.count(edge.first) == 0) {
            if (edge.second != -1) {
                colors.insert(edge.second);
            }
            dfs(edge.first, v, visited, colors);
        }
    }
}

int main() {
    cin >> n >> m;
    graph.resize(n + 1);
    colorList.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
        colorList[a].push_back(c);
        colorList[b].push_back(c);
    }
    
    cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        
        set<int> visited, colors;
        dfs(u, v, visited, colors);
        
        int count = 0;
        for (int color : colors) {
            bool isValid = true;
            for (int j = 1; j <= n; j++) {
                if (colorList[j].size() > 1) {
                    if (colorList[j][0] == color && colorList[j][1] == color)
                        isValid = false;
                }
            }
            if (isValid) count++;
        }
        
        cout << count << endl;
    }
    
    return 0;
}