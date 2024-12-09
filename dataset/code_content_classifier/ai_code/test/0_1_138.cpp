#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> a(n);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    vector<int> maxCosts;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        
        int maxCost = 0;
        for (int j = 0; j < n; j++) {
            auto it = lower_bound(b.begin(), b.end(), a[j] + k);
            if (it != b.end()) {
                maxCost = max(maxCost, accumulate(a.begin(), a.begin() + j, 0) + accumulate(b.begin(), it, 0));
            }
        }

        maxCosts.push_back(maxCost);
    }

    for (int cost : maxCosts) {
        cout << cost << endl;
    }

    return 0;
}