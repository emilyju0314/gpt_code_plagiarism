#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> heads(n);
    for (int i = 0; i < n; i++) {
        cin >> heads[i];
    }

    vector<int> tracks(m);
    for (int i = 0; i < m; i++) {
        cin >> tracks[i];
    }

    int min_time = 0;
    for (int i = 0; i < m; i++) {
        int closest_head = 0;
        int min_distance = abs(tracks[i] - heads[0]);

        for (int j = 1; j < n; j++) {
            int distance = abs(tracks[i] - heads[j]);
            if (distance < min_distance) {
                closest_head = j;
                min_distance = distance;
            }
        }

        min_time = max(min_time, min_distance);
    }

    cout << min_time << endl;

    return 0;
}