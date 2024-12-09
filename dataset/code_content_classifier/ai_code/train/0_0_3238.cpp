#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;

vector<int> adj[MAXN];
int dp[MAXN];
int k, p;

void dfs(int u, int parent) {
    vector<int> children_profits;
    for (int v : adj[u]) {
        if (v != parent) {
            dfs(v, u);
            children_profits.push_back(dp[v]);
        }
    }

    sort(children_profits.begin(), children_profits.end());

    int childCnt = children_profits.size();
    int profit = 0, remain = k;
    for (int i = 0; i < childCnt; i++) {
        if (children_profits[i] <= remain) {
            remain -= children_profits[i];
            profit += children_profits[i];
        } else {
            profit += remain;
            break;
        }
    }
    
    dp[u] = profit;
}

int main() {
    int m;
    cin >> m >> k >> p;

    for (int i = 0; i < m - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, -1);

    cout << dp[1] << "\n";

    return 0;
}