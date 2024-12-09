#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> adj;
vector<int> coins;

void dfs(int v, int parent) {
    for (int u : adj[v]) {
        if (u != parent) {
            dfs(u, v);
            coins[v] += coins[u]; // Move coins from child to parent
        }
    }
}

int main() {
    int N;
    cin >> N;

    adj.resize(N + 1);
    coins.resize(N + 1, 1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0); // Start DFS from root node with parent as 0

    // Check the winner based on number of coins at the root node
    if (coins[1] % 2 == 0) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }

    return 0;
}