#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        vector<vector<int>> adj_list(n);
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            adj_list[u-1].push_back(v-1);
        }

        long long result = 0;
        for (int i = 0; i < n; i++) {
            vector<long long> neighbors;
            for (int neighbor_idx : adj_list[i]) {
                neighbors.push_back(nums[neighbor_idx]);
            }
            long long sum = accumulate(neighbors.begin(), neighbors.end(), 0LL);
            if (result == 0) {
                result = sum;
            } else {
                result = gcd(result, sum);
            }
        }

        cout << result << endl;
    }

    return 0;
}