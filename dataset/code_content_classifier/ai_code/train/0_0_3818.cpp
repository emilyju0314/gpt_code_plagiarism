#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int x, y, z;
    cin >> x >> y >> z;

    vector<int> a(n), b(n), c(n);
    vector<int> cnt(1 << k);

    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << x); j++) {
            cnt[j ^ a[i]]++;
        }
        for(int j = 0; j < (1 << y); j++) {
            cnt[j ^ b[i]]++;
        }
        for(int j = 0; j < (1 << z); j++) {
            cnt[j ^ c[i]]++;
        }
    }

    for(int t = 0; t < (1 << k); t++) {
        cout << cnt[t] % MOD << " ";
    }

    return 0;
}