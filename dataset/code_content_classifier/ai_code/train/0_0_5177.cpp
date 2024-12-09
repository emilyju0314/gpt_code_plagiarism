#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> dp(N + 1, -1e9); // Initialize dp array with negative infinity
    dp[1] = 0; // Starting vertex

    vector<int> a(M), b(M), c(M);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dp[a[j]] != -1e9) {
                dp[b[j]] = max(dp[b[j]], dp[a[j]] + c[j]);
            }
        }
    }

    if (dp[N] == -1e9) {
        cout << "inf" << endl;
    } else {
        cout << dp[N] << endl;
    }

    return 0;
}