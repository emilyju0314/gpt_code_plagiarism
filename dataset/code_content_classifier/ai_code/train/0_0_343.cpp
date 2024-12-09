#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m;
    cin >> n >> k >> m;

    vector<vector<pair<int, int>>> plans(n+1);
    for (int i = 0; i < m; i++) {
        int l, r, c, p;
        cin >> l >> r >> c >> p;
        plans[l].push_back({c, p});
        plans[r+1].push_back({-c, p});
    }

    long long totalCost = 0;
    multiset<pair<int, int>> availableCores; // {cost, cores}
    for (int i = 1; i <= n; i++) {
        for (auto& plan : plans[i]) {
            if (plan.first > 0) {
                availableCores.insert(plan);
            } else {
                availableCores.erase(availableCores.find({-plan.first, plan.second}));
            }
        }

        int neededCores = k;
        while (neededCores > 0) {
            if (availableCores.empty()) {
                totalCost += neededCores;
                neededCores = 0;
            } else {
                auto cheapest = *availableCores.begin();
                int cores = min(neededCores, cheapest.first);
                totalCost += cores * cheapest.second;
                neededCores -= cores;
                availableCores.erase(availableCores.begin());
                if (cores < cheapest.first) {
                    availableCores.insert({cheapest.first - cores, cheapest.second});
                }
            }
        }
    }

    cout << totalCost << endl;

    return 0;
}