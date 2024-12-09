#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, h;
    cin >> n >> h;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    int max_distance = 0;
    for (int i = 0; i < n - 1; i++) {
        max_distance = max(max_distance, segments[i + 1].first - segments[i].second);
    }

    if (n == 1) {
        max_distance = max(max_distance, segments[0].second - segments[0].first);
        max_distance = max(max_distance, segments[0].first - 1);
        max_distance = max(max_distance, h - segments[0].second);
    } else {
        max_distance = max(max_distance, segments[0].first - 1);
        max_distance = max(max_distance, h - segments[n - 1].second);
    }

    cout << max_distance << endl;

    return 0;
}