#include <iostream>
#include <vector>

#define MOD 998244353

using namespace std;

int main() {
    int n;
    long long m;
    cin >> n >> m;

    vector<long long> a(n + 1);
    a[1] = a[2] = 1;
    for (int i = 3; i <= n; i++) {
        a[i] = (a[i - 1] + a[i - 2]) % MOD;
    }

    vector<long long> d(n + 1);
    for (int j = 1; j <= n; j++) {
        d[j] = a[j];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            d[j] = (d[j] + d[j - 1]) % MOD;
        }
    }

    cout << d[m] << endl;

    return 0;
}