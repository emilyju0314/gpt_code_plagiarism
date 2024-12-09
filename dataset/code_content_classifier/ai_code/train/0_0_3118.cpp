#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> voters(n);
    for (int i = 0; i < n; i++) {
        cin >> voters[i].first >> voters[i].second;
    }

    vector<int> costs(m+1, 1e9);
    costs[0] = 0;
    for (int i = 0; i < n; i++) {
        int party = voters[i].first;
        int cost = voters[i].second;
        for (int j = 0; j < m; j++) {
            if (j != party) {
                costs[j] = min(costs[j], cost);
            }
        }
    }

    int total_cost = 0;
    for (int i = 0; i < n; i++) {
        total_cost += costs[voters[i].first];
    }

    cout << total_cost << endl;

    return 0;
}