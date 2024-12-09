#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        long long x;
        cin >> n >> k >> x;

        string s;
        cin >> s;

        vector<long long> dp(2001);
        dp[n] = 1;

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == 'a') {
                dp[i] = dp[i+1];
            } else {
                dp[i] = dp[i+1] + dp[i+1];
                if(dp[i] > x) {
                    dp[i] = x;
                }
            }
        }

        string result = "";
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') {
                result += 'a';
            } else {
                if(x <= dp[i+1]) {
                    result += 'b';
                } else {
                    result += 'a';
                    x -= dp[i+1];
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}