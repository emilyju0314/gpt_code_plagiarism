#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> values;
vector<long long> moves;

void dfs(int node, int parent) {
    moves[node] = abs(values[node]); // Initialize moves at current node
    for (int child : adj[node]) {
        if (child != parent) {
            dfs(child, node);
            moves[node] += moves[child]; // Add moves required for subtree rooted at child
        }
    }
}

int main() {
    int n;
    cin >> n;

    adj.resize(n+1);
    values.resize(n+1);
    moves.resize(n+1);

    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        cin >> values[i];
    }

    dfs(1, -1); // Start DFS traversal from the root node

    cout << moves[1] << endl;

    return 0;
}