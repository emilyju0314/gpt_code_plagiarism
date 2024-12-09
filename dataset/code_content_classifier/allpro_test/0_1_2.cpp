#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Calculate prefix sum array
    vector<int> prefix(n * m);
    for (int i = 0; i < n * m; i++) {
        prefix[i] = a[i % n];
        if (i > 0) {
            prefix[i] += prefix[i - 1];
        }
        prefix[i] %= k;
    }

    unordered_map<int, int> cnt;
    long long ans = 0;

    for (int i = 0; i < n * m; i++) {
        int need = (prefix[i] - (i >= n ? prefix[i - n] : 0) + k) % k;
        ans += cnt[need];
        cnt[prefix[i]]++;
    }

    cout << ans << endl;

    return 0;
}