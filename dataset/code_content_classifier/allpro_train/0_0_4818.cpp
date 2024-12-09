#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> tranche(n);
    for (int i = 0; i < n; i++) {
        cin >> tranche[i];
    }

    vector<int> renovationCost(m);
    for (int i = 0; i < m; i++) {
        cin >> renovationCost[i];
    }

    vector<int> demolishCost(m);
    for (int i = 0; i < m; i++) {
        cin >> demolishCost[i];
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int moneyLeft = tranche[i];
        vector<pair<int, int>> buildings;
        for (int j = 0; j < m; j++) {
            if (renovationCost[j] <= moneyLeft) {
                buildings.push_back(make_pair(demolishCost[j], renovationCost[j]));
            }
        }
        sort(buildings.begin(), buildings.end());

        for (int j = 0; j < buildings.size(); j++) {
            if (buildings[j].first <= moneyLeft) {
                moneyLeft -= buildings[j].first;
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}