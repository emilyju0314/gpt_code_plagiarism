#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<int> k(n);
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }

        vector<int> c(m);
        for (int i = 0; i < m; i++) {
            cin >> c[i];
        }

        sort(c.begin(), c.end());

        long long total_cost = 0;
        for (int i = 0; i < n; i++) {
            if (k[i] <= m) {
                total_cost += min(c[k[i] - 1], c[0]);
            } else {
                total_cost += c[0];
            }
        }

        cout << total_cost << endl;
    }

    return 0;
}