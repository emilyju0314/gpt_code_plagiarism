#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    vector<int> dp(1001, INT_MAX);
    dp[1] = 0;

    for (int i = 2; i <= 1000; i++) {
        for (int j = 1; j <= i / 2; j++) {
            dp[i] = min(dp[i], dp[j] + dp[i-j] + 1);
        }
    }

    int n;
    while (cin >> n && n != 0) {
        cout << dp[n] << endl;
    }

    return 0;
}