#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> last_index(n+1, -1);
    map<int, int> first_index;

    vector<int> dp(n+1, 0);

    for (int i = 0; i < n; i++) {
        last_index[a[i]] = i;
        if (first_index.find(a[i]) == first_index.end()) {
            first_index[a[i]] = i;
        }
    }

    for (int i = 0; i < k; i++) {
        for (int j = n-1; j >= 0; j--) {
            dp[j] = dp[j+1];
            int curr_cost = last_index[a[j]] - first_index[a[j]];

            for (int l = j; l < last_index[a[j]]; l++) {
                curr_cost = min(curr_cost, last_index[a[l]] - first_index[a[l]]);
            }

            dp[j] = max(dp[j], curr_cost + dp[last_index[a[j]]+1]);
        }
    }

    cout << dp[0] << endl;

    return 0;
}