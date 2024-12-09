#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> h(N), a(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<long long> dp(N, 0);
    for (int i = 0; i < N; i++) {
        dp[i] = a[i];
        for (int j = 0; j < i; j++) {
            if (h[j] < h[i]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
    }

    long long max_sum = 0;
    for (int i = 0; i < N; i++) {
        max_sum = max(max_sum, dp[i]);
    }

    cout << max_sum << endl;

    return 0;
}