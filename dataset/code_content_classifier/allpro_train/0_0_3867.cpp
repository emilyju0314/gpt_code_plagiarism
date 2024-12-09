#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> tvSets(n);
    vector<int> startTimes(n), endTimes(n);

    for (int i = 0; i < n; i++) {
        cin >> tvSets[i].first >> tvSets[i].second;
        startTimes[i] = tvSets[i].first;
        endTimes[i] = tvSets[i].second;
    }

    sort(startTimes.begin(), startTimes.end());
    sort(endTimes.begin(), endTimes.end());

    int redundantIndex = -1;
    for (int i = 0; i < n; i++) {
        if (tvSets[i].first <= startTimes[n-1] && tvSets[i].second >= endTimes[0]) {
            redundantIndex = i + 1;
            break;
        }
    }

    cout << redundantIndex << endl;

    return 0;
}