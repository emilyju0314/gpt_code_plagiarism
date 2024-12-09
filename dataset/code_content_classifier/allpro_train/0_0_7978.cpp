#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 998244353

using namespace std;

int n;
vector<pair<int, int>> s;
long long dp[300005][3];

long long solve(int pos, int state) {
    if(pos == n) {
        return 1;
    }

    if(dp[pos][state] != -1) {
        return dp[pos][state];
    }

    long long ans = 0;

    if(state == 0) {
        // Fix first element and recurse
        int next_pos = pos;
        while(next_pos < n && s[next_pos].first == s[pos].first) {
            next_pos++;
        }
        ans += solve(next_pos, 0);
        
        // Fix second element and recurse
        next_pos = pos;
        while(next_pos < n && s[next_pos].second == s[pos].second) {
            next_pos++;
        }
        ans += solve(next_pos, 1);
    }
    else {
        // Fix position and recurse
        ans += solve(pos + 1, 2);
    }
    
    return dp[pos][state] = ans % MOD;
}

int main() {
    cin >> n;

    s.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i].first >> s[i].second;
    }
    
    sort(s.begin(), s.end());

    memset(dp, -1, sizeof(dp));

    cout << solve(0, 0) << endl;

    return 0;
}