#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N, X;
    cin >> N >> X;

    vector<int> L(N);
    for(int i = 0; i < N; i++) {
        cin >> L[i];
    }

    vector<long long> dp(X + 1);
    dp[0] = 1;

    for(int i = 1; i <= X; i++) {
        for(int j = 0; j < N; j++) {
            if(i - L[j] >= 0) {
                dp[i] = (dp[i] + dp[i - L[j]]) % MOD;
            }
        }
    }

    cout << dp[X] << endl;

    return 0;
}