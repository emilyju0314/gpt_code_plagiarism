#include <iostream>
#include <vector>
#define MOD 998244353

using namespace std;

vector<vector<int>> tree;
vector<long long> dp_sum, dp_prod;

void dfs(int node, int parent) {
    dp_sum[node] = 1;
    dp_prod[node] = 1;
    
    for(int child : tree[node]) {
        if(child != parent) {
            dfs(child, node);
            dp_sum[node] = (dp_sum[node] * (1 + dp_sum[child])) % MOD;
            dp_prod[node] = (dp_prod[node] * dp_sum[child]) % MOD;
        }
    }
}

int main() {
    int n;
    long long x;
    cin >> n >> x;
    
    tree.resize(n);
    dp_sum.resize(n);
    dp_prod.resize(n);
    
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    
    dfs(0, -1);
    
    long long result = (x * dp_prod[0]) % MOD;
    result = (result + dp_sum[0]) % MOD;
    
    cout << result << endl;
    
    return 0;
}