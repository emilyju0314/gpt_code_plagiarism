#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> towers(n);
    for (int i = 0; i < n; i++) {
        cin >> towers[i].first >> towers[i].second;
    }

    vector<pair<int, int, int>> quests(m);
    for (int i = 0; i < m; i++) {
        cin >> quests[i].first >> quests[i].second >> quests[i].third;
    }

    int maxQuests = 0;
    for (int mask = 0; mask < (1 << n); mask++) {
        map<pair<int, int>, int> dist;
        for (int i = 0; i < n; i++) {
            if ((mask & (1 << i)) != 0) {
                dist[towers[i]] = 0;
            }
        }

        int curQuests = 0;
        for (int i = 0; i < m; i++) {
            int minDist = INT_MAX;
            for (auto tower : dist) {
                minDist = min(minDist, abs(quests[i].first - tower.first.first) + abs(quests[i].second - tower.first.second));
            }

            if (minDist + quests[i].third <= dist.size()) {
                curQuests++;
            }
        }

        maxQuests = max(maxQuests, curQuests);
    }

    cout << maxQuests << endl;

    return 0;
}