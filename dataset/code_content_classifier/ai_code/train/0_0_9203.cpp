#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, x0;
    cin >> n >> x0;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    int min_distance = -1;
    for (int i = 0; i < n; i++) {
        int max_point = max(segments[i].first, segments[i].second);
        int min_point = min(segments[i].first, segments[i].second);

        if ((x0 >= min_point && x0 <= max_point) || (x0 >= max_point && x0 <= min_point)) {
            min_distance = 0; // Bob already at a position to take pictures
            break;
        } else {
            int distance_to_segment = min(abs(x0 - min_point), abs(x0 - max_point));
            if (min_distance == -1 || distance_to_segment < min_distance) {
                min_distance = distance_to_segment;
            }
        }
    }

    cout << min_distance << endl;

    return 0;
}