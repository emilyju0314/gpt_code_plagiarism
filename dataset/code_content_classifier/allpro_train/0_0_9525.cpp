#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int n, m;
vector<pair<int, int>> relationships;
vector<unordered_set<int>> graph;
unordered_set<int> visited;
int ans = -1;

bool dfs(int curr, int boss) {
    visited.insert(curr);
    for (int subordinate : graph[curr]) {
        if (subordinate == boss) continue;
        if (visited.count(subordinate) || !dfs(subordinate, boss)) {
            return false;
        }
    }
    visited.erase(curr);
    return true;
}

int main() {
    cin >> n >> m;
    
    relationships.resize(m);
    graph.resize(n + 1);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        relationships[i] = {a, b};
        graph[a].insert(b);
    }
    
    for (int i = 0; i < m; i++) {
        int a = relationships[i].first, b = relationships[i].second;
        graph[a].erase(b);
        
        visited.clear();
        bool good = true;
        for (int j = 1; j <= n; j++) {
            if (!visited.count(j) && !dfs(j, j)) {
                good = false;
                break;
            }
        }
        
        if (good) {
            if (ans == -1) {
                ans = i + 1;
            } else {
                ans = -1;
                break;
            }
        }
        
        graph[a].insert(b);
    }
    
    cout << ans << endl;
    
    return 0;
}