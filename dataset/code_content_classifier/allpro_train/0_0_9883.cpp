#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

vector<int> adj[MAXN];
int price[MAXN];
ll dp[MAXN];
vector<int> optimalSet;

ll dfs(int u, int parent) {
    dp[u] = price[u];
    for(int v : adj[u]) {
        if(v != parent) {
            dp[u] += max(0LL, dfs(v, u));
        }
    }
    return dp[u];
}

void findOptimalSet(int u, int parent, ll val) {
    if(val >= 0) {
        optimalSet.push_back(u);
        for(int v : adj[u]) {
            if(v != parent) {
                findOptimalSet(v, u, max(0LL, val + dp[v] - max(0LL, dp[v])));
            }
        }
    }
}

int main() {
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++) {
        cin >> price[i];
    }

    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);
    findOptimalSet(1, -1, 0);

    sort(optimalSet.begin(), optimalSet.end());

    cout << dp[1] - max(0LL, dp[1]) << " " << optimalSet.size() << endl;
    for(int i : optimalSet) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}