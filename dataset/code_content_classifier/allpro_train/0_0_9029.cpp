#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q, k;
    cin >> n >> q >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        // Calculate the number of arrays b that are k-similar to [a_l, a_{l+1}, ..., a_r]
        long long ans = a[r-1] - a[l-1] - 1 + (k - a[r-1]) + (a[l-1] - 1);
        cout << ans << endl;
    }

    return 0;
}