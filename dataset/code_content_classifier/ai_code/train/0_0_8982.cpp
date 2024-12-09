#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<vector<int>> adj;
vector<int> vis;

bool dfs(int u, int N, int day) {
    bool possible = true;
    vis[u] = day;
    
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            possible &= dfs(v, N, day+1);
        } else if (vis[v] == day) {
            return false;
        }
    }
    
    return possible;
}

int main() {
    int N;
    cin >> N;
    
    adj.resize(N+1);
    vis.assign(N+1, 0);
    
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j < N; j++) {
            int opponent;
            cin >> opponent;
            adj[i].push_back(opponent);
        }
    }
    
    int min_days = 0;
    for (int i = 1; i <= N; i++) {
        if (vis[i] == 0) {
            bool possible = dfs(i, N, 1);
            if (!possible) {
                cout << -1 << endl;
                return 0;
            }
            min_days = max(min_days, vis[i]);
        }
    }
    
    cout << min_days << endl;
    
    return 0;
}