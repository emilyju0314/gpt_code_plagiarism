#include <iostream>
#include <vector>

#define MOD 1000000007

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    for(int i = 0; i < n; i++) {
        sum = (sum + a[i]) % MOD;
    }

    auto updateSum = [&](int idx, int val) {
        sum = (sum + (val - a[idx] + MOD) % MOD) % MOD;
        a[idx] = val;
    };

    while(q--) {
        int idx, val;
        cin >> idx >> val;
        updateSum(idx - 1, val);
        cout << sum << endl;
    }

    return 0;
}