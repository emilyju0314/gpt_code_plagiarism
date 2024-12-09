#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long ans = 0;
    long long mult = 1;
    int cnt = count(a.begin(), a.end(), -1);
    int tot = pow(k, cnt) % MOD;

    for (int i = 0; i < n; i++) {
        if (a[i] != -1) {
            for (int j = i + 1; j < n; j++) {
                if (a[j] != -1 && a[i] != a[j]) {
                    ans = (ans + mult) % MOD;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            ans = (ans + (mult * ((tot * pow(k, cnt - 1)) % MOD))) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}