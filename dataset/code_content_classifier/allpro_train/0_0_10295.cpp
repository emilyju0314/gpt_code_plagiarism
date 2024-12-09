#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, H;
    cin >> N >> H;

    vector<int> d(N), h(N);
    for (int i = 1; i < N; i++) {
        cin >> d[i] >> h[i];
    }

    vector<int> dp(N, 1e9);
    dp[1] = 0; // Starting floor, no fountains used

    for (int i = 2; i < N; i++) {
        for (int j = 1; j < i; j++) {
            int needed_strength = max(0, d[i] - h[j]); // Amount of health needed
            dp[i] = min(dp[i], dp[j] + (needed_strength + H - 1) / H); // Calculate minimum fountains needed
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}