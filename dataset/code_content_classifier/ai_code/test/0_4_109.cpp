#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1);
    dp[0] = 1;
    dp[1] = 2;

    for(int i = 2; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % MOD;
    }

    int total = 1;

    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if(s == "WW" || s == "BB") {
            total = (total * dp[1]) % MOD;
        } else if(s == "BW" || s == "WB") {
            total = (total * dp[2]) % MOD;
        }
    }

    cout << total << endl;

    return 0;
}