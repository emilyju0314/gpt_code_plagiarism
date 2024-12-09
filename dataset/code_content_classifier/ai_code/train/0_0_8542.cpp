#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> parts(n);
    for (int i = 0; i < n; i++) {
        cin >> parts[i].first >> parts[i].second;
    }

    int prevRoadWidth = parts[0].first;
    int totalWidthRemoved = 0;
    vector<int> newRoadWidths(n);

    for (int i = 0; i < n; i++) {
        int minRoadWidth = max(prevRoadWidth - parts[i].second, parts[i].first);
        int maxRoadWidth = parts[i].first + parts[i].second;

        if (minRoadWidth > parts[i].first || maxRoadWidth < parts[i].first) {
            cout << -1 << endl;
            return 0;
        }

        newRoadWidths[i] = parts[i].first;
        totalWidthRemoved += parts[i].second - (parts[i].first - minRoadWidth);
        prevRoadWidth = parts[i].first;
    }

    cout << totalWidthRemoved << endl;
    for (int width : newRoadWidths) {
        cout << width << " ";
    }

    return 0;
}