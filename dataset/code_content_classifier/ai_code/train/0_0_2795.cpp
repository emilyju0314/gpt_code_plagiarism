#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> dwarves(n);
    vector<pair<int, int>> stations(k);

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        dwarves[i] = {x, y};
    }

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        stations[i] = {x, y};
    }

    long long min_time = LLONG_MAX;

    for (int i = 0; i < k; i++) {
        long long total_time = 0;
        for (int j = 0; j < n; j++) {
            total_time += abs(dwarves[j].first - stations[i].first) + abs(dwarves[j].second - stations[i].second);
        }
        min_time = min(min_time, total_time);
    }

    cout << min_time << endl;

    return 0;
}