#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Generator {
    int a, b, c;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<Generator> generators(n);
    vector<pair<int, int>> ranges(n);

    for (int i = 0; i < n; ++i) {
        cin >> generators[i].a >> generators[i].b >> generators[i].c;
    }

    for (int i = 0; i < n; ++i) {
        cin >> ranges[i].first >> ranges[i].second;
    }

    vector<vector<int>> restrictions(m, vector<int>(3));

    for (int i = 0; i < m; ++i) {
        cin >> restrictions[i][0] >> restrictions[i][1] >> restrictions[i][2];
    }

    int max_output = 0;

    do {
        vector<int> levels(n, 0);
        for (const auto& res : restrictions) {
            levels[res[1] - 1] = max(levels[res[1] - 1], levels[res[0] - 1] + res[2]);
        }

        int total_output = 0;
        for (int i = 0; i < n; ++i) {
            levels[i] = max(ranges[i].first, min(ranges[i].second, levels[i]));
            total_output += generators[i].a * levels[i] * levels[i] + generators[i].b * levels[i] + generators[i].c;
        }

        max_output = max(max_output, total_output);
    } while (next_permutation(restrictions.begin(), restrictions.end()));

    cout << max_output << endl;

    return 0;
}