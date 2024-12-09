#include <bits/stdc++.h>
using namespace std;

int main() {
    int la, lb;
    cin >> la >> lb;
    
    vector<int> a(la), b(lb);
    for(int i = 0; i < la; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < lb; i++) {
        cin >> b[i];
    }
    
    unordered_map<int, int> last;
    int dp[lb + 1] = {0};

    for(int i = 0; i < la; i++) {
        int cur = 0;
        for(int j = 0; j < lb; j++) {
            if(a[i] == b[j]) {
                if(last.find(a[i]) != last.end()) {
                    dp[j] = max(dp[j], cur);
                }
                last[a[i]] = j;
            }
            if(a[i] > b[j]) {
                cur = max(cur, dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < lb; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}