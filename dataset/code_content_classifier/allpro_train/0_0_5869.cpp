#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string N;
    cin >> N;
    
    vector<int> dp(N.size() + 1, 0);

    for (int i = 1; i <= N.size(); i++) {
        dp[i] = dp[i-1] + (N[i-1] != '0');
        if (i >= 2 && N[i-1] >= N[i-2]) {
            dp[i] = min(dp[i], dp[i-2]);
        } else {
            dp[i] = min(dp[i], dp[i-2] + 1);
        }

        if (i >= 3 && N[i-1] >= N[i-2] && N[i-2] >= N[i-3]) {
            dp[i] = min(dp[i], dp[i-3]);
        } else {
            dp[i] = min(dp[i], dp[i-3] + 1);
        }
    }

    cout << dp.back() << endl;

    return 0;
}