#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define MOD 1000000007

using namespace std;

long long dp[100005];
int n, k;

long long power(long long x, long long y) {
    long long res = 1;
    while (y > 0) {
        if (y & 1) {
            res = (res * x) % MOD;
        }
        x = (x * x) % MOD;
        y >>= 1;
    }
    return res;
}

long long solve(vector<int>& a, int count, long long p) {
    if (count == 0) {
        return p;
    }

    if (dp[count] != -1) {
        return dp[count];
    }

    long long res = 0;
    for (int i = 0; i < k; i++) {
        vector<int> next_a = a;
        for (int j = 0; j < n; j++) {
            if (next_a[j] == -1) {
                next_a[j] = i;
            }
        }
        long long next_p = (p * k) % MOD;
        long long expected_operations = solve(next_a, count - 1, next_p);
        res = (res + expected_operations) % MOD;
    }

    res = (res * power(k, MOD - 2)) % MOD; // Calculate inverse modulo
    dp[count] = res;
    return res;
}

int main() {
    cin >> n >> k;
    vector<int> a(n);
    int count = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            count++;
        }
    }

    memset(dp, -1, sizeof(dp));
    long long answer = solve(a, count, 0);
    cout << answer << endl;

    return 0;
}