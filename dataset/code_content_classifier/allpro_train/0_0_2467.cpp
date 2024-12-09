#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> row(n);
    for (int i = 0; i < n; i++) {
        cin >> row[i];
    }

    int m;
    cin >> m;
    vector<pair<int, pair<int, int>>> requests;
    for (int i = 0; i < m; i++) {
        int type, x, y;
        cin >> type >> x >> y;
        requests.push_back({type, {x, y}});
    }

    vector<int> pref(n, -1);
    vector<int> cnt(n, 0);
    vector<int> res;

    for (auto& req : requests) {
        int type = req.first;
        int x = req.second.first;
        int y = req.second.second;
        
        if (type == 1) {
            row[y - 1] = x;
        } else {
            if (pref[y - 1] == -1) {
                res.push_back(row[y - 1]);
            } else {
                res.push_back(cnt[y - 1] - cnt[pref[y - 1]]);
            }
            pref[y - 1] = x - 1;
            cnt[y - 1]++;
        }
    }

    for (auto r : res) {
        cout << r << endl;
    }

    return 0;
}