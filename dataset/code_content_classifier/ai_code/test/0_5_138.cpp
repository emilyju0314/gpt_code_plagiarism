#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    vector<int> b(m);
    vector<int> queries(q);

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

    for (int i = 0; i < q; i++) {
        int maxTotalCost = 0;
        for (int j = 0; j < m; j++) {
            int idx = upper_bound(a.begin(), a.end(), b[j] + queries[i]) - a.begin();
            if (idx > 0) {
                maxTotalCost += a[idx - 1];
            }
        }
        cout << maxTotalCost << endl;
    }

    return 0;
}