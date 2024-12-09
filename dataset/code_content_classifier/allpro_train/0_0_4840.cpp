#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree;
vector<int> dp;

int dfs(int node) {
    if (dp[node] != -1) {
        return dp[node];
    }
    
    int sum = 0;
    for (int child : tree[node]) {
        sum ^= (1 + dfs(child));
    }
    
    return dp[node] = sum;
}

int main() {
    int N, M;
    cin >> N >> M;
    
    tree.resize(N+1);
    dp.resize(N+1, -1);
    
    for (int i = 1; i <= M; i++) {
        int pi;
        cin >> pi;
        tree[pi].push_back(i);
    }
    
    if (dfs(0) == 0) {
        cout << "Bob" << endl;
    } else {
        cout << "Alice" << endl;
    }
    
    return 0;
}