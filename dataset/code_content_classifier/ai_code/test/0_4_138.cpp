#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n), b(m), k(q);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> k[i];
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < q; i++) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int l = 0; l < n; l++) {
                if (abs(a[l] - b[j]) <= k[i]) {
                    cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans + n << endl;
    }

    return 0;
}