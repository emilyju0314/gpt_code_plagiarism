#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, W;
    cin >> N >> W;

    vector<int> treasures(N);
    for (int i = 0; i < N; i++) {
        cin >> treasures[i];
    }

    vector<pair<int, pair<int, int>>> roads;
    for (int i = 0; i < N - 1; i++) {
        int u, v, c;
        cin >> u >> v >> c;
        roads.push_back({c, {u, v}});
    }

    sort(roads.begin(), roads.end());

    int maxTreasure = 0;
    for (int i = 0; i < N; i++) {
        int currentTreasure = 0;
        int currentBudget = W;
        for (int j = 0; j < N - 1; j++) {
            if (roads[j].second.first == i + 1 || roads[j].second.second == i + 1) {
                if (roads[j].first <= currentBudget) {
                    currentBudget -= roads[j].first;
                    currentTreasure += treasures[roads[j].second.first - 1] + treasures[roads[j].second.second - 1];
                }
            }
        }
        maxTreasure = max(maxTreasure, currentTreasure);
    }

    cout << maxTreasure << endl;

    return 0;
}