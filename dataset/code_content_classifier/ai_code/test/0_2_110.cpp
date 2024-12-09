#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cells(n, vector<int>(3));
    set<int> colors[3];

    for (int i = 0; i < n; i++) {
        cin >> cells[i][0] >> cells[i][1] >> cells[i][2];
        cells[i][2]--;

        colors[cells[i][2]].insert(i);
    }

    vector<pair<int, int>> sorted_indices[3];

    for (int i = 0; i < 3; i++) {
        for (auto idx : colors[i]) {
            sorted_indices[i].push_back({cells[idx][0], cells[idx][1]});
        }

        sort(sorted_indices[i].begin(), sorted_indices[i].end());
    }

    ll res = 0;

    for (auto& idx : sorted_indices[0]) {
        auto it1 = lower_bound(sorted_indices[1].begin(), sorted_indices[1].end(), idx);
        auto it2 = lower_bound(sorted_indices[2].begin(), sorted_indices[2].end(), idx);

        if (it1 == sorted_indices[1].end() || it2 == sorted_indices[2].end())
            continue;

        res++;
    }

    cout << res * 3 << endl;

    return 0;
}