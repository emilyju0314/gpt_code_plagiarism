#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long x;
        cin >> x;

        long long ans = 0;
        vector<long long> dp(105, 0);
        dp[0] = 0;
        
        for (int i = 1; i <= 100; i++) {
            dp[i] = i + dp[i - 1];
            if (dp[i] > x) {
                break;
            }
            ans++;
        }
        
        cout << ans << endl;
    }

    return 0;
}