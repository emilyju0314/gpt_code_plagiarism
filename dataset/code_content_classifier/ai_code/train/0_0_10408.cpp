#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<pair<int, int>> weapons(n);
    vector<pair<int, int>> armors(m);
    vector<vector<int>> monsters(p, vector<int>(3));

    for (int i = 0; i < n; i++) {
        cin >> weapons[i].first >> weapons[i].second;
    }

    for (int i = 0; i < m; i++) {
        cin >> armors[i].first >> armors[i].second;
    }

    for (int i = 0; i < p; i++) {
        cin >> monsters[i][0] >> monsters[i][1] >> monsters[i][2];
    }

    sort(weapons.begin(), weapons.end());
    sort(armors.begin(), armors.end());

    int maxProfit = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j < m && armors[j].first <= weapons[i].first) {
            j++;
        }

        for (int k = 0; k < p; k++) {
            if (weapons[i].first > monsters[k][0] && armors[j-1].first > monsters[k][1]) {
                maxProfit = max(maxProfit, monsters[k][2] - weapons[i].second - armors[j-1].second);
            }
        }
    }

    cout << maxProfit << endl;

    return 0;
}