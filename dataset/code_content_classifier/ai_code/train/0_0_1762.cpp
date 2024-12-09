#include <iostream>
#include <vector>
#include <list>
#include <cmath>
using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100001;

vector<list<int>> tree(MAXN);
long long dp[MAXN][2];
int n;

void dfs(int node, int parent) {
    dp[node][0] = 1;
    dp[node][1] = 1;
    
    for (int child : tree[node]) {
        if (child == parent) continue;
        dfs(child, node);
        
        dp[node][0] = (dp[node][0] * (dp[child][0] + dp[child][1])) % MOD;
        dp[node][1] = (dp[node][1] * dp[child][0]) % MOD;
    }
}

int main() {
    cin >> n;
    
    for (int i = 0; i < 2*n - 1; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(1, 0);
    
    cout << (dp[1][0] + dp[1][1]) % MOD << endl;
    
    return 0;
}