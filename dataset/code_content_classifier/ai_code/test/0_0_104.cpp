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
            cin >> dishes[j].first >> dishes[j].second;
        }

        sort(dishes.begin(), dishes.end(), 
             [](pair<int, int>& a, pair<int, int>& b) { 
                 return (a.first - a.second) < (b.first - b.second); 
             });

        int total_fish = 0;
        int total_meat = 0;
        for (int j = 0; j < n; j++) {
            total_fish += dishes[j].first;
            total_meat += dishes[j].second;
        }

        int balance = abs(total_fish - total_meat);
        cout << balance << endl;

        for (int j = 0; j < n; j++) {
            int eat_fish = min(m, dishes[j].first);
            int eat_meat = m - eat_fish;
            cout << eat_fish << " " << eat_meat << endl;
        }
    }

    return 0;
}