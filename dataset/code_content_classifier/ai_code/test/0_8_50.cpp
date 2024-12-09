#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> cnt(n+1, 0);
    cnt[0] = 1;
    long long total = 1;
    for (int i = 0; i < n; i++) {
        total = (total * a[i]) % MOD;

        long long temp = total;
        for (int j = 1; j <= a[i]; j++) {
            temp = (temp * j) % MOD;
            cnt[j] = (cnt[j] + cnt[j-1] * temp) % MOD;
        }
    }

    cout << (total - cnt[a[n-1]] + MOD) % MOD << endl;

    return 0;
}