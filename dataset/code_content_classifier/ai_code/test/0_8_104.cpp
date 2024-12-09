#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> dishes(n);
        int fish_total = 0, meat_total = 0;

        for (int j = 0; j < n; j++) {
            cin >> dishes[j].first >> dishes[j].second;
            fish_total += dishes[j].first;
            meat_total += dishes[j].second;
        }

        int balance = abs(fish_total - meat_total);
        cout << balance << endl;

        for (int j = 0; j < n; j++) {
            int x = min(m, dishes[j].first);
            int y = m - x;
            cout << x << " " << y << endl;
        }
    }

    return 0;
}