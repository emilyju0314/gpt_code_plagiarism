#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, W;
    cin >> n >> m >> W;

    vector<int> wi(m), ci(m), ai(m);
    for(int i = 0; i < m; i++) {
        cin >> wi[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> ci[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> ai[i];
    }

    vector<long long> dp(W+1, numeric_limits<long long>::max());
    dp[0] = 0;

    for(int i = 0; i < m; i++) {
        for(int j = wi[i]; j <= W; j++) {
            dp[j] = min(dp[j], dp[j - wi[i]] + ci[i] + ai[i]*(j/wi[i] - 1));
        }
    }

    cout.precision(9);
    cout << fixed << dp[W] << endl;

    return 0;
}