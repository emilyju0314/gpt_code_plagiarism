#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> adj;
vector<vector<int>> cost;

int dfs(int node, int parent) {
    int total_time = 0;
    for (int i = 0; i < adj[node].size(); i++) {
        int child = adj[node][i];
        if (child != parent) {
            total_time += cost[node][i] * 2;
            total_time += dfs(child, node);
        }
    }
    return total_time;
}

int main() {
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        adj.clear();
        adj.resize(n);
        cost.clear();
        cost.resize(n);
        
        for (int i = 1; i < n; i++) {
            int p;
            cin >> p;
            adj[i].push_back(p);
            adj[p].push_back(i);
        }
        
        for (int i = 1; i < n; i++) {
            int d;
            cin >> d;
            cost[i].push_back(d);
            cost[adj[i][0]].push_back(d);
        }
        
        int min_time = INT_MAX;
        for (int i = 0; i < n; i++) {
            int removal_time = dfs(i, -1);
            min_time = min(min_time, removal_time);
        }
        
        cout << min_time << endl;
    }
    
    return 0;
}