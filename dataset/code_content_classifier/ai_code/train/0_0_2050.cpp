#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    string X;
    cin >> X;

    vector<long long> dp(X.size() + 1, 0);
    vector<long long> sum(X.size() + 1, 0);

    dp[0] = 0;
    sum[0] = 0;

    for(int i = 1; i <= X.size(); i++) {
        dp[i] = (10 * dp[i - 1] + (X[i - 1] - '0') * i) % MOD;
        sum[i] = (sum[i - 1] + dp[i]) % MOD;
    }

    long long result = 0;
    for(int i = 0; i < X.size(); i++) {
        result = (result + sum[X.size() - i - 1]) % MOD;
        result = (result + (X[i] - '0') * dp[X.size() - i - 1]) % MOD;
    }

    cout << result << endl;

    return 0;
}