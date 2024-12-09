#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<pair<int, int>, int>> tasks(n);
    vector<int> results(n);

    for (int i = 0; i < n; i++) {
        int l, r, t;
        cin >> l >> r >> t;
        tasks[i] = {{l, r}, t};
    }

    int ans = 0;
    int i = 0;

    while (i < n) {
        int l = tasks[i].first.first;
        int r = tasks[i].first.second;
        int t = tasks[i].second;
        int si = max(ans + 1, l);

        if (si + t - 1 <= r) {
            results[i] = 0;
            ans = si + t - 1;
            i++;
        } else {
            int max_val = -1;
            int max_idx = -1;

            for (int j = 0; j < i; j++) {
                int lj = tasks[j].first.first;
                int rj = tasks[j].first.second;
                int tj = tasks[j].second;
                int sij = max(ans + 1, lj);

                if (sij <= rj && max(max_val, tj - sij) == tj - sij) {
                    max_val = tj - sij;
                    max_idx = j;
                }
            }

            if (max_val != -1) {
                results[i] = max_idx + 1;
                i++;
            } else {
                results[i] = -1;
                i++;
            }
        }
    }

    for (int r : results) {
        cout << r << " ";
    }

    return 0;
}