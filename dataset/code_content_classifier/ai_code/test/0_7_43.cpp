#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Road {
    int to, capacity, toll;
};

vector<int> enjoyment_values;
vector<vector<Road>> adjacency_list;

pair<int, int> dfs(int city, int parent, vector<bool>& visited, int v) {
    visited[city] = true;
    pair<int, int> result = {enjoyment_values[city], 0};
    for (const Road& road : adjacency_list[city]) {
        if (road.to == parent) continue;
        if (road.capacity >= v) {
            pair<int, int> next = dfs(road.to, city, visited, v);
            result = max(result, next);
            result.second = max(result.second, road.toll);
        }
    }
    return result;
}

int main() {
    int n, q;
    cin >> n >> q;
    
    enjoyment_values.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> enjoyment_values[i];
    }
    
    adjacency_list.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int a, b, c, t;
        cin >> a >> b >> c >> t;
        a--; b--;
        adjacency_list[a].push_back({b, c, t});
        adjacency_list[b].push_back({a, c, t});
    }
    
    for (int i = 0; i < q; i++) {
        int v, x;
        cin >> v >> x;
        x--;
        vector<bool> visited(n, false);
        pair<int, int> result = dfs(x, -1, visited, v);
        cout << result.first << " " << result.second << "\n";
    }
    
    return 0;
}