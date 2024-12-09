#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> videos(n);
    for (int i = 0; i < n; i++) {
        cin >> videos[i].first >> videos[i].second;
    }

    vector<pair<int, int, int>> channels(m);
    for (int i = 0; i < m; i++) {
        cin >> channels[i].first >> channels[i].second >> channels[i].third;
    }

    int max_efficiency = 0;
    int best_video = 0, best_channel = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x = max(videos[i].first, channels[j].first);
            int y = min(videos[i].second, channels[j].second);
            if (x <= y) {
                int efficiency = (y - x) * channels[j].third;
                if (efficiency > max_efficiency) {
                    max_efficiency = efficiency;
                    best_video = i + 1;
                    best_channel = j + 1;
                }
            }
        }
    }

    cout << max_efficiency << endl;
    if (max_efficiency > 0) {
        cout << best_video << " " << best_channel << endl;
    }

    return 0;
}