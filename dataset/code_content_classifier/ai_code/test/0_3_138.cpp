#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m), queries(q);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> prefix_max(m+1, 0);
    int j = 0;
    for (int i = 0; i < m; i++) {
        while (j < n && a[j] <= b[i]) {
            j++;
        }
        prefix_max[i+1] = prefix_max[i] + a[j-1];
    }

    for (int i = 0; i < q; i++) {
        int k = queries[i];

        int ans = 0;
        for (int j = m; j >= 0; j--) {
            if (k * (m - j) + j > n) {
                continue;
            }
            ans = max(ans, prefix_max[j] + b[m-j-1] * (m - j));
        }

        cout << ans << endl;
    }

    return 0;
}