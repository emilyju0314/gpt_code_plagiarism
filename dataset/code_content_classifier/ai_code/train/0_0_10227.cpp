#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, P1, P2, P3, T1, T2;
    cin >> n >> P1 >> P2 >> P3 >> T1 >> T2;

    vector<pair<int, int>> work_intervals(n);
    for (int i = 0; i < n; i++) {
        cin >> work_intervals[i].first >> work_intervals[i].second;
    }

    int total_power_consumed = 0;
    int current_power = P1;

    for (int i = 0; i < n; i++) {
        total_power_consumed += (work_intervals[i].second - work_intervals[i].first) * current_power;
        if (i < n - 1) {
            int idle_time = work_intervals[i + 1].first - work_intervals[i].second;
            total_power_consumed += min(idle_time, T1) * current_power;
            idle_time -= T1;
            if (idle_time > 0) {
                current_power = P2;
                total_power_consumed += min(idle_time, T2) * current_power;
                idle_time -= T2;
                if (idle_time > 0) {
                    current_power = P3;
                    total_power_consumed += idle_time * current_power;
                }
            }
            current_power = P1;
        }
    }

    cout << total_power_consumed << endl;

    return 0;
}