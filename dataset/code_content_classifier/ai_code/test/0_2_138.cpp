#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<int> monocarp_items(n);
    vector<int> other_items(m);
    vector<int> queries(q);

    for (int i = 0; i < n; i++) {
        cin >> monocarp_items[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> other_items[i];
    }

    for (int i = 0; i < q; i++) {
        cin >> queries[i];
    }

    sort(monocarp_items.begin(), monocarp_items.end());

    for (int i = 0; i < q; i++) {
        int max_total_cost = 0;
        for (int j = 0; j < m; j++) {
            auto it = lower_bound(monocarp_items.begin(), monocarp_items.end(), other_items[j] - queries[i]);
            if (it != monocarp_items.end()) {
                int total_cost = accumulate(it, monocarp_items.end(), 0) + other_items[j];
                max_total_cost = max(max_total_cost, total_cost);
            }
        }
        cout << max_total_cost << endl;
    }

    return 0;
}