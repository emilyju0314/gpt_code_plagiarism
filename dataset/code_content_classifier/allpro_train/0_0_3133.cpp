#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

int add(int a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
    return a;
}

int sub(int a, int b) {
    a -= b;
    if (a < 0) {
        a += MOD;
    }
    return a;
}

int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}

int power(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b % 2 == 1) {
            res = mult(res, a);
        }
        a = mult(a, a);
        b /= 2;
    }
    return res;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> chests(n);
    for (int i = 0; i < n; i++) {
        cin >> chests[i];
    }
    
    sort(chests.begin(), chests.end());
    
    vector<int> dp(n + 1, 0);
    vector<int> fact(n + 1, 1);
    
    for (int i = 1; i <= n; i++) {
        fact[i] = mult(fact[i-1], i);
    }
    
    for (int k = 1; k <= n; k++) {
        dp[k] = mult(sub(fact[n], fact[n-k]), power(fact[k], MOD-2));
        for (int j = 1; j <= n - k; j++) {
            dp[k] = add(dp[k], mult(power(2, j), mult(fact[n-k], power(fact[n-k-j], MOD-2))));
        }
    }
    
    for (int k = 1; k <= n; k++) {
        cout << dp[k] << " ";
    }
    
    return 0;
}