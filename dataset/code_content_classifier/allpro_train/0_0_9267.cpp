#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> v(N), w(N), m(N);

    for (int i = 0; i < N; i++) {
        cin >> v[i] >> w[i] >> m[i];
    }

    vector<long long> dp(W + 1, 0);
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < m[i]; k++) {
            for (int j = W; j >= w[i]; j--) {
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
    }

    cout << dp[W] << endl;

    return 0;
}