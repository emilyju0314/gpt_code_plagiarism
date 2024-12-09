#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long total = 0;
    long long sum = 0;
    map<long long, long long> count;
    count[0] = 1;

    for (int i = 0; i < n * m; i++) {
        sum += a[i % n];
        sum %= k;

        total += count[(k - sum) % k];
        count[sum]++;
    }

    cout << total % MOD << endl;

    return 0;
}