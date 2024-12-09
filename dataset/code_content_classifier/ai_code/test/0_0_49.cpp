#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> getPath(int v, const vector<int>& a, const vector<vector<int>>& tree) {
    vector<int> path;
    while (v != 0) {
        path.push_back(a[v-1]);
        v = tree[v-1][0];
    }
    path.push_back(a[0]);
    return path;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<vector<int>> tree(n);
        for (int i = 1; i < n; i++) {
            int parent;
            cin >> parent;
            tree[parent-1].push_back(i+1);
        }

        while (q--) {
            int v, l, k;
            cin >> v >> l >> k;

            vector<int> path = getPath(v, a, tree);

            map<int, int> count;
            for (int i : path) {
                count[i]++;
            }

            map<int, int> filtered;
            for (auto it = count.begin(); it != count.end(); it++) {
                if (it->second >= l) {
                    filtered[it->first] = it->second;
                }
            }

            vector<pair<int, int>> sorted(filtered.begin(), filtered.end());
            sort(sorted.begin(), sorted.end(), [](pair<int, int>& a, pair<int, int>& b) {
                return a.second < b.second;
            });

            if (sorted.size() < k) {
                cout << "-1 ";
            } else {
                cout << sorted[k-1].first << " ";
            }
        }

        cout << endl;
    }

    return 0;
}