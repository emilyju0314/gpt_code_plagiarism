#include <iostream>
#include <vector>
#include <map>

#define MOD 1009

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> colors(n);
    map<int, int> colorCount;

    for(int i = 0; i < n; i++) {
        cin >> colors[i];
        colorCount[colors[i]]++;
    }

    vector<int> dp(k+1);
    dp[0] = 1;

    for(auto& c : colorCount) {
        for(int i = k; i >= 0; i--) {
            for(int j = 1; j <= min(c.second, i); j++) {
                dp[i] = (dp[i] + dp[i-j]) % MOD;
            }
        }
    }

    cout << dp[k] << endl;

    return 0;
}