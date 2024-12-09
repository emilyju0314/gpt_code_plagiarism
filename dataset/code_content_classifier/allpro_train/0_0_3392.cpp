#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, p;
    cin >> n >> m >> p;

    vector<pair<int, int>> weapons(n);
    vector<pair<int, int>> armors(m);
    vector<pair<int, int, int>> monsters(p);

    for (int i = 0; i < n; i++) {
        cin >> weapons[i].first >> weapons[i].second;
    }

    for (int i = 0; i < m; i++) {
        cin >> armors[i].first >> armors[i].second;
    }

    for (int i = 0; i < p; i++) {
        cin >> monsters[i].first >> monsters[i].second >> monsters[i].third;
    }

    int max_profit = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int total_cost = weapons[i].second + armors[j].second;
            int total_profit = 0;

            for (int k = 0; k < p; k++) {
                if (weapons[i].first > monsters[k].first && armors[j].first > monsters[k].second) {
                    total_profit += monsters[k].third;
                }
            }

            max_profit = max(max_profit, total_profit - total_cost);
        }
    }

    cout << max_profit << endl;

    return 0;
}