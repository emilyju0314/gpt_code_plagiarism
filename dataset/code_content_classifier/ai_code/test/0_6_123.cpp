#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 2e5 + 5;
vector<int> tree[MAXN];
int dp[MAXN][2][2]; // dp[node][red][blue] = maximum score with red color nodes and blue color nodes used

void dfs(int node, int parent, int k) {
    // Initialize dp values
    dp[node][0][0] = 1; // Score if node is white
    dp[node][1][0] = -k; // Score if node is red
    dp[node][0][1] = 0; // Score if node is blue
    dp[node][1][1] = 0;

    for(int child : tree[node]) {
        if(child == parent) continue;

        dfs(child, node, k);

        dp[node][0][0] += max(dp[child][0][0], max(dp[child][0][1], dp[child][1][0])); // Update score for white node
        dp[node][1][0] += max(dp[child][0][0], dp[child][0][1]); // Update score for red node
        dp[node][0][1] += max(dp[child][0][0], dp[child][1][0]); // Update score for blue node
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    for(int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0, k);

    int result = max(dp[1][0][0], max(dp[1][0][1], dp[1][1][0]));
    cout << result << endl;

    return 0;
}