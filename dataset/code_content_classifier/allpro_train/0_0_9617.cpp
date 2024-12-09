#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj;
vector<int> beauty, target, presses;

void dfs(int node, int parent) {
    presses[node] = beauty[node] - target[node];
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            presses[node] += presses[child];
        }
    }
}

int main() {
    int N;
    cin >> N;
    
    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    beauty.resize(N);
    target.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> beauty[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> target[i];
    }
    
    presses.resize(N);
    dfs(0, -1);
    
    int total_presses = 0;
    for (int i = 0; i < N; i++) {
        total_presses += abs(presses[i]);
    }
    
    cout << total_presses << endl;
    
    return 0;
}