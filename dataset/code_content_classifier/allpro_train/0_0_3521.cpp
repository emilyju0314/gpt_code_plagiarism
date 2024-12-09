#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<char> commands(N);
    for (int i = 0; i < N; i++) {
        cin >> commands[i];
    }
    
    vector<long long> dp(N+1, 0);
    dp[0] = 1;

    for (int i = 0; i < N; i++) {
        if (commands[i] == 's') {
            dp[i+1] = dp[i] % MOD;
        } else {
            int open = 0;
            for (int j = i-1; j >= 0; j--) {
                if (commands[j] == 'f') {
                    open++;
                } else {
                    dp[i+1] = (dp[i+1] + dp[j]) % MOD;
                }

                if (open == 0) {
                    break;
                }
            }
        }
    }

    cout << dp[N] << endl;

    return 0;
}