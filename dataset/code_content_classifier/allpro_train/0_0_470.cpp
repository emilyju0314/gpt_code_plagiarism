#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    vector<vector<int>> cost(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> cost[i][j];
        }
    }

    int min_sum = 0;
    for (int i = 0; i < m; i++) {
        vector<int> counts(26, 0);
        for (int j = 0; j < n; j++) {
            counts[strings[j][i] - 'a']++;
        }

        int max_count = *max_element(counts.begin(), counts.end());
        int total_cost = 0;
        for (int k = 0; k < 26; k++) {
            if (counts[k] == max_count) continue;
            int min_cost = INT_MAX;
            for (int j = 0; j < n; j++) {
                min_cost = min(min_cost, cost[j][i]);
            }
            total_cost += min_cost * (max_count - counts[k]);
        }
        min_sum += total_cost;
    }

    cout << min_sum << endl;

    return 0;
}