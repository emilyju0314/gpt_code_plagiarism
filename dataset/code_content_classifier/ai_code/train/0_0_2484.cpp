#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void dfs(vector<vector<int>>& adj, vector<int>& values, unordered_map<int, int>& subtreeGCD, int node, int parent) {
    subtreeGCD[node] = values[node-1];
    
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(adj, values, subtreeGCD, neighbor, node);
            subtreeGCD[node] = gcd(subtreeGCD[node], subtreeGCD[neighbor]);
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<int> values(n);
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    
    vector<vector<int>> adj(n+1);
    for (int i = 0; i < n-1; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
    unordered_map<int, int> subtreeGCD;
    dfs(adj, values, subtreeGCD, 1, -1);
    
    for (int i = 1; i <= n; i++) {
        int ans = values[i-1];
        if (i != 1) {
            ans = gcd(ans, subtreeGCD[i]);
        }
        cout << ans << " ";
    }
    
    return 0;
}