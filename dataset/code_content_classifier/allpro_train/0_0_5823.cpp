#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;

        vector<int> socks(n);
        for (int i = 0; i < n; i++) {
            cin >> socks[i];
        }

        vector<int> colorsFreq(n + 1, 0);
        for (int i = 0; i < n; i++) {
            colorsFreq[socks[i]]++;
        }

        long long minCost = 0;

        // Calculating the minimum cost to make n/2 matching pairs
        for (int i = 1; i <= n; i++) {
            int pairs = min(colorsFreq[i] / 2, (l + r) / 2);
            l -= pairs * 2;
            r -= pairs * 2;
            colorsFreq[i] -= pairs * 2;
            minCost += pairs;
        }

        // If l or r > 0, check if we can convert some unmatched socks to a matching pair
        if (l > 0 || r > 0) {
            int unmatched = l > r ? l : r;
            for (int i = 1; i <= n && unmatched > 0; i++) {
                if (colorsFreq[i] % 2 == 1) {
                    colorsFreq[i]--;
                    unmatched--;
                    minCost++;
                }
            }
            minCost += unmatched;
        }

        cout << minCost << endl;
    }

    return 0;
}