#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> dishes(n);
        for(int i = 0; i < n; i++) {
            cin >> dishes[i].first >> dishes[i].second;
        }

        sort(dishes.begin(), dishes.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return abs(a.first - a.second) < abs(b.first - b.second);
        });

        int total_fish = 0, total_meat = 0;
        for(auto dish : dishes) {
            total_fish += dish.first;
            total_meat += dish.second;
        }

        int balance = abs(total_fish - total_meat);
        cout << balance << endl;

        for(auto dish : dishes) {
            cout << min(m, dish.first) << " " << min(max(0, m - dish.first), dish.second) << endl;
        }
    }

    return 0;
}