#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> prefix(n+1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + a[i-1];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = prefix[r] - prefix[l-1] - (r - l + 1) + k;
        ans += (a[l-1] - 1) + (a[r-1] - k);
        cout << ans << endl;
    }

    return 0;
}