#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<long long> prefix_sum(n+1, 0);
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i-1];
    }

    for (int k = 1; k <= n; k++) {
        long long ans = 0;
        for (int i = k; i <= n; i += m) {
            ans += prefix_sum[i];
        }
        cout << ans << " ";
    }

    return 0;
}