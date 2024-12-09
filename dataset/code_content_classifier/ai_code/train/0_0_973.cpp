#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, h, m, k;
    cin >> n >> h >> m >> k;

    vector<pair<int, int>> trains(n);
    for (int i = 0; i < n; i++) {
        cin >> trains[i].first >> trains[i].second;
    }

    int min_canceled = n;
    int best_t = 0;

    for (int t = 0; t < k; t++) {
        int canceled = 0;
        vector<int> taken(2*h, 0);

        for (auto train : trains) {
            int time = train.first * 60 + train.second;
            int tram_time = (time + (m/2) - t) % (m * h);

            if (tram_time < k || tram_time >= (m - k)) {
                canceled++;
            } else {
                for (int i = tram_time - k; i <= tram_time; i++) {
                    taken[i % (m * h)]++;
                }
            }
        }

        for (int i = 0; i < 2*h; i++) {
            canceled = max(canceled, taken[i]);
        }

        if (canceled < min_canceled) {
            min_canceled = canceled;
            best_t = t;
        }
    }

    cout << min_canceled << " " << best_t << endl;
    for (int i = 0; i < n; i++) {
        int time = (trains[i].first * 60 + trains[i].second + (m/2) - best_t) % (m * h);
        if (time >= k && time < (m - k)) {
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}