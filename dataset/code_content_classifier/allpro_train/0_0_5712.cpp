#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> op;
vector<vector<int>> adj;
vector<int> X, Y;

int dfs(int node, int turn) {
    if (adj[node].empty()) {
        return 0;
    }

    if (turn == 0) {
        int res = 0;
        for (int child : adj[node]) {
            res = max(res, dfs(child, turn ^ 1));
        }
        return res;
    } else {
        int res = (1 << 16) - 1;
        for (int child : adj[node]) {
            res = min(res, dfs(child, turn ^ 1));
        }
        return res;
    }
}

int main() {
    cin >> N >> M;
    
    op.resize(N);
    adj.resize(N);
    X.resize(M);
    Y.resize(M);
    
    for (int i = 0; i < N-1; i++) {
        string operation;
        cin >> operation;
        
        if (operation == "T=T|X") {
            op[i] = 1;
        } else if (operation == "T=T|Y") {
            op[i] = 2;
        } else if (operation == "T=T^Y") {
            op[i] = 3;
        } else if (operation == "T=T&X") {
            op[i] = 4;
        }
    }
    
    for (int i = 0; i < N-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    
    for (int i = 0; i < M; i++) {
        cin >> X[i] >> Y[i];
    }
    
    for (int i = 0; i < M; i++) {
        cout << dfs(0, 0) << endl;
    }
    
    return 0;
}