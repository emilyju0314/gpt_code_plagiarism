#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights1(n);
    vector<int> heights2(n);

    for (int i = 0; i < n; i++) {
        cin >> heights1[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> heights2[i];
    }

    // dp[i] will store the maximum possible total height when considering the first i students
    vector<long long> dp(n+1, 0);

    dp[1] = max(heights1[0], heights2[0]);
    
    for (int i = 2; i <= n; i++) {
        dp[i] = max(dp[i-1] + max(heights1[i-1], heights2[i-1]), dp[i-2] + (heights1[i-1] + heights2[i-1]));
    }

    cout << dp[n] << endl;

    return 0;
}