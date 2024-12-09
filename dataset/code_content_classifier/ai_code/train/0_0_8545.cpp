#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, w;
    cin >> n >> w;

    vector<pair<int, int>> planes(n);

    for (int i = 0; i < n; i++) {
        int x, v;
        cin >> x >> v;
        planes[i] = make_pair(x, v);
    }

    sort(planes.begin(), planes.end());

    long long count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int delta_x = planes[j].first - planes[i].first;
            int delta_v = planes[j].second - planes[i].second;

            if (delta_x * delta_v < 0) {
                double t = (double)delta_x / delta_v;
                double min_wind = min((double)w, abs(t));
                double max_wind = max((double)-w, -abs(t));

                if (max_wind >= min_wind) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}