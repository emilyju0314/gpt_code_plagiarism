#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

long long power(long long a, long long b) {
    long long res = 1;
    for (; b; b >>= 1, a = a * a % MOD) {
        if (b & 1) {
            res = res * a % MOD;
        }
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == -1) {
            cnt++;
        }
    }

    long long ans = 0;
    long long t1 = 1LL * cnt * power(k, cnt - 1) % MOD;
    long long t2 = 1LL * (cnt * (cnt - 1) / 2) % MOD * power(k, cnt - 2) % MOD;

    for(int i = 0; i < n; i++) {
        ans = (ans + 1LL * max(0, i * (i - 1) / 2) % MOD * t1 % MOD) % MOD;
    }

    ans = (ans + 1LL * (n - 1) * n / 2 % MOD * t2 % MOD) % MOD;
    cout << ans << endl;

    return 0;
}