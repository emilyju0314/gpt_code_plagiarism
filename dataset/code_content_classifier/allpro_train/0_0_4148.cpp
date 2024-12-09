#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int m;
    cin >> m;

    vector<pair<int, int>> points(m);
    map<int, int> slope_freq;

    for (int i = 0; i < m; i++) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < m; i++) {
        // Calculate the slope of each pair of points
        for (int j = i + 1; j < m; j++) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;

            if (dx == 0) {
                slope_freq[INT_MAX]++;
            } else {
                slope_freq[(dy * 1000000) / dx]++;
            }
        }
    }

    int max_parallel_lines = 0;
    for (auto& it: slope_freq) {
        max_parallel_lines = max(max_parallel_lines, it.second);
    }

    cout << max_parallel_lines << endl;

    return 0;
}