#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 2e5 + 5;

vector<int> tree[MAX_N];
int white_nodes[MAX_N];
int red_nodes[MAX_N];
int dp[MAX_N][2];
int k;

void dfs(int node, int parent) {
    white_nodes[node] = 1;
    for(int child : tree[node]) {
        if(child != parent) {
            dfs(child, node);
            white_nodes[node] += white_nodes[child];
        }
    }
}

void solve(int node, int parent) {
    for(int child : tree[node]) {
        if(child != parent) {
            solve(child, node);
        }
    }

    dp[node][0] = dp[node][1] = 0;

    for(int child : tree[node]) {
        if(child != parent) {
            dp[node][0] += max(dp[child][0], dp[child][1]);
        }
    }

    dp[node][1] = dp[node][0];

    for(int child : tree[node]) {
        if(child != parent) {
            dp[node][1] = max(dp[node][1], 1 + dp[node][0] - max(dp[child][0], dp[child][1]) + dp[child][1]);
        }
    }

    dp[node][1] = min(dp[node][1], k);
}

int main() {
    int n;
    cin >> n >> k;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);
    solve(1, 0);

    cout << white_nodes[1] * (dp[1][0] - dp[1][1]) << endl;

    return 0;
}