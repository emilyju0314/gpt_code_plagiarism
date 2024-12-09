#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> costs(n);
    for(int i = 0; i < n; i++) {
        cin >> costs[i];
    }

    vector<pair<int, int>> offers(m);
    for(int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        offers[i] = make_pair(x, y);
    }

    vector<int> sorted_costs = costs;
    sort(sorted_costs.begin(), sorted_costs.end());

    int ans = INT_MAX;
    for(int num_taken = 0; num_taken <= k; num_taken++) {
        if(num_taken > n) continue;

        int remaining = k - num_taken;
        if(remaining == 0) {
            ans = min(ans, accumulate(sorted_costs.begin(), sorted_costs.begin() + num_taken, 0));
            continue;
        }

        for(int i = 0; i < m; i++) {
            if(offers[i].first <= num_taken) {
                ans = min(ans, accumulate(sorted_costs.begin(), sorted_costs.begin() + num_taken, 0) - accumulate(sorted_costs.begin(), sorted_costs.begin() + offers[i].second, 0) + accumulate(sorted_costs.begin() + num_taken, sorted_costs.begin() + num_taken + remaining, 0));
            }
        }
    }

    cout << ans << endl;

    return 0;
}