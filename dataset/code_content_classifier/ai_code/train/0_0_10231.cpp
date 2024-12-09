#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    long long P = 0;
    long long Q = 1;

    for (int i = 0; i < n; i++) {
        long long interval_size = r[i] - l[i] + 1;
        P += interval_size * interval_size % MOD;
        Q = Q * interval_size % MOD;
    }

    long long ans = P * Q % MOD;
    cout << ans << endl;

    return 0;
}