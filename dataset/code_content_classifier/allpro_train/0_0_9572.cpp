#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> notes;
    for (int i = 0; i < m; i++) {
        int di, hdi;
        cin >> di >> hdi;
        notes.push_back({di, hdi});
    }

    sort(notes.begin(), notes.end());

    int max_height = 0;

    for (int i = 0; i < m; i++) {
        int prev_day = (i == 0) ? 1 : notes[i - 1].first;
        int prev_height = (i == 0) ? 0 : notes[i - 1].second;

        int curr_day = notes[i].first;
        int curr_height = notes[i].second;

        int diff_days = curr_day - prev_day;
        int diff_height = abs(curr_height - prev_height);

        int remaining_days = n - curr_day;
        int remaining_height = max(curr_height, prev_height) + (remaining_days - diff_days) / 2;

        if (diff_height > remaining_height) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        max_height = max(max_height, max(curr_height, prev_height));

        if (i == m - 1) {
            max_height = max(max_height, remaining_height);
        }
    }

    cout << max_height << endl;

    return 0;
}