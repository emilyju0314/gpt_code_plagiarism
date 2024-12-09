#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int n;
vector<int> boxes;
vector<vector<vector<int>>> dp;

int dfs(int mask, int cur, int idx){
    if(dp[mask][cur][idx] != -1){
        return dp[mask][cur][idx];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        if((mask & (1 << i)) || cur % boxes[i] != 0){
            continue;
        }
        if(idx == -1 || cur == boxes[i]){
            ans = (ans + dfs(mask | (1 << i), boxes[i], idx + 1)) % MOD;
        } else {
            ans = (ans + dfs(mask | (1 << i), boxes[i], idx + 1)) % MOD;
            ans = (ans + dfs(mask | (1 << i), boxes[i] * cur, idx + 1)) % MOD;
        }
    }

    return dp[mask][cur][idx] = ans;
}

int main() {
    cin >> n;
    boxes.resize(n);

    for(int i = 0; i < n; i++){
        cin >> boxes[i];
    }

    sort(boxes.begin(), boxes.end(), greater<>());

    dp.resize(1 << n, vector<vector<int>>(61, vector<int>(n + 1, -1)));

    int ans = (dfs(0, 1, -1) + MOD) % MOD;

    cout << ans << endl;

    return 0;
}