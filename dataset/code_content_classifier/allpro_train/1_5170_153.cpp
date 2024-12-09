#include <bits/stdc++.h>
using namespace std;

int dp[2019] = {0};

int main() {
    string S;
    cin >> S;
    long long mod = 0;
    long long d = 1;
    dp[0] = 1;
    int ans = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
        mod = ((S[i] - '0') * d + mod) % 2019;
        ans += dp[mod]++;
        d = (d * 10) % 2019;
    }
    cout << ans << endl;
}