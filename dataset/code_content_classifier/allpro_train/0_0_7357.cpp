#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> graph;
vector<int> color;
set<int> TaroCities;
set<int> HanakoCities;

void dfs(int v, int c) {
    color[v] = c;
    if (c == 1) TaroCities.insert(v);
    if (c == 2) HanakoCities.insert(v);
    
    for (int u : graph[v]) {
        if (color[u] == 0) {
            dfs(u, 3 - c);
        }
    }
}

int main() {
    int N, M;
    
    while (cin >> N >> M && (N != 0 || M != 0)) {
        graph.clear();
        graph.resize(N + 1);
        
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        color.clear();
        color.resize(N + 1);
        TaroCities.clear();
        HanakoCities.clear();
        
        for (int i = 1; i <= N; i++) {
            if (color[i] == 0) {
                dfs(i, 1);
            }
        }
        
        set<int> possibleCities;
        
        for (int v = 1; v <= N; v++) {
            if (TaroCities.count(v) && HanakoCities.count(v)) {
                possibleCities.insert(v);
            }
        }
        
        cout << possibleCities.size() << endl;
        
        for (int p : possibleCities) {
            cout << p << endl;
        }
    }
    
    return 0;
}