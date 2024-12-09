#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> dishes(n);
    for(int i = 0; i < n; i++) {
        cin >> dishes[i];
    }

    vector<int> pupils(m);
    for(int i = 0; i < m; i++) {
        cin >> pupils[i];
    }

    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);
    for(int i = 0; i < q; i++) {
        int type, idx, x;
        cin >> type >> idx >> x;
        queries[i] = {type, idx - 1}; // Indexes start from 0
        if(type == 1) {
            dishes[idx - 1] = x;
        } else {
            pupils[idx - 1] = x;
        }

        // Calculate the answer for this query
        int ans = -1;
        int maxPrice = *max_element(dishes.begin(), dishes.end());
        auto it = upper_bound(dishes.begin(), dishes.end(), pupils[m - 1]);
        if(it != dishes.end()) {
            ans = *it;
        }
        cout << ans << endl;
    }

    return 0;
}