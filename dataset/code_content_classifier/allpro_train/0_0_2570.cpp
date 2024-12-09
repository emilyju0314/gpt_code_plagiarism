#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int n, d, m;
vector<int> deg;

long long dp[201][201][201][2][2];
bool vis[201][201][201][2][2];

long long solve(int v, int rem, int i, int flip, int neg) {
    if(rem < 0) return 0;
    if(v == n) {
        return (rem == 0);
    }
    long long &ans = dp[v][rem][i][flip][neg];
    if(vis[v][rem][i][flip][neg]) return ans;
    vis[v][rem][i][flip][neg] = true;
    ans = 0;

    if(flip == 0) {
        for(int j = 1; j <= d; j++) {
            if(v+j < n) {
                ans += solve(v+j, rem-j, i, 0, 0) + solve(v+j, rem-j, i, 0, 1);
                ans %= MOD;
            }
        }
    } else {
        if(i > 0) ans += solve(v+1, rem-1, i-1, 1, 0) + solve(v+1, rem-1, i-1, 1, 1);
        if(i < d) ans += solve(v+1, rem, i+1, 1, 0) + solve(v+1, rem, i+1, 1, 1);
        ans %= MOD;
    }

    if(neg == 0) {
        ans += solve(v+1, rem, i, flip, 0) + solve(v+1, rem, i, flip, 1);
    } else {
        ans += solve(v, rem-1, i, flip, 0) + solve(v, rem-1, i, flip, 1);
    }
    ans %= MOD;

    return ans;
}

int main() {
    cin >> n >> d >> m;

    memset(vis, 0, sizeof(vis));

    long long ans = 0;

    for(int i = 0; i <= d; i++) {
        ans += solve(1, d-i, i, 0, 0) + solve(1, d-i, i, 0, 1);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}