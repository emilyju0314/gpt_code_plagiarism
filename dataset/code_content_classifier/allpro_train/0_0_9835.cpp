#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> beacons(n);
    for (int i = 0; i < n; i++) {
        cin >> beacons[i].first >> beacons[i].second;
    }

    vector<int> destroyed(n+1, 0);
    int result = 0;
    for (int i = n-1; i >= 0; i--) {
        int left = max(0, beacons[i].first - beacons[i].second);
        int right = beacons[i].first + beacons[i].second;
        destroyed[i] = destroyed[i+1] + 1 - (lower_bound(beacons.begin(), beacons.end(), make_pair(left, 0)) - beacons.begin()) 
                        + destroyed[upper_bound(beacons.begin(), beacons.end(), make_pair(right, 0)) - beacons.begin()];
        result = max(result, destroyed[i]);
    }

    cout << result << endl;

    return 0;
}