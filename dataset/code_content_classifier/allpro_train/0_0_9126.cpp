#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1000000007;
int n, k;
string s;
int dp[2005][2005];

int solve(int pos, int cnt) {
    if(cnt > k) return 0;
    if(pos == n) {
        return (cnt == k);
    }
    if(dp[pos][cnt] != -1) return dp[pos][cnt];
    
    long long ans = 0;
    for(char c = 'a'; c <= 'z'; ++c) {
        int newCnt = cnt + (c > s[pos]);
        ans = (ans + solve(pos + 1, newCnt)) % MOD;
    }
    return dp[pos][cnt] = ans;
}

int main() {
    cin >> n >> k;
    cin >> s;
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, 0) << endl;
    
    return 0;
}