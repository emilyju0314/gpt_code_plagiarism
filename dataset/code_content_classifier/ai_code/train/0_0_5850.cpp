#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1000000007

using namespace std;

int n, m;
vector<int> a;
vector<int> b;
int dp[400][100500];

int solve(int type, int sum) {
    if(sum == 0) return 1;
    if(type == n) return 0;
    if(dp[type][sum] != -1) return dp[type][sum];

    int ans = 0;
    for(int i = 0; i <= b[type] && sum - i*a[type] >= 0; i++) {
        ans = (ans + solve(type + 1, sum - i*a[type])) % MOD;
    }

    return dp[type][sum] = ans;
}

int main() {
    cin >> n;

    a.resize(n-1);
    for(int i = 0; i < n - 1; i++) {
        cin >> a[i];
    }

    b.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }

    cin >> m;
    memset(dp, -1, sizeof(dp));

    cout << solve(0, m) << endl;

    return 0;
}