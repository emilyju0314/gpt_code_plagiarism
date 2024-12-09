#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> flamingos(m);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        flamingos[i] = make_pair(x, y);
    }

    unordered_map<double, int> slope_counts;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            double slope = (double)(flamingos[j].second - flamingos[i].second) / (flamingos[j].first - flamingos[i].first);
            slope_counts[slope]++;
        }
    }

    int max_flamingos = 0;
    for (auto& pair : slope_counts) {
        max_flamingos = max(max_flamingos, pair.second);
    }

    cout << max_flamingos << endl;

    return 0;
}