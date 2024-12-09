#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> alarms(n);
    for (int i = 0; i < n; i++) {
        cin >> alarms[i];
    }

    sort(alarms.begin(), alarms.end());

    int num_turned_off = 0;
    int interval_count = 0;
    int prev_alarm = 0;

    for (int i = 0; i < n; i++) {
        if (alarms[i] - prev_alarm <= m) {
            interval_count++;
        } else {
            interval_count = 1;
        }

        if (interval_count >= k) {
            num_turned_off++;
            interval_count = 0;
        }

        prev_alarm = alarms[i];
    }

    cout << num_turned_off << endl;

    return 0;
}