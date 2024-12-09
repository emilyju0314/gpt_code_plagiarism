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

        for (int j = 0; j < n; j++) {
            int a, b;
            cin >> a >> b;
            dishes[j] = make_pair(a, b);
        }

        sort(dishes.begin(), dishes.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return abs(x.first - x.second) > abs(y.first - y.second);
        });

        int balance = 0;

        for (int j = 0; j < n; j++) {
            balance += abs(dishes[j].first - dishes[j].second);
        }

        cout << balance << endl;

        for (int j = 0; j < n; j++) {
            int x = min(dishes[j].first, m);
            int y = m - x;
            cout << x << " " << y << endl;
        }
    }

    return 0;
}