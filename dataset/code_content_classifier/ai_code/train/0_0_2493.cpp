#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> colors;
vector<int> used_colors;

void dfs(int v, int p) {
    int color = 1;
    for (int u : adj[v]) {
        if (u == p) continue;
        if (color == colors[v]) color++;
        colors[u] = color;
        used_colors.push_back(color);
        color++;
        dfs(u, v);
    }
}

int main() {
    int N;
    cin >> N;
    
    adj.resize(N + 1);
    colors.resize(N + 1);
    
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    colors[1] = 1;
    used_colors.push_back(1);
    dfs(1, 0);
    
    sort(used_colors.begin(), used_colors.end());
    used_colors.erase(unique(used_colors.begin(), used_colors.end()), used_colors.end());
    
    cout << used_colors.size() << endl;
    for (int i = 2; i <= N; i++) {
        cout << colors[i] << endl;
    }
    
    return 0;
}