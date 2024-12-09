#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int query = 0; query < t; query++) {
        int n, x;
        cin >> n >> x;

        vector<pair<int, int>> blows(n);
        for (int i = 0; i < n; i++) {
            int d, h;
            cin >> d >> h;
            blows[i] = make_pair(d, h);
        }

        sort(blows.begin(), blows.end(), greater<pair<int, int>>());
        
        int max_head_cut = blows[0].first;

        if (max_head_cut >= x) {
            cout << "1" << endl;
        } else if ((x - max_head_cut) <= 0) {
            cout << "-1" << endl;
        } else {
            long long remaining_heads = x - max_head_cut;
            long long grow_heads = blows[0].second - 1;
            long long res = (remaining_heads + grow_heads - 1) / grow_heads;

            cout << res + 1 << endl;
        }
    }

    return 0;
}