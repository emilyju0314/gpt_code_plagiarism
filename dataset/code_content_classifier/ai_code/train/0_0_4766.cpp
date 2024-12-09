#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> segments(n);
    for (int i = 0; i < n; i++) {
        cin >> segments[i].first >> segments[i].second;
    }

    int max_intersection = 0;
    for (int i = 0; i < n; i++) {
        vector<pair<int, int>> remaining_segments;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                remaining_segments.push_back(segments[j]);
            }
        }

        int leftmost = remaining_segments[0].second;
        int rightmost = remaining_segments[0].first;
        for (int j = 0; j < remaining_segments.size(); j++) {
            leftmost = min(leftmost, remaining_segments[j].second);
            rightmost = max(rightmost, remaining_segments[j].first);
        }

        max_intersection = max(max_intersection, rightmost - leftmost);
    }

    cout << max_intersection << endl;

    return 0;
}