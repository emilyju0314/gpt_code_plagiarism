#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<set<pair<int, int>>> segments(n + 1);

    for (int i = 0; i < k; i++) {
        int l, r, p;
        cin >> l >> r >> p;
        segments[p].insert({l, r});
    }

    for (int i = 0; i < m; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;

        bool found = false;
        for (int j = a; j <= b; j++) {
            auto it = segments[j].lower_bound({x, y});
            if (it != segments[j].end() && it->second <= y) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }

        cout.flush();
    }

    return 0;
}