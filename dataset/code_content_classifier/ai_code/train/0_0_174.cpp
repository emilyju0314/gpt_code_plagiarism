#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> min_times(n, 0);

    vector<int> start_station(m);
    vector<int> end_station(m);

    for (int i = 0; i < m; i++) {
        cin >> start_station[i] >> end_station[i];
        start_station[i]--;
        end_station[i]--;
    }

    sort(start_station.begin(), start_station.end());

    for (int i = 0; i < m; i++) {
        int distance = (end_station[i] - start_station[0] + n) % n;
        for (int j = 0; j < n; j++) {
            int curr_distance = (end_station[i] - j + n) % n;
            min_times[j] = max(min_times[j], max(distance, curr_distance) + i);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << min_times[i] << " ";
    }
    cout << endl;

    return 0;
}