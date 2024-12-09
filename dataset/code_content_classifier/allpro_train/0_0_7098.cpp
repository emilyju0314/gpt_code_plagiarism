#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 1005;
vector<pair<int, int>> graph[MAX_N];
vector<int> treasures(MAX_N, 1);  // Assume there is one treasure on each island

void dfs(int node, int target, int max_durability, int T) {
    if (node == target) {
        return;  // Reached the destination island
    }
    
    for (auto edge : graph[node]) {
        int next_node = edge.first;
        int next_durability = max_durability - T;
        
        if (next_durability < 0) {
            continue;  // Bridge collapsed
        }
        
        treasures[next_node] += treasures[node];
        
        dfs(next_node, target, next_durability, T);
    }
}

int main() {
    int N, T, S, E;
    cin >> N >> T >> S >> E;
    
    for (int i = 0; i < N - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    dfs(S, E, T, T);
    
    if (treasures[E] == N) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}