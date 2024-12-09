#include <iostream>
#include <vector>
#include <set>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<bool> visited;
vector<bool> important;

void dfs(int u, set<int>& reachable) {
    visited[u] = true;
    for (int v : graph[u]) {
        if (!visited[v]) {
            dfs(v, reachable);
        }
    }
    reachable.insert(u);
}

int main() {
    cin >> n >> m;
    
    graph.resize(n);
    visited.resize(n, false);
    important.resize(n, false);
    
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        graph[u].push_back(v);
    }

    set<int> allCities;
    for (int i = 0; i < n; i++) {
        set<int> reachable;
        fill(visited.begin(), visited.end(), false);
        dfs(i, reachable);
        allCities.insert(reachable.begin(), reachable.end());
    }

    for (int city : allCities) {
        if (allCities.size() == n-1) {
            important[city] = true;
        }
    }

    int semiImportantCount = 0;
    for (int i = 0; i < n; i++) {
        if (!important[i]) {
            bool found = false;
            for (int v : graph[i]) {
                if (important[v]) {
                    found = true;
                    break;
                }
            }
            if (found) {
                semiImportantCount++;
            }
        }
    }

    cout << importantCount + semiImportantCount << endl;

    return 0;
}