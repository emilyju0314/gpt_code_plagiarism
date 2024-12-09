#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> coupons;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        coupons.push_back(make_pair(l, r));
    }

    sort(coupons.begin(), coupons.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.second < b.second;
    });

    int best = 0;
    int idx = 0;
    for (int i = 0; i <= n - k; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (coupons[i].second >= coupons[j].first) {
                count++;
            }
        }
        if (count > best) {
            best = count;
            idx = i;
        }
    }

    cout << best << endl;
    for (int i = 0; i < k; i++) {
        cout << idx + 1 + i << " ";
    }

    return 0;
}