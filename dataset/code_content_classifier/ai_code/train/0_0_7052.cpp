#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<int> gems(30001, 0);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        gems[p]++;
    }

    vector<int> dp(30001, 0);
    dp[d] = gems[d];

    int max_gems = dp[d];
    for (int i = d + 1; i <= 30000; i++) {
        dp[i] = max(dp[i], dp[i-1]);
        max_gems = max(max_gems, dp[i]);
    }

    for (int i = 0; i <= 30000; i++) {
        dp[i] += gems[i];
        max_gems = max(max_gems, dp[i]);
    }

    cout << max_gems << endl;

    return 0;
}