#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

vector<vector<int>> treeS;
vector<vector<int>> treeT;
vector<vector<vector<int>>> dp;

int countSubtrees(int u, int v) {
    if (dp[u][v][0] != -1) {
        return dp[u][v][0];
    }
    
    dp[u][v][0] = 0;
    dp[u][v][1] = 1;
    
    for (int i = 0; i < treeS[u].size(); i++) {
        int childU = treeS[u][i];
        int childV = v;
        bool isMatching = true;
        
        for (int j = 0; j < treeT[v].size() && isMatching; j++) {
            if (countSubtrees(childU, j) == 0) {
                isMatching = false;
            }
        }
        
        if (isMatching) {
            dp[u][v][0]++;
            dp[u][v][1] = (dp[u][v][1] * (1LL * dp[childU][0][1])) % MOD;
        }
    }
    
    return dp[u][v][0];
}

int main() {
    int nS, nT;
    cin >> nS;
    
    treeS.resize(nS+1);
    
    for (int i = 0; i < nS-1; i++) {
        int u, v;
        cin >> u >> v;
        treeS[u].push_back(v);
        treeS[v].push_back(u);
    }
    
    cin >> nT;
    
    treeT.resize(nT+1);
    
    for (int i = 0; i < nT-1; i++) {
        int x, y;
        cin >> x >> y;
        treeT[x].push_back(y);
        treeT[y].push_back(x);
    }
    
    dp.resize(nS+1, vector<vector<int>>(nT+1, vector<int>(2, -1)));
    
    int ans = 0;
    
    for (int i = 1; i <= nT; i++) {
        ans = (ans + countSubtrees(1, i)) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}