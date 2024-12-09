#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <limits.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    set<pair<int, int>> pairs;
    vector<pair<int, int>> order;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        
        if (t == 1) {
            int a, b;
            cin >> a >> b;
            pairs.insert({a, b});
            order.push_back({a, b});
        } else if (t == 2) {
            int i;
            cin >> i;
            i--;
            pairs.erase(order[i]);
        } else {
            int q;
            cin >> q;
            if (pairs.empty()) {
                cout << "EMPTY SET" << endl;
            } else {
                int ans = INT_MIN;
                for (auto p : pairs) {
                    ans = max(ans, p.first * q + p.second);
                }
                cout << ans << endl;
            }
        }
    }

    return 0;
}