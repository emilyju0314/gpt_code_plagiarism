#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, a;
    cin >> n >> m >> a;

    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<int> p(m);
    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    sort(b.begin(), b.end());
    sort(p.begin(), p.end());

    int total_cost = 0;
    int max_schoolboys = 0;

    for (int i = 0; i <= n; i++) {
        int remaining_budget = a - i;
        if (remaining_budget < 0) break;

        int schoolboys = min(i, m);
        int cost = 0;

        for (int j = 0; j < schoolboys; j++) {
            if (j < n) {
                cost += min(b[j], p[j]);
            } else {
                cost += p[j];
            }
        }

        if (cost <= remaining_budget && schoolboys > max_schoolboys) {
            max_schoolboys = schoolboys;
            total_cost = cost;
        }
    }

    cout << max_schoolboys << " " << total_cost << endl;

    return 0;
}