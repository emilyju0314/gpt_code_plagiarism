#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> repair_costs(n);
    for (int i = 0; i < n; i++) {
        cin >> repair_costs[i];
    }

    vector<pair<int, pair<int, int>>> races;
    for (int i = 0; i < m; i++) {
        int lb, ub, p;
        cin >> lb >> ub >> p;
        races.push_back({p, {lb, ub}});
    }

    sort(races.begin(), races.end(), greater<pair<int, pair<int, int>>>());

    vector<int> road_repairs(n + 1, 0);
    long long total_profit = 0;

    for (int i = 0; i < m; i++) {
        int lb = races[i].second.first;
        int ub = races[i].second.second;

        int min_repair_cost = INT_MAX;
        for (int j = lb; j <= ub; j++) {
            min_repair_cost = min(min_repair_cost, repair_costs[j - 1]);
        }

        if (min_repair_cost > road_repairs[lb - 1]) {
            for (int j = lb; j <= ub; j++) {
                road_repairs[j] = max(road_repairs[j], min_repair_cost);
            }
            total_profit += races[i].first;
        }
    }

    cout << total_profit << endl;

    return 0;
}