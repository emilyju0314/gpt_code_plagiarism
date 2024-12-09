#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int h, t, R;
    cin >> h >> t >> R;

    int n;
    cin >> n;
    vector<pair<int, int>> grow_heads;
    for (int i = 0; i < n; i++) {
        int hi, ti;
        cin >> hi >> ti;
        grow_heads.push_back({hi, ti});
    }

    int m;
    cin >> m;
    vector<pair<int, int>> grow_tails;
    for (int i = 0; i < m; i++) {
        int hi, ti;
        cin >> hi >> ti;
        grow_tails.push_back({hi, ti});
    }

    bool can_win = false;
    int total_blow = 0;
    while (true) {
        if (h + t > R) {
            cout << "Zmey" << endl;
            cout << total_blow << endl;
            return 0;
        }

        bool all_zero = true;
        vector<int> new_h(n, 0);
        vector<int> new_t(m, 0);
        
        for (int i = 0; i < n; i++) {
            if (h < grow_heads[i].first) continue;
            if (t < grow_heads[i].second) continue;
            all_zero = false;
            new_h[grow_heads[i].first]++;
            new_t[grow_heads[i].second]++;
        }

        for (int i = 0; i < m; i++) {
            if (t < grow_tails[i].first) continue;
            if (t < grow_tails[i].second) continue;
            all_zero = false;
            new_h[grow_tails[i].first]++;
            new_t[grow_tails[i].second]++;
        }

        if (all_zero) {
            if (can_win) {
                cout << "Ivan" << endl;
                cout << total_blow << endl;
            } else {
                cout << "Draw" << endl;
            }
            return 0;
        }

        h += *max_element(new_h.begin(), new_h.end());
        t += *max_element(new_t.begin(), new_t.end());

        total_blow++;
    }

    return 0;
}