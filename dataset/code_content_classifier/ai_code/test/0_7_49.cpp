#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

const int MAXN = 1000005;
int a[MAXN], parent[MAXN];
map<int, int> freq;
vector<int> path;

void dfs(int v) {
    path.push_back(a[v]);
    if (freq.find(a[v]) == freq.end()) {
        freq[a[v]] = 1;
    } else {
        freq[a[v]]++;
    }

    if (v == 1) {
        return;
    }

    dfs(parent[v]);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }

        for (int i = 2; i <= n; i++) {
            cin >> parent[i];
        }

        while (q--) {
            int v, l, k;
            cin >> v >> l >> k;

            freq.clear();
            path.clear();
            dfs(v);

            vector<pair<int, int>> nums(freq.begin(), freq.end());
            sort(nums.begin(), nums.end(), [](const auto& a, const auto& b) {
                if (a.second == b.second) {
                    return a.first < b.first;
                }
                return a.second < b.second;
            });

            vector<int> res;
            for (auto& p : nums) {
                if (p.second >= l) {
                    res.push_back(p.first);
                }
            }

            if (res.size() < k) {
                cout << "-1 ";
            } else {
                cout << res[k - 1] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}