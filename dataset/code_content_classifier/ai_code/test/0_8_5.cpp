#include <iostream>
#include <vector>
using namespace std;
const int MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long c = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) c++;
        else cnt += a[i];
    }

    long long ans = 0;
    for (int i = 0; i < c; i++) {
        ans = (ans * k + cnt) % MOD;
    }

    for (int i = 1; i < c; i++) {
        ans = (ans * k) % MOD;
    }

    long long pow2 = 1;
    for (int i = 0; i < c - 1; i++) {
        pow2 = (pow2 * n) % MOD;
    }

    ans = (ans * (k-1) % MOD) * pow2 % MOD;

    cout << ans << endl;

    return 0;
}