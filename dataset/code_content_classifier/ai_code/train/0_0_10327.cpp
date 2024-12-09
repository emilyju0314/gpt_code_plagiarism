#include <iostream>
#include <string>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    string price;
    cin >> price;

    vector<long long> dp(price.size() + 1, 0);

    dp[0] = 0;
    dp[1] = price[0] - '0';

    for (int i = 2; i <= price.size(); i++) {
        dp[i] = (dp[i - 1] * 10 + (price[i - 1] - '0') * i) % MOD;
        dp[i] = (dp[i] + dp[i - 1]) % MOD;
    }

    cout << dp[price.size()] << endl;

    return 0;
}