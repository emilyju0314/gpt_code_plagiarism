#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<vector<int>> adj;
vector<int> dist;

int dfs(int u, int parent) {
    int maxDist = 0;
    
    for (int v : adj[u]) {
        if (v != parent) {
            maxDist = max(maxDist, 1 + dfs(v, u));
        }
    }
    
    return dist[u] = maxDist;
}

int diameter(int root) {
    dist.assign(N, 0);
    dfs(root, -1);
    
    int maxLength = 0;
    for (int u = 0; u < N; u++) {
        maxLength = max(maxLength, dist[u]);
    }
    
    return maxLength;
}

int minVerticesToRemove() {
    int minVertices = N; // Initialize with largest possible value
    
    for (int root = 0; root < N; root++) {
        int maxLength = diameter(root);
        int toRemove = N - 1 - maxLength;
        
        if (maxLength <= K) {
            minVertices = min(minVertices, toRemove);
        }
    }
    
    return minVertices;
}

int main() {
    cin >> N >> K;
    adj.resize(N);
    
    for (int i = 0; i < N - 1; i++) {
        int A, B;
        cin >> A >> B;
        A--; // 0-based indexing
        B--; // 0-based indexing
        adj[A].push_back(B);
        adj[B].push_back(A);
    }
    
    int ans = minVerticesToRemove();
    cout << ans << endl;
    
    return 0;
}