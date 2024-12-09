#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    vector<pair<int, int>> chess_periods;
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        chess_periods.push_back({l, r});
    }

    cin >> m;

    vector<pair<int, int>> programming_periods;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        programming_periods.push_back({l, r});
    }

    int max_distance = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int distance = max(0, min(chess_periods[i].second, programming_periods[j].second) - max(chess_periods[i].first, programming_periods[j].first));
            max_distance = max(max_distance, distance);
        }
    }

    cout << max_distance << endl;

    return 0;
}