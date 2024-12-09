#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
vector<pair<int, int>> files;
int dp[1 << 14][1005];

int solve(int mask, int space_left) {
    if (mask == (1 << n) - 1) {
        return 0;
    }
    
    if (dp[mask][space_left] != -1) {
        return dp[mask][space_left];
    }
    
    int ans = 1e9;
    
    for (int i = 0; i < n; i++) {
        if (!(mask & (1 << i))) {
            if (files[i].first <= space_left) {
                ans = min(ans, solve(mask | (1 << i), min(space_left - files[i].first + files[i].second, m)));
            }
        }
    }
    
    return dp[mask][space_left] = ans;
}

int main() {
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        files.clear();
        
        for (int i = 0; i < n; i++) {
            int bi, ai;
            cin >> bi >> ai;
            files.push_back({bi, ai});
        }
        
        memset(dp, -1, sizeof(dp));
        
        int ans = solve(0, m);
        
        if (ans == 1e9) {
            cout << "Impossible" << endl;
        } else {
            cout << ans << endl;
        }
    }
    
    return 0;
}