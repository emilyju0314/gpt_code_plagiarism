#include <iostream>
#include <vector>
#define mod 1000000007

using namespace std;

vector<int> adj[100002];
vector<int> colors(100002), black(100002), white(100002);
vector<vector<long long>> dp(100002, vector<long long>(2, 0));

void dfs(int u, int p) {
    dp[u][colors[u]] = colors[u];

    for(auto v: adj[u]) {
        if(v != p) {
            dfs(v, u);
            dp[u][0] = (dp[u][0]*(dp[v][0] + dp[v][1])) % mod;
            dp[u][0] = (dp[u][0] + dp[u][1]*dp[v][0]) % mod;
            dp[u][1] = (dp[u][1]*dp[v][0]) % mod;
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i < n; i++) {
        int p;
        cin >> p;

        adj[i].push_back(p);
        adj[p].push_back(i);
    }

    for(int i = 0; i < n; i++) {
        cin >> colors[i];

        if(colors[i] == 1) black[i]++;
        else white[i]++;
    }

    dfs(0, -1);

    cout << (dp[0][0] + dp[0][1]) % mod << endl;

    return 0;
}