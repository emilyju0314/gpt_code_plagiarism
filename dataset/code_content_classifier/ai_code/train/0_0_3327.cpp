#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

// Function to calculate modular inverse
int modInverse(int a, int m) {
    int m0 = m, t, q, x0 = 0, x1 = 1;
    if (m == 1) return 0;

    while (a > 1) {
        q = a / m;
        t = m;
        m = a % m, a = t;
        t = x0;
        x0 = x1 - q * x0;
        x1 = t;
    }

    if (x1 < 0) x1 += m0;
    return x1;
}

// Function to calculate binomial coefficient
int binomialCoeff(int n, int k, vector<int>& fact, vector<int>& invFact) {
    return (fact[n] * invFact[k] % MOD * invFact[n - k] % MOD) % MOD;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }

    vector<int> fact(m + n + 1, 1);
    vector<int> invFact(m + n + 1, 1);
    for (int i = 1; i <= m + n; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modInverse(fact[i], MOD);
    }

    vector<int> dp(m + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= c[j]) {
                dp[i] = (dp[i] + dp[i - c[j]] * binomialCoeff(i - 1, c[j] - 1, fact, invFact) % MOD) % MOD;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        cout << dp[i] << "\n";
    }

    return 0;
}