#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MOD = 1e9 + 7;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int x, y;
    cin >> x >> y;

    if (y % x != 0) {
        cout << "0" << endl;
    } else {
        int n = y / x;
        vector<int> divisors;
        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                divisors.push_back(i);
                if (i * i != n) {
                    divisors.push_back(n / i);
                }
            }
        }
        sort(divisors.begin(), divisors.end());

        vector<int> dp(divisors.size(), 0);
        for (int i = 0; i < divisors.size(); i++) {
            int d = divisors[i];
            dp[i] = 1;
            for (int j = 0; j < i; j++) {
                if (d % divisors[j] == 0) {
                    dp[i] = (dp[i] + dp[j]) % MOD;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < divisors.size(); i++) {
            ans = (ans + dp[i]) % MOD;
        }

        cout << ans << endl;
    }

    return 0;
}