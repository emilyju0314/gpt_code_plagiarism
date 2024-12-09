#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    int totalLength = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            totalLength += segments[i].second - segments[i].first;
        } else {
            int intersectionLength = min(segments[i].second, segments[i-1].second) - max(segments[i].first, segments[i-1].first);
            totalLength += segments[i].second - segments[i].first - max(0, intersectionLength);
        }
    }

    cout << totalLength << endl;

    return 0;
}