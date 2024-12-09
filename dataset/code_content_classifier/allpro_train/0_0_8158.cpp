#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> events(n);
    for (int i = 0; i < n; i++) {
        cin >> events[i].first >> events[i].second;
    }

    sort(events.begin(), events.end());

    int cnt = 0;
    int max_end = events[0].second;

    for (int i = 1; i < n; i++) {
        if (events[i].second > max_end) {
            cnt++;
            max_end = events[i].second;
        }
    }

    cout << cnt << endl;

    return 0;
}