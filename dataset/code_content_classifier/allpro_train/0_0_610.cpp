#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    vector<long long> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    long long ans = 0;

    for (int i = 0; i < n; i++) {
        ans = (ans + a[i] * b[n - 1 - i]) % MOD;
    }

    cout << ans << endl;

    return 0;
}