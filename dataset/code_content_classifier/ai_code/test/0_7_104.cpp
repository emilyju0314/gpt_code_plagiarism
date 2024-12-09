#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> dishes(n);
        vector<int> balance(n);

        int total_fish = 0, total_meat = 0;
        for (int j = 0; j < n; j++) {
              cin >> dishes[j].first >> dishes[j].second;
              total_fish += dishes[j].first;
              total_meat += dishes[j].second;
              balance[j] = dishes[j].first - dishes[j].second;
        }

        int min_balance = abs(total_fish - total_meat);

        cout << min_balance << "\n";

        for (int j = 0; j < n; j++) {
            int x = min(dishes[j].first, m);
            int y = m - x;

            cout << x << " " << y << "\n";
        }
    }

    return 0;
}