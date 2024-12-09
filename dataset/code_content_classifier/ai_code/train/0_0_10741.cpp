#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }

    set<pair<int, int>> matchedPairs;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        matchedPairs.insert({u, v});
    }

    int minSum = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (matchedPairs.count({i+1, j+1}) || matchedPairs.count({j+1, i+1})) {
                for (int k = j+1; k < n; k++) {
                    if (matchedPairs.count({i+1, k+1}) && matchedPairs.count({j+1, k+1})) {
                        if (minSum == -1 || prices[i] + prices[j] + prices[k] < minSum) {
                            minSum = prices[i] + prices[j] + prices[k];
                        }
                    }
                }
            }
        }
    }

    cout << minSum << endl;

    return 0;
}