#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, pair<int, int>>> stations;

    for (int i = 0; i < n; i++) {
        int x, r, f;
        cin >> x >> r >> f;
        stations.push_back({f, {x, r}});
    }

    sort(stations.begin(), stations.end());

    long long badPairs = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (stations[j].first - stations[i].first <= k) {
                int distance = abs(stations[j].second.first - stations[i].second.first);
                int minRange = min(stations[i].second.second, stations[j].second.second);
                if (minRange >= distance) {
                    badPairs++;
                }
            } else {
                break;
            }
        }
    }

    cout << badPairs << endl;

    return 0;
}