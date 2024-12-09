#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m, s, d;
    cin >> n >> m >> s >> d;

    vector<int> obstacles(n);
    for (int i = 0; i < n; i++) {
        cin >> obstacles[i];
    }

    sort(obstacles.begin(), obstacles.end());

    vector<string> steps;
    int current_pos = 0;

    for (int i = 0; i < n; i++) {
        if (current_pos + s >= obstacles[i]) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }

        int run = obstacles[i] - current_pos - 1;
        steps.push_back("RUN " + to_string(run));

        int jump = min(d, obstacles[i] - current_pos - run);
        steps.push_back("JUMP " + to_string(jump));

        current_pos = obstacles[i] + jump;
    }

    if (current_pos + s >= m) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    int remaining_run = m - current_pos - 1;
    steps.push_back("RUN " + to_string(remaining_run));

    for (string step : steps) {
        cout << step << endl;
    }

    return 0;
}