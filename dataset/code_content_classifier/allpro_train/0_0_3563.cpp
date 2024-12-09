#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        long long s;
        cin >> n >> s;

        vector<pair<int, int>> salaries(n);
        for(int i = 0; i < n; i++) {
            cin >> salaries[i].first >> salaries[i].second;
        }

        long long left = 0, right = s, ans = 0;
        while(left <= right) {
            long long mid = (left + right) / 2;
            vector<long long> costs;

            for(int i = 0; i < n; i++) {
                long long cost = max((long long)salaries[i].first, mid);
                costs.push_back(cost);
            }

            sort(costs.begin(), costs.end());
            bool possible = true;

            long long total_cost = 0;
            for(int i = 0; i < (n+1)/2; i++) {
                total_cost += costs[i];
            }

            if(total_cost <= s) {
                ans = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        cout << ans << endl;
    }

    return 0;
}