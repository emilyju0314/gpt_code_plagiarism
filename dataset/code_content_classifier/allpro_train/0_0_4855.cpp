#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long m, a, b;
    cin >> m >> a >> b;

    vector<int> dp(m+1, 0);
    dp[0] = 1;

    for(int i = 0; i <= m; i++) {
        if(i-a >= 0) {
            dp[i] += dp[i-a];
        }
        if(i-b >= 0) {
            dp[i] += dp[i-b];
        }

        dp[i] %= 1000000007;
    }

    long long sum = 0;
    for(int i = 0; i <= m; i++) {
        sum = (sum + dp[i]) % 1000000007;
    }

    cout << sum << endl;

    return 0;
}