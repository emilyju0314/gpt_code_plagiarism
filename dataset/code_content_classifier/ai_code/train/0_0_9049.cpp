#include <iostream>
#include <vector>
#include <algorithm>

#define MOD 1000000007

using namespace std;

int main() {
    long long n, l, k;
    cin >> n >> l >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<long long> b;
    for (int i = 0; i < l; i++) {
        b.push_back(a[i % n]);
    }

    long long count = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < min(i, k - 1) + 1; j++) {
            count = (count + b[i] * (l - i) % MOD) % MOD;
        }
    }

    cout << count << endl;

    return 0;
}