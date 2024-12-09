#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    vector<int> p(N);
    for(int i = 0; i < N; i++) {
        cin >> p[i];
    }

    vector<int> dp(N+1, INT_MAX);
    dp[0] = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < i; j++) {
            int cost = j * B + (i - j) * A;
            dp[i] = min(dp[i], dp[j] + cost);
        }
    }

    cout << dp[N] << endl;

    return 0;
}