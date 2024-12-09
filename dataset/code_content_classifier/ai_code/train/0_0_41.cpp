#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, a, b, q;
    cin >> n >> k >> a >> b >> q;

    vector<pair<int,int>> updates(n+1, {0, 0}); // {day, orders}
    vector<int> pref_sum(n+1, 0);

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int di, ai;
            cin >> di >> ai;
            updates[di].first += ai;
        } else {
            int pi;
            cin >> pi;
            updates[pi].second++;
            updates[pi+k].second--;
        }
    }

    for (int i = 1; i <= n; i++) {
        pref_sum[i] = pref_sum[i-1] + updates[i].first;
    }

    for (int i = 1; i <= n; i++) {
        updates[i].second += updates[i-1].second;
    }

    int max_orders = 0;
    for (int i = 1; i <= n; i++) {
        if (i + k - 1 <= n) {
            int orders_filled = min(a, pref_sum[i]) - updates[i].second * b;
            max_orders = max(max_orders, orders_filled);
        }
    }

    cout << max_orders << endl;

    return 0;
}